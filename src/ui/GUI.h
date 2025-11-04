#ifndef _GUI_HEADER_INCLUDED
#define _GUI_HEADER_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif
#include "ui_helpers.h"

extern lv_obj_t* GUI_Screen__screen;
extern lv_obj_t*  GUI_Panel__screen__panel;
extern lv_obj_t*  GUI_Panel__screen__panel_1;
extern lv_obj_t*  GUI_Panel__screen__panel_2;
extern lv_obj_t*  GUI_Panel__screen__panel_3;
extern lv_obj_t*  GUI_Panel__screen__panel_4;
extern lv_obj_t*  GUI_Panel__screen__panel_5;
extern lv_obj_t*  GUI_Panel__screen__panel_6;
extern lv_obj_t*  GUI_Panel__screen__panel_7;


// Screen-specific function declarations
void GUI_initScreen__screen ();
void GUI_initScreenTexts__screen ();
void GUI_initScreenStyles__screen ();

extern lv_style_t GUI_Style__class_HqRf7OBHYDfUJC__;
extern lv_style_t GUI_Style__class_p58px5HsFqILGr__;
extern lv_style_t GUI_Style__class_dZnQs4Qn2eDhQo__;
extern lv_style_t GUI_Style__class_Jtij8jY2Dvc02m__;
extern lv_style_t GUI_Style__class_umzFheTHCa6oGa__;
extern lv_style_t GUI_Style__class_gELAzghP12nfVq__;
extern lv_style_t GUI_Style__class_QiSrwtq8tXkA6v__;
extern lv_style_t GUI_Style__class_AZhwT96gVSdTys__;
extern lv_style_t GUI_Style__class_51ahHfbOis0YqI__;


void GUI_load ();

void GUI_init ();

void GUI_refresh ();


void GUI_initHAL ();
void HAL_init ();

void GUI_initFramework ();

void GUI_loadContent ();


void GUI_initContent ();


void GUI_initTheme ();


void GUI_initScreens ();


void GUI_loadFirstScreen ();


void GUI_initScreenContents ();

void GUI_initScreenTexts ();

void GUI_initScreenStyles ();


void GUI_initGlobalStyles ();


void GUI_initAnimations ();







#ifdef __cplusplus
} //extern "C"
#endif

#endif //_GUI_HEADER_INCLUDED

