#ifndef  __MOTO_H__
#define  __MOTO_H__

#include <REGX52.H>

/*L298驱动电路引脚说明*/
sbit IN1 = P1^1;
sbit IN2 = P1^2;
sbit ENA = P1^3;

void moto();
void init_moto();

#endif