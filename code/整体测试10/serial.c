#include "serial.h"
#include <REGX52.H>

/*��Ƭ������*/
void Init_serial()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2

	TH1=0XFD;			//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XFD;
	ES=1;				//�򿪽����ж�
	EA=1;				//�����ж�
	TR1=1;				//�򿪼�����
}