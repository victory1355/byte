#include "serial.h"
#include <REGX52.H>

/*单片机串口*/
void Init_serial()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2

	TH1=0XFD;			//计数器初始值设置，注意波特率是4800的
	TL1=0XFD;
	ES=1;				//打开接收中断
	EA=1;				//打开总中断
	TR1=1;				//打开计数器
}