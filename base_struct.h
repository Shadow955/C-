//base_struct.h version2.0 designed by Nero J on 9/11
//update to version2.1 by WSX on 9/15

#ifndef BASE_STRUCT
#define BASE_STRUCT

#include<stdio.h>
struct record {									//���Ƽ�¼
	int num_check;                              //�Һ�
	patient pat;								//������Ϣ
	doctor doc;									//ҽ����Ϣ
    char out_doc[15];							//����ʱ��
	treat tre;									//�������
	record* next = NULL;					    //����ʵ��
};

struct patient {								//������Ϣ�ṹ��
	char name_pat[30];						    //��������
	int age;									//����	
	int tag_pat;                                //����ʶ����(����������)
	patient* next = NULL;				        //����ʵ��
};

struct doctor {									//ҽ����Ϣ�ṹ��
	char name_doc[30];					        //ҽ������
	char level[30];							    //ҽ������
	char sub[30];							    //ҽ������
	int num_work;								//ҽ������	
	doctor* next = NULL;                        //����ʵ��
};

struct treat {									//�������
    check che;									//������
	pill pil;									//��ҩ���
	hospital hos;								//סԺ��Ϣ
};

struct check {									//���ṹ��
	int tag_check;                              //�������Ŀ��
	char type[50][10];                          //�������
	float cost_term[50];					    //���������
	float cost_check;							//�ܼ����ã��������㣩
};

struct pill {									//ҩƷ�ṹ��
	int tag_pill;                               //ҩƷ����Ŀ��
	char name_pill[30][30];				        //ҩƷ����
	int cost_perpill[30];                       //����
	int num_pill[30];                           //����
	float cost_pill;                              //ҩƷ�ܼ�
};

struct hospital {								//סԺ��Ϣ�ṹ��
	int time_start;							    //סԺ��ʼʱ��
	int time_end;							    //Ԥ��סԺ����ʱ��
	int days_hos;								//סԺ�������������㣩
	int cost_hos;								//סԺ���ã��������㣩
    int deposit;                                //סԺѺ��
};

#endif

//modified by Nero J on 9/15