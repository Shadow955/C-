//modified by Nero on 9/29
#include<stdlib.h>
#include<stdio.h>
#include"base_struct.h"
#include<string.h>
#include"fileopt.h"
#include"allfunc.h"
struct record* rec_head;
FILE* infile;																//Դ�ļ�Ϊinfile�����ĺ������ļ�Ϊoutfile
FILE* outfile;
/*********************************

���飺�Ƿ���Դ�ļ���ֱ�Ӳ�����
			  �д����۽��

*********************************/
int openfile() {															//�ļ����뺯��
	infile = fopen("test.txt", "a");							//��ȡ�ļ����ж��Ƿ�ɹ���
	if (infile == NULL)
	{
		printf("�ļ���ʧ�ܣ�����Դ�ļ���\n");		//��ʧ�ܽ����������ϲ�
		return 0;
	}
	else
		printf("�ļ��򿪳ɹ���\n");
}
record* read_and_link() 
{


	/***********************************************************

	ע�⣺��ʽ������ʱ���Ƿ���Ҫ���˻س����д���һ������

	************************************************************/


	rec_head = (record*)malloc(sizeof(record));		//����ͷ�ڵ�
	//rec_head->next = NULL;
	//record* rec_this = rec_head;								//������ǰ�ڵ�
	//record* rec_temp;
	record* rec_temp = (record*)malloc(sizeof(record));//Ĭ�Ͻ����½ڵ�
	rec_head->next = rec_temp;
	while (!EOF)																//ѭ������ֱ���ļ�ĩβ
	{
		//rec_temp = (record*)malloc(sizeof(record));//Ĭ�Ͻ����½ڵ�
		fscanf(infile, "%d %s %d %d", &rec_temp->num_check, rec_temp->pat.name_pat, &rec_temp->pat.age, &rec_temp->pat.tag_pat);
			fscanf(infile, "%s %s %s %d"						//����ҽ����Ϣ����
				, (rec_temp->doc.name_doc)
				, (rec_temp->doc.level)
				, (rec_temp->doc.sub)
				, &(rec_temp->doc.num_work));
			fscanf(infile, "%s", rec_temp->out_doc);
			//fscanf(infile, "%s", rec_temp->tre.che.type[0]);
			int i = 0, j = 0;
			while (strcmp("over", rec_temp->tre.che.type[i]) != 0)//�ڶ���over֮ǰ��ѭ����������Ŀ���������
			{
				fscanf(infile, "%f", rec_temp->tre.che.cost_term);
				i++;
			}
			while (strcmp("over", rec_temp->tre.pil.name_pill[j]) != 0)//�ڶ���over֮ǰ��ѭ������ҩƷ����������
			{
				fscanf(infile, "%s %d %d"
					, rec_temp->tre.pil.name_pill[j]
					, &(rec_temp->tre.pil.cost_perpill[j])
					, &(rec_temp->tre.pil.num_pill[j]));
				j++;
			}
			fscanf(infile, "%d %d %d"									//����סԺ��Ϣ����
				, &(rec_temp->tre.hos.time_start)
				, &(rec_temp->tre.hos.time_end)
				, &rec_temp->tre.hos.deposit);
		
		rec_temp->next = (record*)malloc(sizeof(record));
		rec_temp = rec_temp->next;
	}
	//if (rec_head->next == NULL)
	//	rec_head = rec_temp;
	//rec_temp->next = NULL;											//׼�������½ڵ�
	//rec_this->next = rec_temp;
	//rec_this = rec_temp;
	fclose(infile);
	printf("�������ɹ���");
	return rec_head->next;
	/****************************************

	���������Ƿ������ر��ļ����д�̽��

	***************************************/
}
void printf_number() {
	int number1;//�������������
	printf("�����빦�ܶ�Ӧ�����֣�\n1:��ӡĳ����������Ϣ\n2:��ӡĳҽ��������Ϣ\n3:��ӡĳ������ʷ���Ƽ�¼\n4:��ӡĳ��ʱ���ڵ����Ƽ�¼");
	scanf("%d", &number1);
	switch (number1) {
	case 1: void outsub_doc(struct record* head); break;//��ӡĳ����������Ϣ
	case 2: void outname_doc(struct record* head); break;//��ӡĳҽ��������Ϣ
	case 3: outpatient_name(rec_head); break;//��ӡĳ������ʷ���Ƽ�¼
	case 4: void outtime_limit(struct record* head); break;//��ӡĳ��ʱ���ڵ����Ƽ�¼
	}
}