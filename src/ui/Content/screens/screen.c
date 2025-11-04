#include "../../GUI.h"



void GUI_initScreen__screen () {
    GUI_Screen__screen = lv_obj_create( NULL );
    lv_obj_remove_flag( GUI_Screen__screen, LV_OBJ_FLAG_SCROLLABLE );
     GUI_Panel__screen__panel = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel, 200, 200 );

     GUI_Panel__screen__panel_1 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_1, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_1, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_1, 200, 200 );

     GUI_Panel__screen__panel_2 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_2, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_2, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_2, 200, 200 );

     GUI_Panel__screen__panel_3 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_3, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_3, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_3, 200, 200 );

     GUI_Panel__screen__panel_4 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_4, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_4, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_4, 200, 200 );

     GUI_Panel__screen__panel_5 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_5, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_5, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_5, 200, 200 );

     GUI_Panel__screen__panel_6 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_6, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_6, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_6, 200, 200 );

     GUI_Panel__screen__panel_7 = lv_obj_create( GUI_Screen__screen );
     lv_obj_remove_flag( GUI_Panel__screen__panel_7, LV_OBJ_FLAG_SCROLLABLE );
     lv_obj_set_align( GUI_Panel__screen__panel_7, LV_ALIGN_CENTER );
     lv_obj_set_size( GUI_Panel__screen__panel_7, 200, 200 );


    GUI_initScreenStyles__screen();
    GUI_initScreenTexts__screen();
}


void GUI_initScreenTexts__screen () {
}


void GUI_initScreenStyles__screen () {
    lv_obj_add_style( GUI_Screen__screen, &GUI_Style__class_HqRf7OBHYDfUJC__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel, &GUI_Style__class_p58px5HsFqILGr__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_1, &GUI_Style__class_dZnQs4Qn2eDhQo__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_2, &GUI_Style__class_Jtij8jY2Dvc02m__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_3, &GUI_Style__class_umzFheTHCa6oGa__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_4, &GUI_Style__class_gELAzghP12nfVq__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_5, &GUI_Style__class_QiSrwtq8tXkA6v__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_6, &GUI_Style__class_AZhwT96gVSdTys__, LV_PART_MAIN | LV_STATE_DEFAULT );

     lv_obj_add_style( GUI_Panel__screen__panel_7, &GUI_Style__class_51ahHfbOis0YqI__, LV_PART_MAIN | LV_STATE_DEFAULT );

}


