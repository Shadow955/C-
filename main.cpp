#define funds = 0;
#include<stdio.h>
#include<stdlib.h>
#include"base_struct.h"
#include"fileopt.h"
#include"allfunc.h"
int main() {
	if (!openfile())									//开始时先执行文件读入函数，暂定以布尔类型判断
		return 0;
	read_and_link();								//读入源文件中现有的所有诊疗记录并生成一条链表

	/***************************
	****此处应为主界面部分****
	***************************/

}