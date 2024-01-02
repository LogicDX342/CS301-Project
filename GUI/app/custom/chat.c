#include <stdio.h>
#include "custom.h"
#include "24l01.h"



lv_obj_t **usr_scr[10] = {&guider_ui.user0,&guider_ui.user1,&guider_ui.chat,&guider_ui.GroupChat,&guider_ui.Homepage,&guider_ui.cal_com,&guider_ui.cal_bi,&guider_ui.cal_eq,&guider_ui.Album};

char msg_buf[RX_PLOAD_WIDTH * 2 + 1]={0x0};
uint8_t rx_buf[RX_PLOAD_WIDTH + 1];
uint8_t tx_buf[TX_PLOAD_WIDTH];

typedef struct
{
    uint8_t msg_type;
    uint8_t sender;
    uint8_t receiver;
    char * message;
} msg_t;

void send_callback(lv_timer_t *timer)
{
	printf("timer callback\n");
    msg_t *msg = (msg_t *)timer->user_data;
    NRF24L01_TX_Mode(msg->receiver);
    uint8_t arg = (msg->msg_type << 6) | (msg->sender << 4);
    int len = strlen(msg->message);
    static int i = 0;

	uint8_t end = (i + TX_PLOAD_WIDTH - 2 < len ? CONTINUE : END);
	tx_buf[0] = arg | end;
	char * message = msg->message;

	printf("%x\n",arg);
	strncpy(tx_buf + 1, message + i, TX_PLOAD_WIDTH - 2);
	tx_buf[TX_PLOAD_WIDTH-1] = 0;
	if (NRF24L01_TxPacket(tx_buf)==TX_OK)
		printf(tx_buf);
	printf("send: %s\n",message);
    i += TX_PLOAD_WIDTH - 1;
    if (i >= len)
    {
    	printf("delete timer\n");
        i = 0;
        lv_timer_del(timer);
        free(msg);
    }
}

void send(uint8_t msg_type, uint8_t sender, uint8_t receiver, char *message)
{
	printf("enter send()\n");
	NRF24L01_TX_Mode(receiver);

//    uint8_t arg = (msg_type << 6) | (sender << 4);
//    // set the first char of the message to the argument
//    // if message is too long, send it in multiple packets
//    uint32_t len = strlen(msg);

//    for (int i = 0; i < len; i += TX_PLOAD_WIDTH - 2)
//    {
//    	uint8_t end = (i + TX_PLOAD_WIDTH - 2 < len ? CONTINUE : END);
//        tx_buf[0] = arg | end;
//        printf("%x\n",arg);
//        strncpy(tx_buf + 1, msg + i, TX_PLOAD_WIDTH - 2);
//        tx_buf[TX_PLOAD_WIDTH-1] = 0;
//        if (NRF24L01_TxPacket(tx_buf)==TX_OK)
//        	printf(tx_buf);
//        if (end==CONTINUE)
//        	HAL_Delay(1000);
//    }

	msg_t *msg=malloc(sizeof(msg_t));
//	msg_t msg;
	msg->msg_type = msg_type;
	msg->sender = sender;
	msg->receiver = receiver;
	msg->message = strdup(message);
//	if (timer == NULL)
	{
		printf("create timer\n");
		printf("send: %s\n",message);
		lv_timer_t *timer = lv_timer_create(send_callback, 1000, msg);
		lv_timer_set_repeat_count(timer, -1);
	}
}

void msgbox_event_cb0(lv_event_t *e)
{
	//Write the load screen code.
	lv_obj_t * act_scr = lv_scr_act();
	lv_disp_t * d = lv_obj_get_disp(act_scr);
	if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
		lv_obj_clean(act_scr);
		if (guider_ui.user0_del == true) {
		  setup_scr_user0(&guider_ui);
		}
		lv_scr_load_anim(guider_ui.user0, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
		guider_ui.chat_del = true;
	}
}

