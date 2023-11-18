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


void setup_scr_Album(lv_ui *ui)
{
	//Write codes Album
	ui->Album = lv_obj_create(NULL);
	lv_obj_set_size(ui->Album, 320, 240);

	//Write style for Album, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Album, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Album_file_list
	ui->Album_file_list = lv_list_create(ui->Album);
	ui->Album_file_list_item0 = lv_list_add_btn(ui->Album_file_list, LV_SYMBOL_SAVE, "save");
	lv_obj_set_pos(ui->Album_file_list, 5, 49);
	lv_obj_set_size(ui->Album_file_list, 145, 182);
	lv_obj_set_scrollbar_mode(ui->Album_file_list, LV_SCROLLBAR_MODE_AUTO);

	//Write style state: LV_STATE_DEFAULT for &style_Album_file_list_main_main_default
	static lv_style_t style_Album_file_list_main_main_default;
	ui_init_style(&style_Album_file_list_main_main_default);
	
	lv_style_set_pad_top(&style_Album_file_list_main_main_default, 5);
	lv_style_set_pad_left(&style_Album_file_list_main_main_default, 5);
	lv_style_set_pad_right(&style_Album_file_list_main_main_default, 5);
	lv_style_set_pad_bottom(&style_Album_file_list_main_main_default, 5);
	lv_style_set_bg_opa(&style_Album_file_list_main_main_default, 255);
	lv_style_set_bg_color(&style_Album_file_list_main_main_default, lv_color_hex(0xffffff));
	lv_style_set_border_width(&style_Album_file_list_main_main_default, 1);
	lv_style_set_border_opa(&style_Album_file_list_main_main_default, 255);
	lv_style_set_border_color(&style_Album_file_list_main_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_Album_file_list_main_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_Album_file_list_main_main_default, 3);
	lv_style_set_shadow_width(&style_Album_file_list_main_main_default, 0);
	lv_obj_add_style(ui->Album_file_list, &style_Album_file_list_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Album_file_list_main_scrollbar_default
	static lv_style_t style_Album_file_list_main_scrollbar_default;
	ui_init_style(&style_Album_file_list_main_scrollbar_default);
	
	lv_style_set_radius(&style_Album_file_list_main_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_Album_file_list_main_scrollbar_default, 255);
	lv_style_set_bg_color(&style_Album_file_list_main_scrollbar_default, lv_color_hex(0xffffff));
	lv_obj_add_style(ui->Album_file_list, &style_Album_file_list_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Album_file_list_extra_btns_main_default
	static lv_style_t style_Album_file_list_extra_btns_main_default;
	ui_init_style(&style_Album_file_list_extra_btns_main_default);
	
	lv_style_set_pad_top(&style_Album_file_list_extra_btns_main_default, 5);
	lv_style_set_pad_left(&style_Album_file_list_extra_btns_main_default, 5);
	lv_style_set_pad_right(&style_Album_file_list_extra_btns_main_default, 5);
	lv_style_set_pad_bottom(&style_Album_file_list_extra_btns_main_default, 5);
	lv_style_set_border_width(&style_Album_file_list_extra_btns_main_default, 0);
	lv_style_set_text_color(&style_Album_file_list_extra_btns_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_Album_file_list_extra_btns_main_default, &lv_font_montserratMedium_12);
	lv_style_set_radius(&style_Album_file_list_extra_btns_main_default, 3);
	lv_style_set_bg_opa(&style_Album_file_list_extra_btns_main_default, 255);
	lv_style_set_bg_color(&style_Album_file_list_extra_btns_main_default, lv_color_hex(0xffffff));
	lv_obj_add_style(ui->Album_file_list_item0, &style_Album_file_list_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_Album_file_list_extra_texts_main_default
	static lv_style_t style_Album_file_list_extra_texts_main_default;
	ui_init_style(&style_Album_file_list_extra_texts_main_default);
	
	lv_style_set_pad_top(&style_Album_file_list_extra_texts_main_default, 5);
	lv_style_set_pad_left(&style_Album_file_list_extra_texts_main_default, 5);
	lv_style_set_pad_right(&style_Album_file_list_extra_texts_main_default, 5);
	lv_style_set_pad_bottom(&style_Album_file_list_extra_texts_main_default, 5);
	lv_style_set_border_width(&style_Album_file_list_extra_texts_main_default, 0);
	lv_style_set_text_color(&style_Album_file_list_extra_texts_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_Album_file_list_extra_texts_main_default, &lv_font_montserratMedium_12);
	lv_style_set_radius(&style_Album_file_list_extra_texts_main_default, 3);
	lv_style_set_bg_opa(&style_Album_file_list_extra_texts_main_default, 255);
	lv_style_set_bg_color(&style_Album_file_list_extra_texts_main_default, lv_color_hex(0xffffff));

	//Write codes Album_btn_1
	ui->Album_btn_1 = lv_btn_create(ui->Album);
	ui->Album_btn_1_label = lv_label_create(ui->Album_btn_1);
	lv_label_set_text(ui->Album_btn_1_label, "Return");
	lv_label_set_long_mode(ui->Album_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Album_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Album_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Album_btn_1, 5, 5);
	lv_obj_set_size(ui->Album_btn_1, 80, 30);

	//Write style for Album_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Album_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Album_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Album_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Album_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Album_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Album_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Album_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Album_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Album_img_1
	ui->Album_img_1 = lv_img_create(ui->Album);
	lv_obj_add_flag(ui->Album_img_1, LV_OBJ_FLAG_CLICKABLE);
#if LV_USE_GUIDER_SIMULATOR
	lv_img_set_src(ui->Album_img_1, "");
#else
	lv_img_set_src(ui->Album_img_1, "S:/example_16bit.bmp/");
#endif
	lv_img_set_pivot(ui->Album_img_1, 50,50);
	lv_img_set_angle(ui->Album_img_1, 0);
	lv_obj_set_pos(ui->Album_img_1, 172, 70);
	lv_obj_set_size(ui->Album_img_1, 100, 100);

	//Write style for Album_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Album_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Album_spinner_1
	ui->Album_spinner_1 = lv_spinner_create(ui->Album, 1000, 60);
	lv_obj_set_pos(ui->Album_spinner_1, 197, 95);
	lv_obj_set_size(ui->Album_spinner_1, 50, 50);

	//Write style for Album_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->Album_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Album_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Album_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Album_spinner_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Album_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->Album_spinner_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->Album_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->Album_spinner_1, lv_color_hex(0xd5d6de), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Album_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Album_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->Album_spinner_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->Album_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->Album_spinner_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Update current screen layout.
	lv_obj_update_layout(ui->Album);

	
	//Init events for screen.
	events_init_Album(ui);
}
