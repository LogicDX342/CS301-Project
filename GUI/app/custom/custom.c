/*
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

lv_obj_t *img_obj;

char *my_tolower(char *str)
{
    char *p = str;
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p + 32;
        }
        p++;
    }
    return str;
}


char file_list[5][8];
int file_count = 0;
int current_file_index = 0;

void set_prev_image()
{
    if (current_file_index > 0)
    {
        current_file_index--;
        char *prev_file = file_list[current_file_index];
        char path[32];
        sprintf(path, "S:/PICTURE/%s", prev_file);
        printf("Clicked: %s\r\n", path);
        lv_img_set_src(img_obj, path);
    }
}

void set_next_image()
{
    if (current_file_index < file_count - 1)
    {
        current_file_index++;
        char *next_file = file_list[current_file_index];
        char path[32];
        sprintf(path, "S:/PICTURE/%s", next_file);
        printf("Clicked: %s\r\n", path);
        lv_img_set_src(img_obj, path);
    }
}

static void list_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    lv_obj_t *list = lv_event_get_current_target(e);
    char path[32];
    if (code == LV_EVENT_CLICKED)
    {
        sprintf(path, "S:/PICTURE/%s", lv_list_get_btn_text(list, obj));
        printf("Clicked: %s\r\n", path);
        lv_img_set_src(img_obj, path);
    }
}

void get_file_list()
{
    lv_obj_t *list = guider_ui.Album_file_list;
    img_obj = guider_ui.Album_image;
    lv_obj_set_size(img_obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_fs_res_t res;
    lv_fs_dir_t dir;
    res = lv_fs_dir_open(&dir, "S:/PICTURE");
    printf("res: %d\r\n", res);
    if (res == LV_FS_RES_OK)
    {
        char fn[64];
        while (lv_fs_dir_read(&dir, fn) == LV_FS_RES_OK)
        {
            printf("fn: %s\r\n", fn);
            if (fn[0] == '\0')
            {
                break;
            }
            if (fn[0] == '/')
            {
                continue;
            }
            my_tolower(fn);
            file_list[file_count][0] = '\0';
            strcpy(file_list[file_count], fn);
            file_count++;
            lv_obj_t *list_btn = lv_list_add_btn(list, LV_SYMBOL_FILE, fn);
            lv_obj_add_event_cb(list_btn, list_event_cb, LV_EVENT_CLICKED, NULL);
        }
        lv_fs_dir_close(&dir);
    }
}