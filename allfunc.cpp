#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include"base_struct.h"
#include"allfunc.h"

float sumcheck(int tag_check,float cost_term[])              //�������ܷ��ú���
{
	int i ;
	float sum = 0;
	for (i = 0; i < tag_check; i++)
	{
		sum = sum + cost_term[i];
	}
	return sum;
}

float sumpill(int tag_pill, int cost_perpill[30], int num_pill[30])        //����ҩƷ�ܷ��ú���
{
	int i, j, sum;
	sum = 0;
	j = tag_pill;
	for (i = 0; i < j; i++)
	{
		sum = sum + ((cost_perpill[i]) * (num_pill[i]));
	}
	return (float)sum;
}

int date_turn(char a[8])                 //��8λ����ת��Ϊ����
{
	int i, mon, day, tag;
	mon = (int)((a[0] * 10) + a[1]);
	day = (int)((a[2] * 10) + a[3]);
	switch (mon)
	{
	case 1:tag = day;
	case 2:tag = day + 31;
	case 3:tag = day + 59;
	case 4:tag = day + 90;
	case 5:tag = day + 120;
	case 6:tag = day + 151;
	case 7:tag = day + 181;
	case 8:tag = day + 212;
	case 9:tag = day + 243;
	case 10:tag = day + 273;
	case 11:tag = day + 304;
	case 12:tag = day + 334;
	}
	return tag;
}

int days_hosp(int time_start, int time_end)                  //����סԺʱ������
{
	char ch1[8], ch2[8];
	char x, y;
	int durtime;
	sprintf(ch1, "%d", time_start);
	sprintf(ch2, "%d", time_end);
	x = date_turn(ch1);
	y = date_turn(ch2);
	durtime = (((int)x) - ((int)y));
	return durtime;
}

int cost_hos(int a,int b,int c)           //סԺ���ú���
{
	int sum = 0;
	sum = sum + a + b + (c * 100);
	return sum;
}

void getrecord(struct record* head)
{
	record* temp = (record*)malloc(sizeof(record));
	temp->next = NULL;
	record* p, * q;
	p = head; q = p->next;
	while (q != NULL)
	{
		q = q->next;
	}
	if (q == NULL)
	{
		printf("�����뻼����Ϣ\n");
		q = temp;
		scanf("%s %d", &(q->pat.name_pat), &(q->pat.age));
		printf("������Һ�\n");
		scanf("%d", q->num_check);
		printf("������ҽ����Ϣ\n");
		scanf("%s%s%s%d",&(q->doc.name_doc) , &(q->doc.level), &(q->doc.sub), &(q->doc.num_work));
		printf("���������ʱ��\n");
		scanf("%s", &(q->out_doc[12]));
		printf("����������鼰�����,�������������롮|��\n");
		(q->tre.che.tag_check) = 0; bool flag_che = true; int i = 0;
		while(flag_che)
		{
			scanf("%s", &(q->tre.che.type[i]));
			if ((q->tre.che.type[i][0]) == '|')
			{
				flag_che = false;
				(q->tre.che.cost_check) = sumcheck((q->tre.che.tag_check), (q->tre.che.cost_term));
				break;
			}
			scanf("%d", &(q->tre.che.cost_term[i]));
			(q->tre.che.tag_check)++;
		}
		printf("�������ҩƷ���Ƽ��������͵���,�������������롮|��\n");
		(q->tre.pil.tag_pill) = 0; bool flag_pil = true; i = 0;
		while (flag_pil)
		{
			scanf("%s", &(q->tre.pil.name_pill[i]));
			if ((q->tre.pil.name_pill[i][0]) == '|')
			{
				flag_pil = false;
				(q->tre.pil.cost_pill) = sumpill(q->tre.pil.tag_pill, q->tre.pil.cost_perpill, q->tre.pil.num_pill);
				break;
			}
			scanf("%d&d", &(q->tre.pil.cost_perpill[i]), &(q->tre.pil.num_pill[i]));
			(q->tre.pil.tag_pill)++;
		}
		printf("�����뿪ʼסԺʱ�䣬Ԥ�Ƴ�Ժʱ�估�ѽ��ɵ�סԺѺ��\n");
		scanf("%d%d%d", &(q->tre.hos.time_start), &(q->tre.hos.time_end), &(q->tre.hos.deposit));
		(q->tre.hos.days_hos) = days_hosp(q->tre.hos.time_start, q->tre.hos.time_end);
		free(temp);
	}
	return;
}

