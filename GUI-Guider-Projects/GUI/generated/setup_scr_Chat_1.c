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


void setup_scr_Chat_1(lv_ui *ui)
{
	//Write codes Chat_1
	ui->Chat_1 = lv_obj_create(NULL);
	lv_obj_set_size(ui->Chat_1, 320, 240);

	//Write style for Chat_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_1_label_1
	ui->Chat_1_label_1 = lv_label_create(ui->Chat_1);
	lv_label_set_text(ui->Chat_1_label_1, "Tom");
	lv_label_set_long_mode(ui->Chat_1_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Chat_1_label_1, 0, 5);
	lv_obj_set_size(ui->Chat_1_label_1, 100, 32);

	//Write style for Chat_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_1_label_1, lv_color_hex(0x0000ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_1_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Chat_1_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_1_list_1
	ui->Chat_1_list_1 = lv_list_create(ui->Chat_1);
	ui->Chat_1_list_1_item0 =lv_list_add_text(ui->Chat_1_list_1, "save");
	lv_obj_set_pos(ui->Chat_1_list_1, 16, 53);
	lv_obj_set_size(ui->Chat_1_list_1, 288, 177);
	lv_obj_set_scrollbar_mode(ui->Chat_1_list_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for &style_Chat_1_list_1_main_main_default
	static lv_style_t style_Chat_1_list_1_main_main_default;
	ui_init_style(&style_Chat_1_list_1_main_main_default);
	
	lv_style_set_pad_top(&style_Chat_1_list_1_main_main_default, 5);
	lv_style_set_pad_left(&style_Chat_1_list_1_main_main_default, 5);
	lv_style_set_pad_right(&style_Chat_1_list_1_main_main_default, 5);
	lv_style_set_pad_bottom(&style_Chat_1_list_1_main_main_default, 5);
	lv_style_set_bg_opa(&style_Chat_1_list_1_main_main_default, 255);
	lv_style_set_bg_color(&style_Chat_1_list_1_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_border_width(&style_Chat_1_list_1_main_main_default, 1);
	lv_style_set_border_opa(&style_Chat_1_list_1_main_main_default, 255);
	lv_style_set_border_color(&style_Chat_1_list_1_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_border_side(&style_Chat_1_list_1_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_Chat_1_list_1_main_main_default, 3);
	lv_style_set_shadow_width(&style_Chat_1_list_1_main_main_default, 0);
	lv_obj_add_style(ui->Chat_1_list_1, &style_Chat_1_list_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Chat_1_list_1_main_scrollbar_default
	static lv_style_t style_Chat_1_list_1_main_scrollbar_default;
	ui_init_style(&style_Chat_1_list_1_main_scrollbar_default);
	
	lv_style_set_radius(&style_Chat_1_list_1_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_Chat_1_list_1_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_Chat_1_list_1_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_obj_add_style(ui->Chat_1_list_1, &style_Chat_1_list_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Chat_1_list_1_extra_btns_main_default
	static lv_style_t style_Chat_1_list_1_extra_btns_main_default;
	ui_init_style(&style_Chat_1_list_1_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_Chat_1_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_Chat_1_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_Chat_1_list_1_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_Chat_1_list_1_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_Chat_1_list_1_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_Chat_1_list_1_extra_btns_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_Chat_1_list_1_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_radius(&style_Chat_1_list_1_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_Chat_1_list_1_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_Chat_1_list_1_extra_btns_main_default, lv_color_hex(0xffffff));

	//Write style state: LV_STATE_DEFAULT for &style_Chat_1_list_1_extra_texts_main_default
	static lv_style_t style_Chat_1_list_1_extra_texts_main_default;
	ui_init_style(&style_Chat_1_list_1_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_Chat_1_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_Chat_1_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_Chat_1_list_1_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_Chat_1_list_1_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_Chat_1_list_1_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_Chat_1_list_1_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_Chat_1_list_1_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_radius(&style_Chat_1_list_1_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_Chat_1_list_1_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_Chat_1_list_1_extra_texts_main_default, lv_color_hex(0xffffff));
	lv_obj_add_style(ui->Chat_1_list_1_item0, &style_Chat_1_list_1_extra_texts_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Chat_1_btn_1
	ui->Chat_1_btn_1 = lv_btn_create(ui->Chat_1);
	ui->Chat_1_btn_1_label = lv_label_create(ui->Chat_1_btn_1);
	lv_label_set_text(ui->Chat_1_btn_1_label, "back");
	lv_label_set_long_mode(ui->Chat_1_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Chat_1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Chat_1_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Chat_1_btn_1, 235, 4);
	lv_obj_set_size(ui->Chat_1_btn_1, 69, 37);

	//Write style for Chat_1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Chat_1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Chat_1_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Chat_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Chat_1_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Chat_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Chat_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Chat_1_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Chat_1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->Chat_1);

	
	//Init events for screen.
	events_init_Chat_1(ui);
}
