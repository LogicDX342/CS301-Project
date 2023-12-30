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
#include <ctype.h>
#include <math.h>

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

lv_obj_t *cal_com_label_1;
lv_obj_t *cal_com_label_2;
lv_obj_t *cal_bi_label_1;
lv_obj_t *cal_bi_label_2;
lv_obj_t *cal_eq_label_a;
lv_obj_t *cal_eq_label_b;
lv_obj_t *cal_eq_label_c;
lv_obj_t *cal_eq_label_d;
lv_obj_t *cal_eq_label_ans;
lv_obj_t *cal_eq_label_input;

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
  cal_com_label_1=ui->cal_com_label_1;
  cal_com_label_2=ui->cal_com_label_2;
  cal_bi_label_1=ui->cal_bi_label_1;
  cal_bi_label_2=ui->cal_bi_label_2;
  cal_eq_label_a=ui->cal_eq_label_a;
  cal_eq_label_b=ui->cal_eq_label_b;
  cal_eq_label_c=ui->cal_eq_label_c;
  cal_eq_label_d=ui->cal_eq_label_d;
  cal_eq_label_ans=ui->cal_eq_label_ans;
  cal_eq_label_input=ui->cal_eq_label_input;
  
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

int fl = 0;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                fl = 1;
                return 0;
            }
            return a / b;
        case '^':
            return pow(a, b);
    }
    return 0;
}

char *evaluateExpression(char *expression) {
    int i;
    int values[100], topVal = -1, topOps = -1;
    char ops[100];
    memset(values,0,sizeof(values));
    memset(ops,0,sizeof(ops));
    int parentheses = 0;
    int lastWasOperator = 0;

    for (i = 0; i < strlen(expression); i++) {
        if(i==0&&expression[i]=='-'){
            lastWasOperator = 0;
            values[++topVal] = 0;
        }
        if(i>0){
            if(expression[i-1]=='('&&expression[i]=='-'){
                lastWasOperator = 0;
                values[++topVal] = 0;
            }
        }
        if (expression[i] == ' ') continue;

        else if (isdigit(expression[i])) {
            lastWasOperator = 0;
            int val = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            values[++topVal] = val;
        } else if (expression[i] == '(') {
            ops[++topOps] = expression[i];
            parentheses++;
            if (expression[i + 1] == ')') {
                fl = 1;
                break;
            }
            lastWasOperator = 0;
        } else if (expression[i] == ')') {
            if (parentheses == 0) {
                fl = 1;
                break;
            }
            while (topOps != -1 && ops[topOps] != '(') {
                int val2 = values[topVal--];
                int val1 = values[topVal--];
                char op = ops[topOps--];

                values[++topVal] = applyOp(val1, val2, op);
            }
            if (topOps != -1) topOps--;
            parentheses--;
            lastWasOperator = 0;
        } else {
            if (lastWasOperator) {
                fl = 1;
                break;
            }
            while (topOps != -1 && precedence(ops[topOps]) >= precedence(expression[i]) && expression[i] != '^') {
                int val2 = values[topVal--];
                int val1 = values[topVal--];
                char op = ops[topOps--];

                values[++topVal] = applyOp(val1, val2, op);
            }
            ops[++topOps] = expression[i];
            lastWasOperator = 1;
        }
    }

    if (fl || parentheses != 0) {
        char *error_message = (char *) malloc(strlen("Invalid expression") + 1);
        strcpy(error_message, "Invalid expression");
        return error_message;
    }

    while (topOps != -1) {
        int val2 = values[topVal--];
        int val1 = values[topVal--];
        char op = ops[topOps--];
        values[++topVal] = applyOp(val1, val2, op);
    }
    int result = values[topVal];
    char *result_message = (char *) malloc(30);
    sprintf(result_message, "%d", result);
    return result_message;
}

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    while (*binary != '\0') {
        decimal = decimal * 2 + (*binary - '0');
        binary++;
    }
    return decimal;
}

char *decimalToBinary(int decimal) {
    int isNegative = decimal < 0;
    if (isNegative) {
        decimal = -decimal;
    }

    if (decimal == 0) return strdup("0");

    int bits = sizeof(int) * 8;
    char *binary = (char *) malloc(bits + 1);
    binary[bits] = '\0';

    int index = bits - 1;
    while (decimal > 0) {
        binary[index--] = (decimal % 2) + '0';
        decimal /= 2;
    }

    if (isNegative) {
        binary[index] = '-';
        return strdup(binary + index);
    } else {
        return strdup(binary + index + 1);
    }
}

