#include"GLCD.h"

int i;




void glcd_cmd(unsigned char cmd) //subroutine for command
 {
	   PORTC=cmd;

	SET_BIT(PORTD,0); // Enable GLCD
   _delay_ms(2);

   CLR_BIT(PORTD,2); // To create an instruction
   CLR_BIT(PORTD,1); // To write instruction
   _delay_ms(2);
 }

void glcd_data(unsigned char dat)  //subroutine for data
 {
	  PORTC=dat;

   _delay_ms(2);
   SET_BIT(PORTD,0);
  SET_BIT(PORTD,2);
  CLR_BIT(PORTD,1);
   _delay_ms(2);
   CLR_BIT(PORTD,0);
 }

void glcd_init()                //subroutine for initialaization
{
  unsigned char command[4]={0x10,0xb8,0x40,0x3f};
  select_chip(1);                      //Chip selection
  for(i=0;i<4;i++)
  glcd_cmd(command[i]);
  select_chip(0);
  for(i=0;i<4;i++)
   glcd_cmd(command[i]);
 }

void select_chip(int chip)    //Chip selection
 {
  if(chip==1)
   {
      PORTD|=(1<<4);
      PORTD&=~(1<<3);
   }
  else
   {
      PORTD&=~(1<<4);
      PORTD|=(1<<3);
   }
}

void glcd_picture(const unsigned char *ip)  //Subroutine for printing
 {
   int page,column;
    for(page=0;page<8;page++)
{
  select_chip(0);
  glcd_cmd(0xb8|page);
  glcd_cmd(0x40);
    for(column=0;column<128;column++)
     {
if(column==64)
{
 select_chip(1);
 glcd_cmd(0xb8|page);
 glcd_cmd(0x40);
}
glcd_data(*ip++);    //acessing array values using pointers
    }
       }
  }
