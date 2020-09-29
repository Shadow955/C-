//base_struct.h version2.0 designed by Nero J on 9/11
//update to version2.1 by WSX on 9/15

#ifndef BASE_STRUCT
#define BASE_STRUCT

#include<stdio.h>
struct record {									//诊疗记录
	int num_check;                              //挂号
	patient pat;								//患者信息
	doctor doc;									//医生信息
    char out_doc[12];							//出诊时间
	treat tre;									//诊疗情况
	record* next = NULL;					    //链表实现
};

struct patient {								//患者信息结构体
	char name_pat[5];						    //患者姓名
	int age;									//年龄	
	int tag_pat;                                //身份识别码(编码规则待定)
	patient* next = NULL;				        //链表实现
};

struct doctor {									//医生信息结构体
	char name_doc[30];					        //医生姓名
	char level[5];							    //医生级别
	char sub[10];							    //医生科室
	int num_work;								//医生工号
	doctor* next = NULL;                        //链表实现
};

struct treat {									//诊疗情况
    check che;									//检查情况
	pill pil;									//开药情况
	hospital hos;								//住院信息
};

struct check {									//检查结构体
	int tag_check;                              //检查总项目数
	char type[50][10];                          //检查类型
	float cost_term[50];					    //单项检查费用
	float cost_check;							//总检查费用（函数计算）
};

struct pill {									//药品结构体
	int tag_pill;                               //药品总项目数
	char name_pill[30][30];				        //药品名称
	int cost_perpill[30];                       //单价
	int num_pill[30];                           //数量
	float cost_pill;                              //药品总价
};

struct hospital {								//住院信息结构体
	int time_start;							    //住院开始时间
	int time_end;							    //预计住院结束时间
	int days_hos;								//住院天数（函数计算）
	int cost_hos;								//住院费用（函数计算）
    int deposit;                                //住院押金
};

#endif

//modified by Nero J on 9/15 test test