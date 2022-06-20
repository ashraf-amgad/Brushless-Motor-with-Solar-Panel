/*
 * adc.c
 *
 * Created: 9/20/2020 10:37:25 PM
 *  Author: Ashraf Amgad
 */ 

#include <avr/io.h>
#include "Dio/Dio.h"
#include "adc/adc.h"
#include "ExtInt/ExtInt.h"
#include "pwm/timer.h"



#define Automatic_State				2
#define Manual_State				3
volatile u8 Status_Automatic_Manual = Manual_State;



#define Speed_1_State				5
#define Speed_2_State				6
#define Speed_3_State				7
#define Speed_4_State				8
#define Speed_0_State				9
volatile u8 Status_Speed = Speed_0_State;



volatile f32 temp_adc;

void adc_Int(void)
{
	
	temp_adc = ADC_u16GetData();
	temp_adc = (temp_adc * 5)/1024;
	
	if(temp_adc < 2.5)
	{
		PORTC = 0xff;
		//Pwm_SetDutyCycle(TIMER_0 , 50);
	}
	
	else
	{
		PORTC = 0x00;
		//Pwm_SetDutyCycle(TIMER_0 , 100);
	}		
		
	ADC_voidStartConv();
		
}


#define LEDS_PORT	PORTD
#define LED_SPEED_1		(1<<1)
#define LED_SPEED_2		(1<<4)
#define LED_SPEED_3		(1<<5)
#define LED_SPEED_4		(1<<6)
#define LED_AUTOMATIC	(1<<0)


void swtich_Auto_Int0(void)
{
	//PORTD |= 0x01; 
	switch (Status_Automatic_Manual)
	{
		case Automatic_State:
			LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_2 | LED_SPEED_3 | LED_SPEED_4 | LED_AUTOMATIC);
			Status_Automatic_Manual = Manual_State;
			break;
			
			
		case Manual_State:
			LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_2 | LED_SPEED_3 | LED_SPEED_4);
			LEDS_PORT |= (LED_AUTOMATIC);
			Status_Automatic_Manual = Automatic_State;
			break;
	}
	
}

void swtich_Speed_Int1(void)
{
	//PORTD &= ~(0x01);
	if(Status_Automatic_Manual == Manual_State)
	{
		switch (Status_Speed)
		{
			case Speed_1_State:
				LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_3 | LED_SPEED_4);
				LEDS_PORT |= (LED_SPEED_2);
				Status_Speed = Speed_2_State;
				break;
			
			
			case Speed_2_State:	
				LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_2 | LED_SPEED_4);
				LEDS_PORT |= (LED_SPEED_3);
				Status_Speed = Speed_3_State;
				break;
			
			case Speed_3_State:
				LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_2 | LED_SPEED_3);
				LEDS_PORT |= (LED_SPEED_4);
				Status_Speed = Speed_4_State;
				break;	
	
			case Speed_4_State:
				LEDS_PORT &= ~(LED_SPEED_1 | LED_SPEED_2 | LED_SPEED_3 | LED_SPEED_4);
				Status_Speed = Speed_0_State;
				break;
			
			case Speed_0_State:
				LEDS_PORT &= ~(LED_SPEED_4 | LED_SPEED_2 | LED_SPEED_3);
				LEDS_PORT |= (LED_SPEED_1);
				Status_Speed = Speed_1_State;
				break;
		}
		
	}	
	
}


int main(void)
{
	volatile float lm35_reading = 0;
	
	
	Dio_Init();
	ExtInt_voidInit();
	ADC_voidInit();
	Timer_Init();
	
	ExtInt_voidINT0ISR(&swtich_Auto_Int0);
	ExtInt_voidINT1ISR(&swtich_Speed_Int1);
	ADC_voidSetISR(&adc_Int);
	
	Timer_LoadOCR(TIMER_0 ,255);
	Timer_Enable(TIMER_0);
	Pwm_SetDutyCycle(TIMER_0 , 0);
	
	
	
	
	asm("sei");
	ADC_voidStartConv();
	
	
    while(1)
    {
        if (Status_Automatic_Manual == Automatic_State)
		{
			lm35_reading = 100 * temp_adc;
			
			/* 30 C degree > adc_value > 25 C degree*/
			if ( (30 > lm35_reading) && (lm35_reading >= 25) )
			{
				Pwm_SetDutyCycle(TIMER_0 , 15);
			}
			
			/* 34 C degree > adc_value > 30 C degree*/
			else if ( (34> lm35_reading) && (lm35_reading >= 30) )
			{
				Pwm_SetDutyCycle(TIMER_0 , 20);
			}
			
			/* 38 C degree > adc_value > 34 C degree*/
			else if ( (38 > lm35_reading) && (lm35_reading >= 34) )
			{
				Pwm_SetDutyCycle(TIMER_0 , 25);
			}
			
			/* adc_value > 38 C degree*/
			else if (lm35_reading >= 38)
			{
				Pwm_SetDutyCycle(TIMER_0 , 100);
			}
			
			else
			{
				Pwm_SetDutyCycle(TIMER_0 , 0);
			}
			
		}
		
		else
		{
			switch (Status_Speed)
			{
				case Speed_1_State:
					Pwm_SetDutyCycle(TIMER_0 , 15);
					break;
			
			
				case Speed_2_State:
					Pwm_SetDutyCycle(TIMER_0 , 20);
					break;
			
				case Speed_3_State:
					Pwm_SetDutyCycle(TIMER_0 , 30);
					break;
	
				case Speed_4_State:
					Pwm_SetDutyCycle(TIMER_0 , 100);
					break;
			
				case Speed_0_State:
					Pwm_SetDutyCycle(TIMER_0 , 0);
					break;
			}
			
		}

    }
}


