/*
 * DIO.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ali Ehab
 */
#include "DIO.h"


void DIO_write(Channel_Type channel,State_Type state)
{
	if(channel>=0&&channel<=7)
	{
		if(state==1)
		{
			SET_BIT(PORTA,channel);
		}
		else
		{
			CLR_BIT(PORTA,channel);
		}
	}
	else if(channel>=8&&channel<=15)
		{
			if(state==1)
			{
				SET_BIT(PORTB,(channel-8));
			}
			else
			{
				CLR_BIT(PORTB,(channel-8));
			}
		}
	else if(channel>=16&&channel<=23)
			{
				if(state==1)
				{
					SET_BIT(PORTC,(channel-16));
				}
				else
				{
					CLR_BIT(PORTC,(channel-16));
				}
			}
	else if(channel>=24&&channel<=31)
			{
				if(state==1)
				{
					SET_BIT(PORTD,(channel-24));
				}
				else
				{
					CLR_BIT(PORTD,(channel-24));
				}
			}
}

int DIO_read(Channel_Type channel)
{
	State_Type state =0;
	if(channel>=0&&channel<=7)
	{
		state=GET_BIT(PINA,channel);

	}
	else if(channel>=8&&channel<=15)
	{
		state=GET_BIT(PINB,(channel-8));

	}
	else if(channel>=16&&channel<=23)
	{
			state=GET_BIT(PINC,(channel-16));
	}
	else if(channel>=24&&channel<=31)
	{
			state=GET_BIT(PIND,(channel-24));

	}
	return state;
}






