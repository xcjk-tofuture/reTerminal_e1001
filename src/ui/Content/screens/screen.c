#include "../../GUI.h"



void GUI_initScreen__screen () {
    GUI_Screen__screen = lv_obj_create( NULL );
    lv_obj_remove_flag( GUI_Screen__screen, LV_OBJ_FLAG_SCROLLABLE );
     GUI_Panel__screen__panel = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel, LV_ALIGN_CENTER );
     lv_obj_set_pos( GUI_Panel__screen__panel, -202, -120 );
     lv_obj_set_size( GUI_Panel__screen__panel, 400, 240 );

     GUI_Panel__screen__panel_1 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_1, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_1, LV_ALIGN_CENTER );
     lv_obj_set_pos( GUI_Panel__screen__panel_1, 208, -116 );
     lv_obj_set_size( GUI_Panel__screen__panel_1, 421, 254 );

     GUI_Panel__screen__panel_2 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_2, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_2, LV_ALIGN_CENTER );
     lv_obj_set_pos( GUI_Panel__screen__panel_2, 197, 120 );
     lv_obj_set_size( GUI_Panel__screen__panel_2, 400, 240 );

     GUI_Panel__screen__panel_3 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_3, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_3, LV_ALIGN_CENTER );
     lv_obj_set_pos( GUI_Panel__screen__panel_3, -202, 120 );
     lv_obj_set_size( GUI_Panel__screen__panel_3, 400, 240 );

     GUI_Label__screen__label = lv_label_create( GUI_Screen__screen );
     lv_obj_set_align( GUI_Label__screen__label, LV_ALIGN_BOTTOM_RIGHT );
     lv_obj_set_size( GUI_Label__screen__label, LV_SIZE_CONTENT, LV_SIZE_CONTENT );


    GUI_initScreenStyles__screen();
    GUI_initScreenTexts__screen();
}


void GUI_initScreenTexts__screen () {
     lv_label_set_text( GUI_Label__screen__label, "4L Test" );
}


void GUI_initScreenStyles__screen () {
     lv_obj_add_style( GUI_Panel__screen__panel, &GUI_Style__class_p58px5HsFqILGr__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_1, &GUI_Style__class_dZnQs4Qn2eDhQo__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_2, &GUI_Style__class_Jtij8jY2Dvc02m__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_3, &GUI_Style__class_umzFheTHCa6oGa__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Label__screen__label, &GUI_Style__class_feSRUvXmJNcOTw__, LV_PART_MAIN | LV_STATE_DEFAULT );

}