void msgbox_event_cb1(lv_event_t *e)
{
	//Write the load screen code.
    lv_obj_t * act_scr = lv_scr_act();
    lv_disp_t * d = lv_obj_get_disp(act_scr);
    if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr)) {
		lv_obj_clean(act_scr);
        if (guider_ui.user1_del == true) {
          setup_scr_user1(&guider_ui);
        }
        lv_scr_load_anim(guider_ui.user1, LV_SCR_LOAD_ANIM_NONE, 200, 200, true);
        guider_ui.chat_del = true;
    }
}
void pop_msgbox0(char *msg)
{
    static const char * btns[2] = {"Apply" , ""};
    lv_obj_t *msgbox = lv_msgbox_create(lv_scr_act(), "Notice", msg, btns, true);
    lv_obj_set_width(msgbox, 200);
    lv_obj_align(msgbox, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(msgbox, msgbox_event_cb0, LV_EVENT_VALUE_CHANGED, NULL);
}

void pop_msgbox1(char *msg)
{
    static const char * btns[2] = {"Apply" , ""};
    lv_obj_t *msgbox = lv_msgbox_create(lv_scr_act(), "Notice", msg, btns, true);
    lv_obj_set_width(msgbox, 200);
    lv_obj_align(msgbox, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(msgbox, msgbox_event_cb1, LV_EVENT_VALUE_CHANGED, NULL);
}

void receive(lv_timer_t *timer)
{
	printf("enter receive()\n");
	NRF24L01_RX_Mode();
    if (!NRF24L01_RxPacket(rx_buf))
    {
    	printf("enter if\n");
        uint8_t msg_type = rx_buf[0] >> 6;
        rx_buf[RX_PLOAD_WIDTH] = 0;
        uint8_t user = (rx_buf[0] >> 4) & 0b11;
        uint8_t end = rx_buf[0] & 0b01;
        uint8_t *msg = rx_buf + 1;
        switch (msg_type)
        {
        case PRIVATE:
        	printf("enter PRIVATE\n");
//        	printf("enter private\n");
        	printf("%x\n",user);
        	printf("%x\n",friend_0);
//        	printf("%x\n",friend_0);
//        	printf("%x\n",lv_scr_act());
//        	printf("%x\n",usr_scr[0]);
            if (user == friend_0 && lv_scr_act() == *usr_scr[0])
            {
            	printf("enter friend0\n");
            	printf("%x\n",end);
                if (end == CONTINUE)
                {
                	printf("%s\n",msg);
                    strcat(msg_buf, msg);
                }
                else
                {
                	printf("enter else\n");
                    strcat(msg_buf, msg);
                    printf("%s\n",msg_buf);
                    lv_obj_t *list = guider_ui.user0_list_1;
                    lv_list_add_text(list, "User0:");
                    lv_obj_t *item = lv_list_add_text(list, msg_buf);
                    lv_label_set_long_mode(item, LV_LABEL_LONG_WRAP);
                    msg_buf[0] = '\0';
                }

            }else if(user == friend_1 && lv_scr_act() == *usr_scr[1]){
            	printf("enter friend1\n");
				if (end == CONTINUE)
				{
					strcat(msg_buf, msg);
				}
				else
				{
					printf("enter else\n");
					strcat(msg_buf, msg);
					printf("%s\n",msg_buf);
					lv_obj_t *list = guider_ui.user1_list_1;
					lv_list_add_text(list, "User1:");
					lv_obj_t *item = lv_list_add_text(list, msg_buf);
					lv_label_set_long_mode(item, LV_LABEL_LONG_WRAP);
					msg_buf[0] = '\0';
				}
            }
            break;
        case PUBLIC:
        	printf("enter PUBLIC\n");
        	if(lv_scr_act() == *usr_scr[3]){
            	printf("enter group\n");
				if (end == CONTINUE)
				{
					strcat(msg_buf, msg);
				}
				else
				{
					printf("enter else\n");
					strcat(msg_buf, msg);
					printf("%s\n",msg_buf);
					lv_obj_t *list = guider_ui.GroupChat_list_1;
					if(user == friend_0){
						lv_list_add_text(list, "User0:");
					}else{
						lv_list_add_text(list, "User1:");
					}
					lv_obj_t *item = lv_list_add_text(list, msg_buf);
					lv_label_set_long_mode(item, LV_LABEL_LONG_WRAP);
					msg_buf[0] = '\0';
				}
        	}
            break;
        case INVITE:
        	printf("enter INVITE\n");
            if (lv_scr_act() != guider_ui.Album)
            {
            	printf("enter pop\n");
            	if(user == friend_0){
            		pop_msgbox0(msg);
            	}else if(user == friend_1){
            		pop_msgbox1(msg);
            	}

            }
            break;
        case ECHO:
        	printf("enter ECHO\n");
            break;
        default:
            break;
        }
    }
    printf("exit receive()\n");
}
