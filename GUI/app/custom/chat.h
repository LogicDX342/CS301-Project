#ifndef CHAT_H
#define CHAT_H

#include "custom.h"
#define PRIVATE 0b00
#define PUBLIC 0b01
#define INVITE 0b10
#define ECHO 0b11

#define USER_A 0b00
#define USER_B 0b01


#define Jerry 0
#define Tom 1
#define Scott 2


//////Jerry's configuration begin
//#define friend_0 1
//#define friend_1 2
//////Jerry's configuration end


////Tom's configuration begin
//#define friend_0 0
//#define friend_1 2
////Tom's configuration end


////Scott's configuration begin
#define friend_0 0
#define friend_1 1
////Scott's configuration end


#define END 0b00
#define CONTINUE 0b01
void receive(lv_timer_t *timer);
void send(uint8_t msg_type, uint8_t sender, uint8_t receiver, uint8_t *msg);


#endif
