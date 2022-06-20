/*
 * Dio.c
 *
 * Created: 9/21/2020 1:24:59 AM
 *  Author: Ashraf Amgad
 */ 

#include <avr/io.h>
#include "../utils/std_types.h"
#include "../utils/utils.h"


void Dio_Init(void)
{
	DDRA = 0b00000000;
	DDRB = 0b00001000;
	DDRC = 0b11111111;
	DDRD = 0b11110011;
	
	PORTA = 0b00000000;
	PORTB = 0b00000000;
	PORTC = 0b00000000;
	PORTD = 0b00000000;

}