void outpatient_tag(struct record* head, int tag_in)   //���ݻ��������Ϣ�������
{
	record* p, * q;
	p = head; q = head->next;
	for (((p->pat).tag_pat) == tag_in; q != NULL;)
	{
		printf("%s %d ", ((p->pat).name_pat), ((p->pat).age));//���������Ϣ����
		printf("%s %s %s %d", ((p->doc).name_doc), ((p->doc).level), ((p->doc).sub), ((p->doc).num_work));//���ҽ����Ϣ����
		printf("%s ", p->out_doc);                         //�������ʱ��
		for (int i = 0; i < (p->tre.che.tag_check); i++)
		{			 
			printf("%s ", p->tre.che.type[i]);       //����������
			printf("%d ", p->tre.che.cost_term[i]);  //���������ķ���
		}
		for (int i = 0; i < (p->tre.pil.tag_pill); i++)
		{
			printf("%s ", p->tre.pil.name_pill[i]);   //���ҩƷ����
			printf("%d ", p->tre.pil.cost_perpill[i]);//���ҩƷ����
			printf("%d ", p->tre.pil.num_pill[i]);    //���ҩƷ����
		}
		printf("%d  %d ", p->tre.hos.time_start, p->tre.hos.time_end);//���ס,��Ժʱ��
		printf("%d %d %d\n", p->tre.hos.days_hos, p->tre.hos.cost_hos, p->tre.hos.deposit);//���סԺ����,סԺ����,סԺѺ��
		p = q; q = q->next;
	}
	return;
}

void outpatient_name(struct record* head, char name[30])		//�����������������
{
	record* p, * q;
	p = head; q = head->next;
	int t, x = 0; t = 0;
	for (strcmp(((p->pat).name_pat) ,name)==1; q != NULL;)
	{
		x = x + 1;
		printf("&d %s %d\n", x, ((p->pat).name_pat), ((p->pat).age));//���������Ϣ����
		p = q; q = q->next;
	}
	if (x == 0)
	{
		printf("���޴���");
	}
	printf("��ѡ����Ҫ��ѯ�Ļ���");
	scanf("%d", &t);
	for (strcmp((p->pat.name_pat), name) == 1; q != NULL; )
	{
		t = t + 1;
		if (x == t) 
		{
			printf("%s %d ", (p->pat.name_pat), (p->pat.age));//���������Ϣ����
			printf("%s %s %s %d", p->doc.name_doc, p->doc.level, p->doc.sub, p->doc.num_work);//���ҽ����Ϣ����
			printf("%s ", p->out_doc);                         //�������ʱ��
			for (int i = 0; i < (p->tre.che.tag_check); i++)
			{
				printf("%s ", p->tre.che.type[i]);       //����������
				printf("%d ", p->tre.che.cost_term[i]);  //���������ķ���
			}
			for (int i = 0; i < (p->tre.pil.tag_pill); i++)
			{
				printf("%s ", p->tre.pil.name_pill[i]);   //���ҩƷ����
				printf("%d ", p->tre.pil.cost_perpill[i]);//���ҩƷ����
				printf("%d ", p->tre.pil.num_pill[i]);    //���ҩƷ����
			}
			printf("%d  %d ", p->tre.hos.time_start, p->tre.hos.time_end);//���ס,��Ժʱ��
			printf("%d %d %d\n", p->tre.hos.days_hos, p->tre.hos.cost_hos, p->tre.hos.deposit);//���סԺ����,סԺ����,סԺѺ��
		}
	}
	return;
}
