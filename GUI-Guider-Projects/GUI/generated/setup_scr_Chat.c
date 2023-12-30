/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"


void setup_scr_Chat(lv_ui *ui)
{
	//Write codes Chat
	ui->Chat = lv_obj_create(NULL);
	lv_obj_set_size(ui->Chat, 320, 240);

	//Write style for Chat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_btn_1
	ui->Chat_btn_1 = lv_btn_create(ui->Chat);
	ui->Chat_btn_1_label = lv_label_create(ui->Chat_btn_1);
	lv_label_set_text(ui->Chat_btn_1_label, "Jerry");
	lv_label_set_long_mode(ui->Chat_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Chat_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Chat_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Chat_btn_1, 35, 17);
	lv_obj_set_size(ui->Chat_btn_1, 100, 50);

	//Write style for Chat_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Chat_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_btn_2
	ui->Chat_btn_2 = lv_btn_create(ui->Chat);
	ui->Chat_btn_2_label = lv_label_create(ui->Chat_btn_2);
	lv_label_set_text(ui->Chat_btn_2_label, "Tom");
	lv_label_set_long_mode(ui->Chat_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Chat_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Chat_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Chat_btn_2, 35, 88);
	lv_obj_set_size(ui->Chat_btn_2, 100, 50);

	//Write style for Chat_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Chat_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_btn_3
	ui->Chat_btn_3 = lv_btn_create(ui->Chat);
	ui->Chat_btn_3_label = lv_label_create(ui->Chat_btn_3);
	lv_label_set_text(ui->Chat_btn_3_label, "Group");
	lv_label_set_long_mode(ui->Chat_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Chat_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Chat_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Chat_btn_3, 35, 158);
	lv_obj_set_size(ui->Chat_btn_3, 100, 50);

	//Write style for Chat_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Chat_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_btn_4
	ui->Chat_btn_4 = lv_btn_create(ui->Chat);
	ui->Chat_btn_4_label = lv_label_create(ui->Chat_btn_4);
	lv_label_set_text(ui->Chat_btn_4_label, "back");
	lv_label_set_long_mode(ui->Chat_btn_4_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Chat_btn_4_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Chat_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Chat_btn_4, 235, 4);
	lv_obj_set_size(ui->Chat_btn_4, 69, 37);

	//Write style for Chat_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Chat_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_btn_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->Chat);

	
	//Init events for screen.
	events_init_Chat(ui);
}
