/*ÑÓÊ±1ms*/
/*void delay_1us(unsigned int time)
{
	while(--time);
}*/

/*ÑÓÊ±100us*/
void delay_100us(unsigned int time)
{
	unsigned int x,y;
	for(x=time; x>0; x--)
		for(y=110; y>0; y--);
}