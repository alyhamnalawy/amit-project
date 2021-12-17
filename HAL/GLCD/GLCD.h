/*
 * GLCD.h
 *
 *  Created on: Dec 1, 2021
 *      Author: Ali Ehab
 */

#ifndef HAL_GLCD_GLCD_H_
#define HAL_GLCD_GLCD_H_

#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include delay header file */
#include <stdio.h>			/* Include std i/o library file */
#include"../../Bit_Math.h"
#include <avr/interrupt.h>


void glcd_picture(const unsigned char *);
void select_chip(int);
void glcd_init();
void glcd_data(unsigned char);
void glcd_cmd(unsigned char);



#endif /* HAL_GLCD_GLCD_H_ */
