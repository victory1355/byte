#ifndef __BUZZER_H__
#define __BUZZER_H__

//#include <REGX52.H>

/*����������˵��*/
sbit BZ = P2^0;

void init_buzzer();
void buzzer();


#endif