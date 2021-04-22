/*
 * File:   main.c
 * Author: 19179166
 *
 * Created on 16 de Abril de 2021, 16:34
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000
#define DADOS  PORTB
#define EN     PORTDbits.RD7
#define RS     PORTDbits.RD6    // escreve informacao ou comando 1 0

void LCD_init  (void)
{
   
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    ANSELH = 0;
    TRISB = 0X00;
    
    DADOS = 0x00;
    EN = 1;
    RS = 0; 
}

void LCD_on (void)
{
    RS = 0;     // comando
    EN = 1;     // enable 
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_printChar (char c)
{
    RS = 1;     // informacao
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void LCD_print (char * str)         //laco na memoria 
{
    char i = 0;                         // INDICE VALOR(posicao na memoria) STRING
    
    while ( *(str+i) != 0 )             // ENQUANTO ST... NAO FOR 0 LCDprintchar
    {
        LCD_printChar( *(str+i) );      // pega valor da string e printa 
        ++i;
    }
}

void main(void) 
{
   
  
    LCD_init();
    LCD_on();
    LCD_print( "brks" );
    
  
    while(1)
    {
        
    }
   
}

