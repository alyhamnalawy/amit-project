/*
 * extint.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Ali Ehab
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTINT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTINT_H_

#include "../DIO/DIO.h"
#include <avr/interrupt.h>
void init_INT0();
void setcallback_INT0(void(*p2func)(void));
void setcallback_INT1(void(*p2func)(void));
void setcallback_INT2(void(*p2func)(void));


#endif /* MCAL_EXTERNAL_INTERRUPT_EXTINT_H_ */
