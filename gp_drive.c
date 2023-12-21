#include "gp_drive.h"

void init_gpio(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt)
{
	volatile unsigned long *CR;
	unsigned short t_Pin =pin;
	unsigned offset = 0x00;
	
	if(pin>7){
		t_Pin -=8;
		offset = 0x01;
	}
	if(port ==1){
		RCC_APB2ENR |= 4;
		CR = (volatile unsigned long*) (&GPIO_A +offset);
	}
	else if(port==2){
		RCC_APB2ENR |= 8;
		CR = (volatile unsigned long*) (&GPIO_B + offset);
	}
	else if(port ==3){
		RCC_APB2ENR |= 0x10;
		CR = (volatile unsigned long*) (&GPIO_C + offset);
	}
	else if(port ==4){
		RCC_APB2ENR |= 0x20;
		CR = (volatile unsigned long*) (&GPIO_D + offset);
	}
	*CR &= ~(0xfu<<(t_Pin)*4);
	*CR |= ((dir <<(t_Pin)*4)|(opt<<(t_Pin*4+2)));		
}
int Read_gp(unsigned short port, unsigned short pin){
	
	volatile unsigned long *IDR;
	unsigned long offset = 0x02;
	int state;
	
  if(port ==1){
		IDR = (volatile unsigned long*) (&GPIO_A +offset);
	}
	if(port ==2){
		IDR = (volatile unsigned long*) (&GPIO_B +offset);
	}
	if(port ==3){
		IDR = (volatile unsigned long*) (&GPIO_C +offset);
	}
	if(port ==4){
		IDR = (volatile unsigned long*) (&GPIO_D +offset);
	}
	state = ((*IDR & (1<<pin))>>pin);
 	return state;	
}
void Write_gp(unsigned short port, unsigned short pin, unsigned state)
{
	volatile unsigned long *ODR;
	unsigned long offset = 0x03;
	
  if(port ==1){
		ODR = (volatile unsigned long*) (&GPIO_A +offset);
	}
 	if(port ==2){
		ODR = (volatile unsigned long*) (&GPIO_B +offset);
	}
	if(port ==3){
		ODR = (volatile unsigned long*) (&GPIO_C +offset);
	}
	if(port ==4){
		ODR = (volatile unsigned long*) (&GPIO_D +offset);
	}
	state ? (*ODR |= (state<<pin)) : (*ODR &= ~(1<<pin));	
}

	

