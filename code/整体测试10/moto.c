
#include "head.h"

/*初始化电机状态*/
void init_moto()
{
    GND_L298 = 0;
	ENA = 0;
}
void moto()
{
     unsigned int i;
	 /*正转*/
	 IN1 = 1;
	 IN2 = 0;
	 for(i=15; i>0; i--)
	 {
	 	delay_100us(50);
	 	ENA = ~ENA;
	 }
	 /*反转*/
	 IN1 = 0;
	 IN2 = 1;
	 for(i=15; i>0; i--)
	 {
	 	delay_100us(50);
	 	ENA = ~ENA;
	 }
	 //停止转动
	 ENA = 0;
	 IN1 = 0;
     IN2 = 0;
}