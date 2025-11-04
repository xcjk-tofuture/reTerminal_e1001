
/*
 * Seeed reTerminal E1002 Display Demo
 * Designed for slow-refresh 6-color e-paper display
 */

#include <TFT_eSPI.h>
#include <lvgl.h>

#include "e1001_display.h"
#include "ui/GUI.h"

e1001_driver_t e1001_driver;

void setup()
{
    String LVGL_Arduino = "Automotive Dashboard Demo - LVGL ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() +
                    "." + lv_version_patch();

    Serial.begin(115200);
    Serial.println(LVGL_Arduino);
    Serial.println("Initializing 6-color e-paper display...");

    e1001_display_init(&e1001_driver);

    Serial.println("Creating dashboard UI...");
    // Create dashboard UI
    GUI_init();

    Serial.println("Setting initial display values...");
    
    Serial.println("Dashboard initialization complete!");
    Serial.println("Display content updated with all parameters");
}

void loop()
{
    lv_timer_handler(); // Drive LVGL internal timers
    delay(50);          // Reduce CPU usage since frequent updates aren't needed

    // Check if display refresh is needed
    if (e1001_display_should_refresh(&e1001_driver))
    {
        Serial.println("Refreshing e-paper display...");
        e1001_display_refresh(&e1001_driver);
        Serial.println("Display refresh complete");
    }
}