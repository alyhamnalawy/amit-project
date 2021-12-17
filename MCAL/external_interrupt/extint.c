/*
 * extint.c
 *
 *  Created on: Oct 1, 2021
 *      Author: Ali Ehab
 */

#include "../external_interrupt/extint.h"
void(*p2f_INT0)(void);
void(*p2f_INT1)(void);
void(*p2f_INT2)(void);

void init_INT0()
{
	SET_BIT(GICR,INT0);

	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
}
ISR(INT0_vect)
{
	p2f_INT0();
}
ISR(INT1_vect)
{
	p2f_INT1();
}
ISR(INT2_vect)
{
	p2f_INT2();
}

void setcallback_INT0(void(*p2func)(void))
{
	p2f_INT0=p2func;
}
void setcallback_INT1(void(*p2func)(void))
{
	p2f_INT1=p2func;
}
void setcallback_INT2(void(*p2func)(void))
{
	p2f_INT2=p2func;
}







