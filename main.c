#include<avr/io.h>
#include<stdlib.h>
#include<util/delay.h>
#include"MCAL/DIO/DIO.h"
#include"bit_math.h"
#include"MCAL/ADC/ADC.h"
#include"MCAL/external_interrupt/extint.h"
#include "MCAL/TIMER0/TIMER0.h"
#include"HAL/LCD/LCD.h"
#include"STD_Types.h"
#define f_cpu 16000000UL

void timer1_init(void)
{
	SET_BIT(TCCR1A,COM1B1); // Clear OC1A/OC1B on compare match (Set output to low level)
	SET_BIT(TCCR1A,WGM11); //Fast PWM, 10-bit
	SET_BIT(TCCR1A,WGM10);  //Fast PWM, 10-bit
	SET_BIT(TCCR1B,CS10);  //clkI/O/64 (From prescaler)
	SET_BIT(TCCR1B,CS11);  //clkI/O/64 (From prescaler)
	SET_BIT(TCCR1B,WGM12);   //Fast PWM, 10-bit
	SET_BIT(TIMSK,TICIE1); // enable the icp interrupt
}

int main()
{
	unsigned int a,b,c,high,period,i;
	uint8_t frequency[14],duty_cy[7];
	TMR0_init();
	init_INT0();
	SET_BIT(SREG,7);  //SEI();
	DIO_init();
	lcd_init();
	ADC_init();
	init_INT0();
	timer1_init();
	PORTD = 0xFF;      /* Turn ON pull-up resistor */

	while(1)
	{
		for(i=0;i<ADC_read(1);i++)
			{
			OCR1B=TMR0_Set_OCR(i/(4.015));   //putting the value of the adc in timer 0 to generate pwm
					_delay_ms(500);
		    }
				i=0;
				TCNT1=0;
			    CLR_BIT(TIFR,ICF1);  	/* Clear ICF (Input Capture flag) flag */
				TCCR1B = 0x41;  	/* Rising edge, no prescaler */
				while (GET_BIT(TIFR,ICF1)== 0);
				a = ICR1;  		/* Take value of capture register */
				TIFR = (1<<ICF1);  	/* Clear ICF flag */

				TCCR1B = 0x01;  	/* Falling edge, no prescaler */
				while (GET_BIT(TIFR,ICF1) == 0);
				b = ICR1;  		/* Take value of capture register */
				CLR_BIT(TIFR,ICF1); ;  	/* Clear ICF flag */

				TCCR1B = 0x41;  	/* Rising edge, no prescaler */
				while (GET_BIT(TIFR,ICF1) == 0);
				c = ICR1;  		/* Take value of capture register */
				CLR_BIT(TIFR,ICF1);   	/* Clear ICF flag */

				TCCR1B = 0;  		/* Stop the timer */

				if(a<b && b<c)  	/* Check for valid condition,
							to avoid timer overflow reading */
				{
					high=b-a;
					period=c-a;

					long freq= f_cpu/period;/* Calculate frequency */

								/* Calculate duty cycle */
		            		float duty_cycle =((float) high /(float)period)*100;
					ltoa(freq,frequency,10);

					itoa((int)duty_cycle,duty_cy,10);

					lcd_sendcmd(0x80);
					lcd_sendstring("Freq: ");
					lcd_sendstring(frequency);
					lcd_sendstring(" Hz    ");

					lcd_sendcmd(0xC0);
					lcd_sendstring("Duty: ");
					lcd_sendstring(duty_cy);
					lcd_sendstring(" %      ");


				}

				else
				{
					lcd_sendstring("OUT OF RANGE!!");
				}
				_delay_ms(50);
			}

	return 0;
		}
// https://lucid.app/lucidchart/f1334649-b80f-4239-bfd0-f5e74d7afd82/edit?invitationId=inv_ecbf142a-799c-4718-ab49-82b4c6bdee19