int calculate(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*';
}

char *binaryOperation(const char *binaryExpression) {
    int values[64], topVal = -1, topOps = -1;
    char ops[64];
    memset(values,0,sizeof(values));
    memset(ops,0,sizeof(ops));
    int i = 0;
    if (binaryExpression[i] == '-') {
        values[++topVal] = 0;
        ops[++topOps] = '-'; 
        i++; 
    }

    for (; binaryExpression[i] != '\0'; i++) {
        if (isspace(binaryExpression[i])) continue;

        if (isdigit(binaryExpression[i])) {
            char binary[64];
            int index = 0;
            while (i < strlen(binaryExpression) && isdigit(binaryExpression[i])) {
                binary[index++] = binaryExpression[i++];
            }
            binary[index] = '\0';
            i--;
            values[++topVal] = binaryToDecimal(binary);
        } else if (isOperator(binaryExpression[i])) {
            while (topOps != -1 && precedence(ops[topOps]) >= precedence(binaryExpression[i])) {
                int val2 = values[topVal--];
                int val1 = values[topVal--];
                char op = ops[topOps--];

                values[++topVal] = calculate(val1, val2, op);
            }
            ops[++topOps] = binaryExpression[i];
        }
    }

    while (topOps != -1) {
        int val2 = values[topVal--];
        int val1 = values[topVal--];
        char op = ops[topOps--];

        values[++topVal] = calculate(val1, val2, op);
    }

    return decimalToBinary(values[topVal]);
}


char exp_com[64];
int eccnt;
char exp_bi[64];
int ebcnt;
char exp_a[64], exp_b[64], exp_c[64], exp_d[64];
int acnt, bcnt, ccnt, dcnt,nowsta;

void funchange(char c){
    if(nowsta==0){
    	exp_a[acnt++]=c;
    }
    else if(nowsta==1){
    	exp_b[bcnt++]=c;
    }
    else if(nowsta==2){
    	exp_c[ccnt++]=c;
    }
    else if(nowsta==3){
    	exp_d[dcnt++]=c;
    }
}

char* solveEquation(char* a, char* b, char* c, char* d) {
    double da = atof(a);
    double db = atof(b);
    double dc = atof(c) - atof(d);
    char* result = (char*)malloc(50);
    if (da == 0) {
        double x = -dc / db;
        sprintf(result, "x=%.3f", x);
    } else {
        double delta = db * db - 4 * da * dc;
        if (delta < 0) {
            sprintf(result, "No real roots");
        } else if (delta == 0) {
            double x = -db / (2 * da);
            sprintf(result, "x=%.3f", x);
        } else {
            double x1 = (-db + sqrt(delta)) / (2 * da);
            double x2 = (-db - sqrt(delta)) / (2 * da);
            sprintf(result, "x=%.3f|x=%.3f", x1, x2);
        }
    }
    return result;
}

