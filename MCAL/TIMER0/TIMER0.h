/*
 * TIMER0.h
 *
 *  Created on: Oct 8, 2021
 *      Author: HP
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#include"TIMER0_Config.h"
#include"../../Bit_Math.h"
#include<util/delay.h>
#include<avr/io.h>
#include <avr/interrupt.h>

void TMR0_init();
void TMR0_Set_OCR(unsigned char DutyCycle);
void SetCallBack_TMR0_OV(void(*p2fOV)(void));
void SetCallBack_TMR0_COMP(void(*p2fCOMP)(void));

#endif /* MCAL_TIMER0_TIMER0_H_ */
