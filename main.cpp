#define funds = 0;
#include<stdio.h>
#include<stdlib.h>
#include"base_struct.h"
#include"fileopt.h"
#include"allfunc.h"

void printf_number() {
	int number1;//�������������
	printf("�����빦�ܶ�Ӧ�����֣�\n1:��ӡĳ����������Ϣ\n2:��ӡĳҽ��������Ϣ\n3:��ӡĳ������ʷ���Ƽ�¼\n4:��ӡĳ��ʱ���ڵ����Ƽ�¼");
	scanf("%d", &number1);
	switch (number1) {
	case 1: void printf_sub(int); break;//��ӡĳ����������Ϣ
	case 2: void printf_doctor(int); break;//��ӡĳҽ��������Ϣ
	case 3: void printf_patient(struct patient); break;//��ӡĳ������ʷ���Ƽ�¼
	case 4: void printf_record_time(); break;//��ӡĳ��ʱ���ڵ����Ƽ�¼
	}
}

int main() {
	if (!openfile())									//��ʼʱ��ִ���ļ����뺯�����ݶ��Բ��������ж�
		return 0;

	read_and_link();								//����Դ�ļ������е��������Ƽ�¼������һ������

	/***************************
	****�˴�ӦΪ�����沿��****
	***************************/
	int number;//�������������
	printf("������Ҫִ�й��ܶ�Ӧ�����֣�\n1:¼�����Ƽ�¼\n2:�޸����Ƽ�¼\n3:ɾ�����Ƽ�¼\n4:��ӡ��Ϣ\n5:ͳ��Ӫҵ�����סԺ���߱���\n6:ͳ��ҽ���ĳ�������͹�����æ�̶�\n7:���浱ǰϵͳ�е�������Ϣ\n");//������ֶ�Ӧ����
	scanf("%d", &number);
	switch (number) {
		case 1: struct record add_record(struct record); break;//¼�����Ƽ�¼
		case 2: struct record alter_record(int); break;//�޸����Ƽ�¼
		case 3: void delete_record(int); break;//ɾ�����Ƽ�¼
		case 4: printf_number(); break;//ȷ�ϴ�ӡ��Ϣ
		case 5: float espence(); break;//ͳ��Ӫҵ��
		case 6: void printf_doctor_condition(); break;//ͳ��ҽ���ĳ�������͹�����æ�̶�
		case 7: void save(); break;//���浱ǰϵͳ�������Ϣ
	}
}

