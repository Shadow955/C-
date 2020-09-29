#pragma once

float sumcheck(int tag_check, float cost_term[]);

float sumpill(int tag_pill, int cost_perpill[30], int num_pill[30]);        //计算药品总费用函数

int date_turn(char a[8]);                 //将8位日期转化为天数

int days_hosp(int time_start, int time_end);                  //计算住院时长函数

int cost_hos(int a, int b, int c);          //住院费用函数

void getrecord(struct record* head);

void outpatient_tag(struct record* head, int tag_in);  //依据患者相关信息输出数据

void outpatient_name(struct record* head, char name[30]);		//检索患者姓名并输出
