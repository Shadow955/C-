//modified by Nero on 9/29
#include<stdlib.h>
#include<stdio.h>
#include"base_struct.h"
#include<string.h>
#include"fileopt.h"
#include"allfunc.h"
struct record* rec_head;
FILE* infile;																//源文件为infile，更改后的输出文件为outfile
FILE* outfile;
/*********************************

争议：是否在源文件内直接操作？
			  有待讨论解决

*********************************/
int openfile() {															//文件读入函数
	infile = fopen("test.txt", "a");							//读取文件并判断是否成功打开
	if (infile == NULL)
	{
		printf("文件打开失败！请检查源文件！\n");		//打开失败结束并返回上层
		return 0;
	}
	else
		printf("文件打开成功！\n");
}
record* read_and_link() 
{


	/***********************************************************

	注意：格式化读入时，是否需要过滤回车？有待进一步测试

	************************************************************/


	rec_head = (record*)malloc(sizeof(record));		//建立头节点
	//rec_head->next = NULL;
	//record* rec_this = rec_head;								//建立当前节点
	//record* rec_temp;
	record* rec_temp = (record*)malloc(sizeof(record));//默认建立新节点
	rec_head->next = rec_temp;
	while (!EOF)																//循环读入直至文件末尾
	{
		//rec_temp = (record*)malloc(sizeof(record));//默认建立新节点
		fscanf(infile, "%d %s %d %d", &rec_temp->num_check, rec_temp->pat.name_pat, &rec_temp->pat.age, &rec_temp->pat.tag_pat);
			fscanf(infile, "%s %s %s %d"						//读入医生信息部分
				, (rec_temp->doc.name_doc)
				, (rec_temp->doc.level)
				, (rec_temp->doc.sub)
				, &(rec_temp->doc.num_work));
			fscanf(infile, "%s", rec_temp->out_doc);
			//fscanf(infile, "%s", rec_temp->tre.che.type[0]);
			int i = 0, j = 0;
			while (strcmp("over", rec_temp->tre.che.type[i]) != 0)//在读至over之前，循环读入检查项目名称与费用
			{
				fscanf(infile, "%f", rec_temp->tre.che.cost_term);
				i++;
			}
			while (strcmp("over", rec_temp->tre.pil.name_pill[j]) != 0)//在读至over之前，循环读入药品单价与数量
			{
				fscanf(infile, "%s %d %d"
					, rec_temp->tre.pil.name_pill[j]
					, &(rec_temp->tre.pil.cost_perpill[j])
					, &(rec_temp->tre.pil.num_pill[j]));
				j++;
			}
			fscanf(infile, "%d %d %d"									//读入住院信息部分
				, &(rec_temp->tre.hos.time_start)
				, &(rec_temp->tre.hos.time_end)
				, &rec_temp->tre.hos.deposit);
		
		rec_temp->next = (record*)malloc(sizeof(record));
		rec_temp = rec_temp->next;
	}
	//if (rec_head->next == NULL)
	//	rec_head = rec_temp;
	//rec_temp->next = NULL;											//准备建立新节点
	//rec_this->next = rec_temp;
	//rec_this = rec_temp;
	fclose(infile);
	printf("链表构建成功！");
	return rec_head->next;
	/****************************************

	链表建立后是否立即关闭文件？有待探讨

	***************************************/
}
void printf_number() {
	int number1;//保存输入的数字
	printf("请输入功能对应的数字：\n1:打印某科室诊疗信息\n2:打印某医生诊疗信息\n3:打印某患者历史诊疗记录\n4:打印某段时间内的诊疗记录");
	scanf("%d", &number1);
	switch (number1) {
	case 1: void outsub_doc(struct record* head); break;//打印某科室诊疗信息
	case 2: void outname_doc(struct record* head); break;//打印某医生诊疗信息
	case 3: outpatient_name(rec_head); break;//打印某患者历史诊疗记录
	case 4: void outtime_limit(struct record* head); break;//打印某段时间内的诊疗记录
	}
}