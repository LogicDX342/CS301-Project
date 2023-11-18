/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"


#include "custom.h"
static void Homepage_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
			lv_obj_clean(act_scr);
	        if (guider_ui.Album_del == true) {
	          setup_scr_Album(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Album, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, true);
	        guider_ui.Homepage_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Homepage(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Homepage_btn_1, Homepage_btn_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Album_file_list_item0_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		show_image(char*);
		show_image(char*);
		//Write animation: Album_img_1 move_x
	  	lv_anim_t Album_img_1_anim_move_x;
	  	lv_anim_init(&Album_img_1_anim_move_x);
	  	lv_anim_set_var(&Album_img_1_anim_move_x, guider_ui.Album_img_1);
	  	lv_anim_set_time(&Album_img_1_anim_move_x, 1000);
	  	lv_anim_set_delay(&Album_img_1_anim_move_x, 0);
	  	lv_anim_set_exec_cb(&Album_img_1_anim_move_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
		lv_anim_set_values(&Album_img_1_anim_move_x, lv_obj_get_x(guider_ui.Album_img_1), 0);
	  	lv_anim_set_path_cb(&Album_img_1_anim_move_x, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&Album_img_1_anim_move_x, 0);
	  	lv_anim_set_repeat_delay(&Album_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_time(&Album_img_1_anim_move_x, 0);
	  	lv_anim_set_playback_delay(&Album_img_1_anim_move_x, 0);
		lv_anim_start(&Album_img_1_anim_move_x);
		//Write animation: Album_img_1 move_y
	  	lv_anim_t Album_img_1_anim_move_y;
	  	lv_anim_init(&Album_img_1_anim_move_y);
	  	lv_anim_set_var(&Album_img_1_anim_move_y, guider_ui.Album_img_1);
	  	lv_anim_set_time(&Album_img_1_anim_move_y, 1000);
	  	lv_anim_set_delay(&Album_img_1_anim_move_y, 0);
	  	lv_anim_set_exec_cb(&Album_img_1_anim_move_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
		lv_anim_set_values(&Album_img_1_anim_move_y, lv_obj_get_y(guider_ui.Album_img_1), 0);
	  	lv_anim_set_path_cb(&Album_img_1_anim_move_y, &lv_anim_path_linear);
	  	lv_anim_set_repeat_count(&Album_img_1_anim_move_y, 0);
	  	lv_anim_set_repeat_delay(&Album_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_time(&Album_img_1_anim_move_y, 0);
	  	lv_anim_set_playback_delay(&Album_img_1_anim_move_y, 0);
		lv_anim_start(&Album_img_1_anim_move_y);
		lv_obj_clear_flag(guider_ui.Album_spinner_1, LV_OBJ_FLAG_HIDDEN);
		break;
	}
	default:
		break;
	}
}
void events_init_Album(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Album_file_list_item0, Album_file_list_item0_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
