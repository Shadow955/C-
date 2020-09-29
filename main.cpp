#define funds = 0;
#include<stdio.h>
#include<stdlib.h>
#include"base_struct.h"
#include"fileopt.h"
#include"allfunc.h"

void printf_number() {
	int number1;//保存输入的数字
	printf("请输入功能对应的数字：\n1:打印某科室诊疗信息\n2:打印某医生诊疗信息\n3:打印某患者历史诊疗记录\n4:打印某段时间内的诊疗记录");
	scanf("%d", &number1);
	switch (number1) {
	case 1: void printf_sub(int); break;//打印某科室诊疗信息
	case 2: void printf_doctor(int); break;//打印某医生诊疗信息
	case 3: void printf_patient(struct patient); break;//打印某患者历史诊疗记录
	case 4: void printf_record_time(); break;//打印某段时间内的诊疗记录
	}
}

int main() {
	if (!openfile())									//开始时先执行文件读入函数，暂定以布尔类型判断
		return 0;

	read_and_link();								//读入源文件中现有的所有诊疗记录并生成一条链表

	/***************************
	****此处应为主界面部分****
	***************************/
	int number;//保存输入的数字
	printf("请输入要执行功能对应的数字：\n1:录入诊疗记录\n2:修改诊疗记录\n3:删除诊疗记录\n4:打印信息\n5:统计营业额，生成住院患者报表\n6:统计医生的出诊情况和工作繁忙程度\n7:保存当前系统中的所有信息\n");//设计数字对应操作
	scanf("%d", &number);
	switch (number) {
		case 1: struct record add_record(struct record); break;//录入诊疗记录
		case 2: struct record alter_record(int); break;//修改诊疗记录
		case 3: void delete_record(int); break;//删除诊疗记录
		case 4: printf_number(); break;//确认打印信息
		case 5: float espence(); break;//统计营业额
		case 6: void printf_doctor_condition(); break;//统计医生的出诊情况和工作繁忙程度
		case 7: void save(); break;//保存当前系统保存的信息
	}
}

