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



int Homepage_digital_clock_min_value = 25;
int Homepage_digital_clock_hour_value = 11;
int Homepage_digital_clock_sec_value = 50;void setup_scr_Homepage(lv_ui *ui)
{
	//Write codes Homepage
	ui->Homepage = lv_obj_create(NULL);
	lv_obj_set_size(ui->Homepage, 320, 240);

	//Write style for Homepage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_btn_1
	ui->Homepage_btn_1 = lv_btn_create(ui->Homepage);
	ui->Homepage_btn_1_label = lv_label_create(ui->Homepage_btn_1);
	lv_label_set_text(ui->Homepage_btn_1_label, "Album");
	lv_label_set_long_mode(ui->Homepage_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Homepage_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Homepage_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Homepage_btn_1, 25, 21);
	lv_obj_set_size(ui->Homepage_btn_1, 80, 80);

	//Write style for Homepage_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Homepage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_btn_1, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_btn_2
	ui->Homepage_btn_2 = lv_btn_create(ui->Homepage);
	ui->Homepage_btn_2_label = lv_label_create(ui->Homepage_btn_2);
	lv_label_set_text(ui->Homepage_btn_2_label, "Calculator");
	lv_label_set_long_mode(ui->Homepage_btn_2_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Homepage_btn_2_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Homepage_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Homepage_btn_2, 120, 21);
	lv_obj_set_size(ui->Homepage_btn_2, 80, 80);

	//Write style for Homepage_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage_btn_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Homepage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_btn_2, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_btn_3
	ui->Homepage_btn_3 = lv_btn_create(ui->Homepage);
	ui->Homepage_btn_3_label = lv_label_create(ui->Homepage_btn_3);
	lv_label_set_text(ui->Homepage_btn_3_label, "Chat");
	lv_label_set_long_mode(ui->Homepage_btn_3_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Homepage_btn_3_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Homepage_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Homepage_btn_3, 218, 21);
	lv_obj_set_size(ui->Homepage_btn_3, 80, 80);

	//Write style for Homepage_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage_btn_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Homepage_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_btn_3, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_btn_4
	ui->Homepage_btn_4 = lv_btn_create(ui->Homepage);
	ui->Homepage_btn_4_label = lv_label_create(ui->Homepage_btn_4);
	lv_label_set_text(ui->Homepage_btn_4_label, "Game");
	lv_label_set_long_mode(ui->Homepage_btn_4_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Homepage_btn_4_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Homepage_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Homepage_btn_4, 25, 119);
	lv_obj_set_size(ui->Homepage_btn_4, 80, 80);

	//Write style for Homepage_btn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage_btn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage_btn_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Homepage_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_btn_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_btn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_btn_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_btn_4, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_btn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_username_label
	ui->Homepage_username_label = lv_label_create(ui->Homepage);
	lv_label_set_text(ui->Homepage_username_label, "Username");
	lv_label_set_long_mode(ui->Homepage_username_label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Homepage_username_label, 5, 215);
	lv_obj_set_size(ui->Homepage_username_label, 100, 20);

	//Write style for Homepage_username_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_username_label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_username_label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Homepage_username_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_username_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_username_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_digital_clock
	static bool Homepage_digital_clock_timer_enabled = false;
	ui->Homepage_digital_clock = lv_dclock_create(ui->Homepage, "11:25:50");
	if (!Homepage_digital_clock_timer_enabled) {
		lv_timer_create(Homepage_digital_clock_timer, 1000, NULL);
		Homepage_digital_clock_timer_enabled = true;
	}
	lv_obj_set_pos(ui->Homepage_digital_clock, 235, 210);
	lv_obj_set_size(ui->Homepage_digital_clock, 80, 20);

	//Write style for Homepage_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Homepage_digital_clock, lv_color_hex(0x12548b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Homepage_digital_clock, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Homepage_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Homepage_digital_clock, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Homepage_msgbox_1
	static const char * Homepage_msgbox_1_btns[] = {"Apply","Close",""};
	ui->Homepage_msgbox_1 = lv_msgbox_create(ui->Homepage, "Title", "content", Homepage_msgbox_1_btns, true);
	lv_obj_set_size(lv_msgbox_get_btns(ui->Homepage_msgbox_1), 120, 30);
	lv_obj_set_pos(ui->Homepage_msgbox_1, 20, 45);
	lv_obj_set_size(ui->Homepage_msgbox_1, 280, 150);

	//Write style for Homepage_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Homepage_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Homepage_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Homepage_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Homepage_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Homepage_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Homepage_msgbox_1_extra_title_main_default
	static lv_style_t style_Homepage_msgbox_1_extra_title_main_default;
	ui_init_style(&style_Homepage_msgbox_1_extra_title_main_default);
	
	lv_style_set_text_color(&style_Homepage_msgbox_1_extra_title_main_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_Homepage_msgbox_1_extra_title_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_Homepage_msgbox_1_extra_title_main_default, 0);
	lv_style_set_text_line_space(&style_Homepage_msgbox_1_extra_title_main_default, 30);
	lv_obj_add_style(lv_msgbox_get_title(ui->Homepage_msgbox_1), &style_Homepage_msgbox_1_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Homepage_msgbox_1_extra_content_main_default
	static lv_style_t style_Homepage_msgbox_1_extra_content_main_default;
	ui_init_style(&style_Homepage_msgbox_1_extra_content_main_default);
	
	lv_style_set_text_color(&style_Homepage_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_Homepage_msgbox_1_extra_content_main_default, &lv_font_montserratMedium_12);
	lv_style_set_text_letter_space(&style_Homepage_msgbox_1_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_Homepage_msgbox_1_extra_content_main_default, 10);
	lv_obj_add_style(lv_msgbox_get_text(ui->Homepage_msgbox_1), &style_Homepage_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Homepage_msgbox_1_extra_btns_items_default
	static lv_style_t style_Homepage_msgbox_1_extra_btns_items_default;
	ui_init_style(&style_Homepage_msgbox_1_extra_btns_items_default);
	
	lv_style_set_bg_opa(&style_Homepage_msgbox_1_extra_btns_items_default, 255);
	lv_style_set_bg_color(&style_Homepage_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
	lv_style_set_border_width(&style_Homepage_msgbox_1_extra_btns_items_default, 0);
	lv_style_set_radius(&style_Homepage_msgbox_1_extra_btns_items_default, 10);
	lv_style_set_text_color(&style_Homepage_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_Homepage_msgbox_1_extra_btns_items_default, &lv_font_montserratMedium_12);
	lv_obj_add_style(lv_msgbox_get_btns(ui->Homepage_msgbox_1), &style_Homepage_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->Homepage);

	
	//Init events for screen.
	events_init_Homepage(ui);
}
