
#include "head.h"

/*ѡ��ͬ�ķ�������Ĭ������Դ���������͵�ƽ��Ч*/
//#define DIANYA_BZ 1

void init_buzzer()
{
#ifdef DIANYA_BZ    //��ѹ��������DC3-24V
	BZ = 0;          
#else
    BZ = 1;		   //��Դ���������͵�ƽ��Ч
#endif

}
void buzzer()
{
#ifdef DIANYA_BZ
	BZ = 1;
	delay_100us(900);
	BZ = 0;
#else
	BZ = 0;
	delay_100us(900);
	BZ = 1;
#endif
}