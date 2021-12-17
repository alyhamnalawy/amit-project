/*
 * keypad.h
 *
 *  Created on: Sep 25, 2021
 *      Author: Ali Ehab
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include "../../bit_math.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../STD_Types.h"


unsigned char getkeypress(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
