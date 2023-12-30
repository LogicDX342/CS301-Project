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
static void Homepage_btn_3_event_handler (lv_event_t *e)
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
	        if (guider_ui.Chat_del == true) {
	          setup_scr_Chat(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
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
	lv_obj_add_event_cb(ui->Homepage_btn_3, Homepage_btn_3_event_handler, LV_EVENT_ALL, NULL);
}
static void Album_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		get_file_list();
		break;
	}
	case LV_EVENT_GESTURE:
	{
		lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
		switch(dir) {
			case LV_DIR_TOP:
			{
				lv_indev_wait_release(lv_indev_get_act());
				set_next_image();
				break;
			}
			case LV_DIR_BOTTOM:
			{
				lv_indev_wait_release(lv_indev_get_act());
				set_prev_image();
				break;
			}
		}
		break;
	}
	default:
		break;
	}
}
static void Album_return_btn_event_handler (lv_event_t *e)
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
	        if (guider_ui.Homepage_del == true) {
	          setup_scr_Homepage(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Homepage, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Album_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Album(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Album, Album_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Album_return_btn, Album_return_btn_event_handler, LV_EVENT_ALL, NULL);
}
static void Chat_btn_1_event_handler (lv_event_t *e)
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
	        if (guider_ui.Chat_0_del == true) {
	          setup_scr_Chat_0(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat_0, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void Chat_btn_2_event_handler (lv_event_t *e)
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
	        if (guider_ui.Chat_1_del == true) {
	          setup_scr_Chat_1(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat_1, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void Chat_btn_3_event_handler (lv_event_t *e)
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
	        if (guider_ui.Group_del == true) {
	          setup_scr_Group(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Group, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
static void Chat_btn_4_event_handler (lv_event_t *e)
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
	        if (guider_ui.Homepage_del == true) {
	          setup_scr_Homepage(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Homepage, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Chat(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Chat_btn_1, Chat_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Chat_btn_2, Chat_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Chat_btn_3, Chat_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Chat_btn_4, Chat_btn_4_event_handler, LV_EVENT_ALL, NULL);
}
static void Chat_0_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.Chat_del == true) {
	          setup_scr_Chat(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_0_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Chat_0(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Chat_0_btn_1, Chat_0_btn_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Chat_1_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.Chat_del == true) {
	          setup_scr_Chat(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Chat_1_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Chat_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Chat_1_btn_1, Chat_1_btn_1_event_handler, LV_EVENT_ALL, NULL);
}
static void Group_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//Write the load screen code.
	    lv_obj_t * act_scr = lv_scr_act();
	    lv_disp_t * d = lv_obj_get_disp(act_scr);
	    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
	        if (guider_ui.Chat_del == true) {
	          setup_scr_Chat(&guider_ui);
	        }
	        lv_scr_load_anim(guider_ui.Chat, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
	        guider_ui.Group_del = true;
	    }
		break;
	}
	default:
		break;
	}
}
void events_init_Group(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Group_btn_1, Group_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}
