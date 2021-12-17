/*
 * keypad.c
 *
 *  Created on: Sep 25, 2021
 *      Author: Ali Ehab
 */
#include"keypad.h"
//from 0 to 3 rows
//from 4 to 7 col




unsigned char getkeypress(void)
{
	//pullup
	DIO_write(col0,HIGH);
	DIO_write(col1,HIGH);
	DIO_write(col2,HIGH);
	DIO_write(col3,HIGH);


	DIO_write(row0,LOW);
	DIO_write(row1,LOW);
	DIO_write(row2,LOW);
	DIO_write(row3,LOW);

	if(DIO_read(col0) && DIO_read(col1) && DIO_read(col2) && DIO_read(col3))
	{
		return 1;
	}
	return 0;

}
