
#include "head.h"

/*��ʼ�����״̬*/
void init_moto()
{
    GND_L298 = 0;
	ENA = 0;
}
void moto()
{
     unsigned int i;
	 /*��ת*/
	 IN1 = 1;
	 IN2 = 0;
	 for(i=15; i>0; i--)
	 {
	 	delay_100us(50);
	 	ENA = ~ENA;
	 }
	 /*��ת*/
	 IN1 = 0;
	 IN2 = 1;
	 for(i=15; i>0; i--)
	 {
	 	delay_100us(50);
	 	ENA = ~ENA;
	 }
	 //ֹͣת��
	 ENA = 0;
	 IN1 = 0;
     IN2 = 0;
}