void click_com_1(){exp_com[eccnt++] = '1';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_2(){exp_com[eccnt++] = '2';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_3(){exp_com[eccnt++] = '3';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_4(){exp_com[eccnt++] = '4';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_5(){exp_com[eccnt++] = '5';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_6(){exp_com[eccnt++] = '6';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_7(){exp_com[eccnt++] = '7';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_8(){exp_com[eccnt++] = '8';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_9(){exp_com[eccnt++] = '9';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_0(){exp_com[eccnt++] = '0';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_add(){exp_com[eccnt++] = '+';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_sub(){exp_com[eccnt++] = '-';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_mul(){exp_com[eccnt++] = '*';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_div(){exp_com[eccnt++] = '/';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_pow(){exp_com[eccnt++] = '^';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_left(){exp_com[eccnt++] = '(';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_right(){exp_com[eccnt++] = ')';lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_del(){exp_com[--eccnt] = 0;lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_clean(){memset(exp_com,0,sizeof(exp_com));eccnt=0;lv_label_set_text(cal_com_label_1, exp_com);lv_label_set_text(cal_com_label_2, "");}
void click_com_eql(){
  fl = 0;
  char *commenresult = evaluateExpression(exp_com);
  lv_label_set_text(cal_com_label_2, commenresult);
  exp_com[eccnt++] = '=';
  lv_label_set_text(cal_com_label_1, exp_com);
 memset(exp_com, 0, sizeof(exp_com));
 eccnt = 0;
  free(commenresult);
}

void click_bi_1(){exp_bi[ebcnt++] = '1';lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_0(){exp_bi[ebcnt++] = '0';lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_add(){exp_bi[ebcnt++] = '+';lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_sub(){exp_bi[ebcnt++] = '-';lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_mul(){exp_bi[ebcnt++] = '*';lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_del(){exp_bi[--ebcnt] = 0;lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_clean(){memset(exp_bi,0,sizeof(exp_bi));ebcnt=0;lv_label_set_text(cal_bi_label_1, exp_bi);lv_label_set_text(cal_bi_label_2, "");}
void click_bi_eql(){
  char *biresult = binaryOperation(exp_bi);
  lv_label_set_text(cal_bi_label_2, biresult);
  exp_bi[ebcnt++] = '=';
  lv_label_set_text(cal_bi_label_1, exp_bi);
  memset(exp_bi, 0, sizeof(exp_bi));
   ebcnt = 0;
  free(biresult);
  }

void showabcd(){
  if(nowsta==0)
    lv_label_set_text(cal_eq_label_input, "now input a");
  else if(nowsta==1)
    lv_label_set_text(cal_eq_label_input, "now input b");
  else if(nowsta==2)
    lv_label_set_text(cal_eq_label_input, "now input c");
  else if(nowsta==3)
    lv_label_set_text(cal_eq_label_input, "now input d");
  lv_label_set_text(cal_eq_label_a, exp_a);
  lv_label_set_text(cal_eq_label_b, exp_b);
  lv_label_set_text(cal_eq_label_c, exp_c);
  lv_label_set_text(cal_eq_label_d, exp_d);
  lv_label_set_text(cal_eq_label_ans, "");
}

void click_eq_1(){funchange('1');showabcd();}
void click_eq_2(){funchange('2');showabcd();}
void click_eq_3(){funchange('3');showabcd();}
void click_eq_4(){funchange('4');showabcd();}
void click_eq_5(){funchange('5');showabcd();}
void click_eq_6(){funchange('6');showabcd();}
void click_eq_7(){funchange('7');showabcd();}
void click_eq_8(){funchange('8');showabcd();}
void click_eq_9(){funchange('9');showabcd();}
void click_eq_0(){funchange('0');showabcd();}
void click_eq_sub(){funchange('-');showabcd();}
void click_eq_pre(){
  if(nowsta!=0){
    nowsta--;
  }
  showabcd();
}
void click_eq_nex(){
   if(nowsta!=3){
    nowsta++;
  }
  showabcd();
}
void click_eq_del(){
	if(nowsta==0){
		exp_a[--acnt]=0;
	}
	else if(nowsta==1){
		exp_b[--bcnt]=0;
	}
	else if(nowsta==2){
		exp_c[--ccnt]=0;
	}
	else if(nowsta==3){
		exp_d[--dcnt]=0;
	}
  showabcd();
}
void click_eq_clean(){
	if(nowsta==0){
		memset(exp_a, 0, sizeof(exp_a));
		acnt=0;
	}
	else if(nowsta==1){
		memset(exp_b, 0, sizeof(exp_b));
		bcnt=0;
	}
	else if(nowsta==2){
		memset(exp_c, 0, sizeof(exp_c));
		ccnt=0;
	}
	else if(nowsta==3){
		memset(exp_d, 0, sizeof(exp_d));
		dcnt=0;
	}  
  showabcd();
}
void click_eq_eql(){
	fl = 0;
	char *fresult = solveEquation(exp_a,exp_b,exp_c,exp_d);
    lv_label_set_text(cal_eq_label_ans, fresult);
	memset(exp_a, 0, sizeof(exp_a));
	memset(exp_b, 0, sizeof(exp_b));
	memset(exp_c, 0, sizeof(exp_d));
	memset(exp_d, 0, sizeof(exp_d));
	acnt =bcnt =ccnt =dcnt = 0;
    free(fresult);
  }

void cal_init(){
  fl=eccnt=ebcnt=acnt=bcnt=ccnt=dcnt=nowsta=0;
  memset(exp_com,0,sizeof(exp_com));
  memset(exp_bi,0,sizeof(exp_bi));
  memset(exp_a,0,sizeof(exp_a));
  memset(exp_b,0,sizeof(exp_b));
  memset(exp_c,0,sizeof(exp_c));
  memset(exp_d,0,sizeof(exp_d));
}