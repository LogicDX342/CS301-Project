#include <stdio.h>
#include "custom.h"
#include "remote.h"

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
char count_str[10];
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
            printf("file_list[%d]: %s\r\n", i, file_list[i]);
            printf("lv_list_get_btn_text(list, obj): %s\r\n", lv_list_get_btn_text(list, obj));
            if (strcmp(file_list[i], lv_list_get_btn_text(list, obj)) == 0)
            {
                current_file_index = i;
                set_current_index(current_file_index);
                break;
            }
        }
    }
}

extern uint8_t RmtCnt;
void read_remote()
{
    uint8_t key = Remote_Scan();
    if (key != 0 && RmtCnt > 1)
    {
        RmtCnt = 0;
        switch (key)
        {
        case 98:
            set_prev_image();
            break;
        case 168:
            set_next_image();
            break;
        default:
            break;
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
            file_list[file_count] = (char *)malloc(strlen(fn) + 2);
            memset(file_list[file_count], 0, strlen(fn) + 2);
            strcpy(file_list[file_count], fn);
            printf("file_list[%d]: %s\r\n", file_count, file_list[file_count]);
            lv_obj_t *list_btn = lv_list_add_btn(list, LV_SYMBOL_FILE, fn);
            lv_obj_add_event_cb(list_btn, list_event_cb, LV_EVENT_CLICKED, NULL);
            file_count++;
        }
        lv_fs_dir_close(&dir);
        file_count = lv_obj_get_child_cnt(list);
        set_current_index(0);
    }
    static lv_timer_t *timer = NULL;
    if (timer == NULL) {
        timer = lv_timer_create(read_remote, 100, NULL);
        lv_timer_set_repeat_count(timer, -1);
    }
}
