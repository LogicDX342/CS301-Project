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

char *file_list[5];
char count_str[5];
int file_count = 0;
int current_file_index = 0;

void set_current_index(int index)
{
    sprintf(count_str, "%d/%d", index + 1, file_count);
    lv_label_set_text(guider_ui.Album_count_label, count_str);
}

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
        set_current_index(current_file_index);
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
        set_current_index(current_file_index);
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
        for (int i = 0; i < file_count; i++)
        {
            if (strcmp(file_list[i], lv_list_get_btn_text(list, obj)) == 0)
            {
                current_file_index = i;
                set_current_index(current_file_index);
                break;
            }
        }
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
    if (res == LV_FS_RES_OK)
    {
        char fn[64];
        while (lv_fs_dir_read(&dir, fn) == LV_FS_RES_OK)
        {
            printf("fn: %s\r\n", fn);
            if (fn[0] == '\0' || fn[0] == '/')
            {
                break;
            }
            my_tolower(fn);
            file_list[file_count] = (char *)malloc(strlen(fn) + 1);
            memset(file_list[file_count], 0, strlen(fn) + 1);
            strcpy(file_list[file_count], fn);
            file_count++;
            lv_obj_t *list_btn = lv_list_add_btn(list, LV_SYMBOL_FILE, fn);
            lv_obj_add_event_cb(list_btn, list_event_cb, LV_EVENT_CLICKED, NULL);
        }
        lv_fs_dir_close(&dir);
        set_current_index(0);
    }
}