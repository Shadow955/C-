#pragma once

float sumcheck(int tag_check, float cost_term[]);

float sumpill(int tag_pill, int cost_perpill[30], int num_pill[30]);        //����ҩƷ�ܷ��ú���

int date_turn(char a[8]);                 //��8λ����ת��Ϊ����

int days_hosp(int time_start, int time_end);                  //����סԺʱ������

int cost_hos(int a, int b, int c);          //סԺ���ú���

void getrecord(struct record* head);

void outpatient_tag(struct record* head, int tag_in);  //���ݻ��������Ϣ�������

void outpatient_name(struct record* head, char name[30]);		//�����������������
