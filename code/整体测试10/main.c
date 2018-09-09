/*
    Author:詹学桂
	Date:  2018/1/28

	产品：基于GPS和蓝牙技术的智能单车锁
	描述：通过手机APP于智能锁蓝牙进行通信，实现开锁功能

	硬件连接说明：
	(STC89C52)P2^0 <------> I/O(蜂鸣器)
	          P1^3 <------> ENA(L298)
			  P1^2 <------> IN2(L298)
			  P1^1 <------> IN1(L298)

	(GPS-U-blox)TXD <-------> RXD(HC-05蓝牙模块)							 
    (STC89C52)  RXD <-------> TXD(HC-05蓝牙模块)

	具体功能描述：通过手机APP发送指令'o'，MCU接收到指令驱动电机进行开锁

*/
 
#include "head.h"

/*开锁标志*/
unsigned char flag_lock;

/*主控制逻辑*/
void main()
{
	 init_moto();
	 init_buzzer();
	 Init_serial();

	 flag_lock = 0;
	 while(1)
	 {
		  if(flag_lock == 1)
		  {
		     EA = 0;

		  	 buzzer();
		  	 moto();

			 EA = 1;
			 flag_lock = 0;	 
		  }	  	
	 }
	 
}


/*串口中断响应*/
void open_lock() interrupt  4
{
     unsigned char recieve_data;

     recieve_data = SBUF;
     if(recieve_data == 'o')
   		flag_lock = 1;
	 //if(recieve_data == 'c')
	 	//flag_lock = 0;

	 RI = 0;        //手动置零	
}

