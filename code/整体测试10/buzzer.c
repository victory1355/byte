
#include "head.h"

/*选择不同的蜂鸣器，默认是有源蜂鸣器，低电平有效*/
//#define DIANYA_BZ 1

void init_buzzer()
{
#ifdef DIANYA_BZ    //电压蜂鸣器，DC3-24V
	BZ = 0;          
#else
    BZ = 1;		   //有源蜂鸣器，低电平有效
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