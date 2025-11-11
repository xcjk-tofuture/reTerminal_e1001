#include "e1001_display.h"

#include <lvgl.h>
#include <TFT_eSPI.h>

/*Set to your screen resolution and rotation*/
#define TFT_HOR_RES   800
#define TFT_VER_RES   480

/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE ((TFT_HOR_RES * TFT_VER_RES) * LV_COLOR_DEPTH / 8 / 10 + 8 )
static uint8_t draw_buf[DRAW_BUF_SIZE];

EPaper epaper;

#if LV_USE_LOG != 0
void arduino_print( lv_log_level_t level, const char * buf )
{
    LV_UNUSED(level);
    Serial.println(buf);
    Serial.flush();
}
#endif

/* LVGL calls it when a rendered image needs to copied to the display*/
static void e1001_disp_flush( lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    e1001_driver_t *drv = (e1001_driver_t *)lv_display_get_driver_data(disp);
    EPaper *epd = drv->epd;
    int32_t w = lv_area_get_width(area);
    int32_t h = lv_area_get_height(area);
    uint8_t pixels8_1;
    uint8_t pixels8_2;
    uint8_t pixels8_3;
    uint8_t pixels8_4;
    // LV_LOG_INFO("flushing: %d,%d - %dx%d", area->x1, area->y1, w, h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x +=4) {
            pixels8_1 = (px_map)[y * w + x];
            pixels8_2 = (px_map)[y * w + x + 1];
            pixels8_3 = (px_map)[y * w + x + 2];
            pixels8_4 = (px_map)[y * w + x + 3];
            uint8_t pixel2_1 = (pixels8_1 <= 63) ? 0b00 : (pixels8_1 <= 127) ? 0b01 : (pixels8_1 <= 191) ? 0b10 : 0b11;
            uint8_t pixel2_2 = (pixels8_2 <= 63) ? 0b00 : (pixels8_2 <= 127) ? 0b01 : (pixels8_2 <= 191) ? 0b10 : 0b11;
            uint8_t pixel2_3 = (pixels8_3 <= 63) ? 0b00 : (pixels8_3 <= 127) ? 0b01 : (pixels8_3 <= 191) ? 0b10 : 0b11;
            uint8_t pixel2_4 = (pixels8_4 <= 63) ? 0b00 : (pixels8_4 <= 127) ? 0b01 : (pixels8_4 <= 191) ? 0b10 : 0b11;
            uint8_t packedByte = (pixel2_1 << 6) | (pixel2_2 << 4) | (pixel2_3 << 2) | pixel2_4;

            epd->drawPixel(area->x1 + x , area->y1 + y, packedByte, 2);  //the last param is target_bpp

            
        }
        // Serial.println(";");
    }

    if (lv_display_flush_is_last(disp)) {
        drv->flush_scheduled = true;
        drv->flush_scheduled_time = millis();
    }

    /*Call it to tell LVGL you are ready*/
    lv_display_flush_ready(disp);
}

/*Read the touchpad*/
static void device_touchpad_read( lv_indev_t * indev, lv_indev_data_t * data )
{
}

/*use Arduinos millis() as tick source*/
static uint32_t get_arduino_tick(void)
{
    return millis();
}

static void resolution_changed_event_cb(lv_event_t * e)
{
    lv_display_t *disp = (lv_display_t *)lv_event_get_target(e);
    e1001_driver_t *drv =  (e1001_driver_t *)lv_display_get_driver_data(disp);
    EPaper *epd = drv->epd;
    int32_t hor_res = lv_display_get_horizontal_resolution(disp);
    int32_t ver_res = lv_display_get_vertical_resolution(disp);
    lv_display_rotation_t rot = lv_display_get_rotation(disp);

    /* handle rotation */
    switch(rot) {
        case LV_DISPLAY_ROTATION_0:
            epd->setRotation(0);   /* Portrait orientation */
            break;
        case LV_DISPLAY_ROTATION_90:
            epd->setRotation(1);   /* Landscape orientation */
            break;
        case LV_DISPLAY_ROTATION_180:
            epd->setRotation(2);   /* Portrait orientation, flipped */
            break;
        case LV_DISPLAY_ROTATION_270:
            epd->setRotation(3);   /* Landscape orientation, flipped */
            break;
    }
}

void e1001_display_init(e1001_driver_t *drv)
{
    drv->epd = &epaper;
    drv->flush_scheduled = false;
    drv->flush_scheduled_time = 0;

    drv->epd->begin();

    lv_init();

    /*Set a tick source so that LVGL will know how much time elapsed. */
    lv_tick_set_cb(get_arduino_tick);

    /* register print function for debugging */
#if LV_USE_LOG != 0
    lv_log_register_print_cb( arduino_print );
#endif

    lv_display_t *disp;

    /*Else create a display yourself*/
    disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    lv_display_set_driver_data(disp, (void *)drv);
    lv_display_set_flush_cb(disp, e1001_disp_flush);
    //lv_display_add_event_cb(disp, resolution_changed_event_cb, LV_EVENT_RESOLUTION_CHANGED, NULL);
    lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /*Initialize the (dummy) input device driver*/
    // lv_indev_t * indev = lv_indev_create();
    // lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER); /*Touchpad should have POINTER type*/
    // lv_indev_set_read_cb(indev, device_touchpad_read);

}

void e1001_display_refresh(e1001_driver_t *drv)
{
    drv->epd->updateGray();  //use gray update
    drv->flush_scheduled = false;
}

void e1001_display_schedule_refresh(e1001_driver_t *drv)
{
    drv->flush_scheduled = true;
    drv->flush_scheduled_time = millis();
}

bool e1001_display_should_refresh(e1001_driver_t *drv)
{
    return drv->flush_scheduled && (millis() - drv->flush_scheduled_time > 100);
}
