/*
    Author:ղѧ��
	Date:  2018/1/28

	��Ʒ������GPS���������������ܵ�����
	������ͨ���ֻ�APP����������������ͨ�ţ�ʵ�ֿ�������

	Ӳ������˵����
	(STC89C52)P2^0 <------> I/O(������)
	          P1^3 <------> ENA(L298)
			  P1^2 <------> IN2(L298)
			  P1^1 <------> IN1(L298)

	(GPS-U-blox)TXD <-------> RXD(HC-05����ģ��)							 
    (STC89C52)  RXD <-------> TXD(HC-05����ģ��)

	���幦��������ͨ���ֻ�APP����ָ��'o'��MCU���յ�ָ������������п���

*/
 
#include "head.h"

/*������־*/
unsigned char flag_lock;

/*�������߼�*/
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


/*�����ж���Ӧ*/
void open_lock() interrupt  4
{
     unsigned char recieve_data;

     recieve_data = SBUF;
     if(recieve_data == 'o')
   		flag_lock = 1;
	 //if(recieve_data == 'c')
	 	//flag_lock = 0;

	 RI = 0;        //�ֶ�����	
}

