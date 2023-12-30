#include <stdio.h>
#include "custom.h"
#include "24l01.h"

#define PRIVATE 0b00
#define PUBLIC 0b01
#define INVITE 0b10
#define ECHO 0b11

#define USER_A 0b00
#define USER_B 0b01

#define END 0b00
#define CONTINUE 0b01

lv_obj_t *usr_scr[4] = {&guider_ui.Album};

char msg_buf[RX_PLOAD_WIDTH * 2 + 1];
char rx_buf[RX_PLOAD_WIDTH + 1];
char tx_buf[TX_PLOAD_WIDTH];

void send(uint8_t msg_type, uint8_t user, uint8_t *msg)
{
    uint8_t arg = (msg_type << 6) | (user << 4);
    // set the first char of the message to the argument
    // if message is too long, send it in multiple packets
    int len = strlen(msg);
    for (int i = 0; i < len; i += TX_PLOAD_WIDTH - 1)
    {
        tx_buf[0] = arg || (i + TX_PLOAD_WIDTH - 1 < len ? CONTINUE : END);
        strncpy(tx_buf + 1, msg + i, TX_PLOAD_WIDTH - 1);
        NRF24L01_TxPacket(tx_buf);
    }
}

void msgbox_event_cb(lv_event_t *e)
{
    // lv_obj_t *obj = lv_event_get_target(e);
    // lv_msgbox_close(obj);
}

void pop_msgbox(char *msg)
{
    static const char * btns[2] = {"Apply" , ""};
    lv_obj_t *msgbox = lv_msgbox_create(lv_scr_act(), "Chat Invitation", msg, btns, true);
    lv_obj_set_width(msgbox, 200);
    lv_obj_align(msgbox, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(msgbox, msgbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

void receive(lv_timer_t *timer)
{
    if (!NRF24L01_RxPacket(rx_buf))
    {
        if (lv_scr_act() == guider_ui.Album)
        {
            pop_msgbox("Album");
            return;
        }
        return;
        uint8_t msg_type = rx_buf[0] >> 6;
        uint8_t user = (rx_buf[0] >> 4) & 0b11;
        uint8_t end = rx_buf[0] & 0b01;
        uint8_t *msg = rx_buf + 1;
        switch (msg_type)
        {
        case PRIVATE:
            if (lv_scr_act() == usr_scr[user])
            {
                if (end == CONTINUE)
                {
                    strcat(msg_buf, msg);
                }
                else
                {
                    strcat(msg_buf, msg);
                    pop_msgbox(msg_buf);
                    msg_buf[0] = '\0';
                }
            }
            break;
        case PUBLIC:
            break;
        case INVITE:
            if (lv_scr_act() != guider_ui.Album)
            {
                pop_msgbox(msg);
            }
            break;
        case ECHO:
            break;
        default:
            break;
        }
        return NULL;
    }
}