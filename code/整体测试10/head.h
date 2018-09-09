#ifndef  __HEAD_H__
#define  __HEAD_H__

#include <REGX52.H>


/*L298驱动电路引脚说明*/
sbit IN1 = P1^1;
sbit IN2 = P1^2;
sbit ENA = P1^3;
sbit GND_L298 = P1^4;

/*蜂鸣器引脚说明*/		   
sbit BZ = P2^0;

void moto();
void init_moto();
void Init_serial();
void init_buzzer();
void buzzer();
void delay_1us(unsigned int time);
void delay_100us(unsigned int time);

#endif