/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Homepage;
	bool Homepage_del;
	lv_obj_t *Homepage_btn_1;
	lv_obj_t *Homepage_btn_1_label;
	lv_obj_t *Homepage_btn_2;
	lv_obj_t *Homepage_btn_2_label;
	lv_obj_t *Homepage_btn_3;
	lv_obj_t *Homepage_btn_3_label;
	lv_obj_t *Homepage_btn_4;
	lv_obj_t *Homepage_btn_4_label;
	lv_obj_t *Homepage_username_label;
	lv_obj_t *Homepage_digital_clock;
	lv_obj_t *Homepage_msgbox_1;
	lv_obj_t *Album;
	bool Album_del;
	lv_obj_t *Album_return_btn;
	lv_obj_t *Album_return_btn_label;
	lv_obj_t *Album_image;
	lv_obj_t *Album_file_list;
	lv_obj_t *Album_count_label;
	lv_obj_t *Chat;
	bool Chat_del;
	lv_obj_t *Chat_btn_1;
	lv_obj_t *Chat_btn_1_label;
	lv_obj_t *Chat_btn_2;
	lv_obj_t *Chat_btn_2_label;
	lv_obj_t *Chat_btn_3;
	lv_obj_t *Chat_btn_3_label;
	lv_obj_t *Chat_btn_4;
	lv_obj_t *Chat_btn_4_label;
	lv_obj_t *Chat_0;
	bool Chat_0_del;
	lv_obj_t *Chat_0_label_1;
	lv_obj_t *Chat_0_list_1;
	lv_obj_t *Chat_0_list_1_item0;
	lv_obj_t *Chat_0_btn_1;
	lv_obj_t *Chat_0_btn_1_label;
	lv_obj_t *Chat_1;
	bool Chat_1_del;
	lv_obj_t *Chat_1_label_1;
	lv_obj_t *Chat_1_list_1;
	lv_obj_t *Chat_1_list_1_item0;
	lv_obj_t *Chat_1_btn_1;
	lv_obj_t *Chat_1_btn_1_label;
	lv_obj_t *Group;
	bool Group_del;
	lv_obj_t *Group_label_1;
	lv_obj_t *Group_label_2;
	lv_obj_t *Group_label_3;
	lv_obj_t *Group_list_1;
	lv_obj_t *Group_list_1_item0;
	lv_obj_t *Group_btn_1;
	lv_obj_t *Group_btn_1_label;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;

void setup_scr_Homepage(lv_ui *ui);
void setup_scr_Album(lv_ui *ui);
void setup_scr_Chat(lv_ui *ui);
void setup_scr_Chat_0(lv_ui *ui);
void setup_scr_Chat_1(lv_ui *ui);
void setup_scr_Group(lv_ui *ui);
LV_IMG_DECLARE(__135x148);

LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)


#ifdef __cplusplus
}
#endif
#endif
