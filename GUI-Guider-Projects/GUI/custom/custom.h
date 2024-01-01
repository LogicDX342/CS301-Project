/*
* Copyright 2023 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void custom_init(lv_ui *ui);
void get_file_list();
void set_prev_image();
void set_next_image();
void start_msg_timer();
int precedence(char op);
int applyOp(int a, int b, char op);
char *evaluateExpression(char *expression);

int binaryToDecimal(const char *binary);
char *decimalToBinary(int decimal);
int calculate(int a, int b, char op);
int isOperator(char c);
char *binaryOperation(const char *binaryExpression);

void funchange(char c);
char* solveEquation(char* a, char* b, char* c, char* d);

void click_com_1(void);
void click_com_2(void);
void click_com_3(void);
void click_com_4(void);
void click_com_5(void);
void click_com_6(void);
void click_com_7(void);
void click_com_8(void);
void click_com_9(void);
void click_com_0(void);
void click_com_add(void);
void click_com_sub(void);
void click_com_mul(void);
void click_com_div(void);
void click_com_pow(void);
void click_com_left(void);
void click_com_right(void);
void click_com_del(void);
void click_com_clean(void);
void click_com_eql(void);
void cal_init(void);
void click_bi_1();
void click_bi_0();
void click_bi_add();
void click_bi_sub();
void click_bi_mul();
void click_bi_del();
void click_bi_clean();
void click_bi_eql();
void showabcd();
void click_eq_1();
void click_eq_2();
void click_eq_3();
void click_eq_4();
void click_eq_5();
void click_eq_6();
void click_eq_7();
void click_eq_8();
void click_eq_9();
void click_eq_0();
void click_eq_sub();
void click_eq_pre();
void click_eq_nex();
void click_eq_del();
void click_eq_clean();
void click_eq_eql();

#define SIZE 4

void game_init();
void printBoard();
void addRandom();
bool checkGameOver();
void moveLeft();
void moveRight();
void moveUp();
void moveDown();
int findMax();

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
