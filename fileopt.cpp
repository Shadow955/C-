//modified by Nero on 9/29
#include<stdlib.h>
#include<stdio.h>
#include"base_struct.h"
#include<string.h>
#include"fileopt.h"
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
void read_and_link() {


	/***********************************************************

	ע�⣺��ʽ������ʱ���Ƿ���Ҫ���˻س����д���һ������

	************************************************************/


	rec_head = (record*)malloc(sizeof(record));		//����ͷ�ڵ�
	rec_head->next = NULL;
	record* rec_this = rec_head;								//������ǰ�ڵ�
	record* rec_temp = (record*)malloc(sizeof(record));//Ĭ�Ͻ����½ڵ�
	while (1)																//ѭ������ֱ���ļ�ĩβ
	{
		if (fscanf(infile, "%ld %s %d %d"					//����Һż�������Ϣ����
			, &(rec_temp->num_check)
			, (rec_temp->pat.name_pat)
			, &(rec_temp->pat.age)
			, &(rec_temp->pat.tag_pat)) == EOF)
		{
			free(rec_temp);											//���ļ�������ɾ��������½ڵ�
			break;
		}
		else
		{
			fscanf(infile, "%s %s %s %ld"						//����ҽ����Ϣ����
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
		}
	}
	rec_temp->next = NULL;											//׼�������½ڵ�
	rec_this->next = rec_temp;
	rec_this = rec_temp;
	fclose(infile);
	/****************************************

	���������Ƿ������ر��ļ����д�̽��

	***************************************/
}