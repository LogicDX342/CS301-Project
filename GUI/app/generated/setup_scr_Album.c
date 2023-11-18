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

	//Write codes Album_return_btn
	ui->Album_return_btn = lv_btn_create(ui->Album);
	ui->Album_return_btn_label = lv_label_create(ui->Album_return_btn);
	lv_label_set_text(ui->Album_return_btn_label, "Return");
	lv_label_set_long_mode(ui->Album_return_btn_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Album_return_btn_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Album_return_btn, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->Album_return_btn, 5, 5);
	lv_obj_set_size(ui->Album_return_btn, 80, 30);

	//Write style for Album_return_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Album_return_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Album_return_btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Album_return_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Album_return_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Album_return_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Album_return_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Album_return_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Album_return_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Album_image
	ui->Album_image = lv_img_create(ui->Album);
	lv_obj_add_flag(ui->Album_image, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_pivot(ui->Album_image, 50,50);
	lv_img_set_angle(ui->Album_image, 0);
	lv_obj_set_pos(ui->Album_image, 171, 66);
	lv_obj_set_size(ui->Album_image, 135, 148);

	//Write style for Album_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Album_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Album_file_list
	ui->Album_file_list = lv_list_create(ui->Album);
	lv_obj_set_pos(ui->Album_file_list, 5, 45);
	lv_obj_set_size(ui->Album_file_list, 150, 190);
	lv_obj_set_scrollbar_mode(ui->Album_file_list, LV_SCROLLBAR_MODE_OFF);

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

	//Update current screen layout.
	lv_obj_update_layout(ui->Album);

	
	//Init events for screen.
	events_init_Album(ui);
}
