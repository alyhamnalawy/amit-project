/*
 * steppermotor.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Ali Ehab
 */
#include "steppermotor.h"
void steppermotor(void)
{
	DIO_write(stepper_org_1,HIGH);
	DIO_write(stepper_yel_2,LOW);
	DIO_write(stepper_pink_3,LOW);
	DIO_write(stepper_blu_4,LOW);

	_delay_us(100);

	DIO_write(stepper_org_1,LOW);
	DIO_write(stepper_yel_2,HIGH);
	DIO_write(stepper_pink_3,LOW);
	DIO_write(stepper_blu_4,LOW);

	_delay_us(100);

	DIO_write(stepper_org_1,LOW);
	DIO_write(stepper_yel_2,LOW);
	DIO_write(stepper_pink_3,HIGH);
	DIO_write(stepper_blu_4,LOW);

	_delay_us(100);

	DIO_write(stepper_org_1,LOW);
	DIO_write(stepper_yel_2,LOW);
	DIO_write(stepper_pink_3,LOW);
	DIO_write(stepper_blu_4,HIGH);

	_delay_us(100);

}

