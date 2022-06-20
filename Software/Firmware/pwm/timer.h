/*
 * timer.h
 *
 * Created: 3/12/2020 6:26:58 PM
 *  Author: Ashraf Amgad
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "timer_cfg.h"
#include "../utils/std_types.h"
#include "utils_2.h"
#include <avr/interrupt.h>


#define TIMER_INIT				(0U)
#define TIMER_UNINIT			(1U)

#define TIMER_0					(2U)
#define TIMER_2					(3U)

#define TIMER_MODE_NORMAL				(4U)
#define TIMER_MODE_CTC					(5U)
#define TIMER_MODE_FAST_PWM				(6U)
#define TIMER_MODE_PHASE_CORRECT_PWM	(7U)


#define CPU_CLOCK_1M			(13U)
#define CPU_CLOCK_4M			(14U)
#define CPU_CLOCK_8M			(15U)

#define TIMER_OCn_NON_PWM_DISCONNECT		(16U)
#define TIMER_OCn_NON_PWM_TOGGLE			(17U)
#define TIMER_OCn_NON_PWM_CLEAR				(18U)
#define TIMER_OCn_NON_PWM_SET				(19U)

#define TIMER_OCn_FAST_PWM_DISCONNECT		(20U)
#define TIMER_OCn_FAST_PWM_SET_AT_TOP		(21U)
#define TIMER_OCn_FAST_PWM_CLEAR_AT_TOP		(22U)


#define TIMER_OCn_PHASE_CORRECT_PWM_DISCONNECT				(23U)
#define TIMER_OCn_PHASE_CORRECT_PWM_CLEAR_AT_UP_COUNT		(24U)
#define TIMER_OCn_PHASE_CORRECT_PWM_SET_AT_UP_COUNT			(25U)



/*** CLOCK SELECT ***/
#define TIMER_PRESCALER_1			(26U)
#define TIMER_PRESCALER_8           (27U)
#define TIMER_PRESCALER_32          (28U)
#define TIMER_PRESCALER_64          (39U)
#define TIMER_PRESCALER_128         (30U)
#define TIMER_PRESCALER_256         (31U)
#define TIMER_PRESCALER_1024        (32U)



#define TIMER_OCR0		(* (volatile u8*)(0x5C))
#define TIMER_TIMSK		(* (volatile u8*)(0x59))
#define TIMER_TIFR		(* (volatile u8*)(0x58))
#define TIMER_TCCR0		(* (volatile u8*)(0x53))
#define TIMER_TCNT0		(* (volatile u8*)(0x52))
#define TIMER_TCCR2		(* (volatile u8*)(0x45))
#define TIMER_TCNT2		(* (volatile u8*)(0x44))
#define TIMER_OCR2		(* (volatile u8*)(0x43))
#define TIMER_ASSR		(* (volatile u8*)(0x42))	
	
	


       
#define TIMER_TCCR0_CS00		((u8)0x01)
#define TIMER_TCCR0_CS01		((u8)0x02)
#define TIMER_TCCR0_CS02		((u8)0x04)
#define TIMER_TCCR0_WGM01		((u8)0x08)
#define TIMER_TCCR0_COM00		((u8)0x10)
#define TIMER_TCCR0_COM01		((u8)0x20)
#define TIMER_TCCR0_WGM00		((u8)0x40)
#define TIMER_TCCR0_FOC0		((u8)0x80)

#define TIMER_TCCR2_CS20		((u8)0x01)
#define TIMER_TCCR2_CS21		((u8)0x02)
#define TIMER_TCCR2_CS22		((u8)0x04)
#define TIMER_TCCR2_WGM21		((u8)0x08)
#define TIMER_TCCR2_COM20		((u8)0x10)
#define TIMER_TCCR2_COM21		((u8)0x20)
#define TIMER_TCCR2_WGM20		((u8)0x40)
#define TIMER_TCCR2_FOC2		((u8)0x80)


#define TIMER_TIMSK_TOIE0		((u8)0x01)
#define TIMER_TIMSK_OCIE0		((u8)0x02)
#define TIMER_TIMSK_TOIE2		((u8)0x40)
#define TIMER_TIMSK_OCIE2		((u8)0x80)


#define TIMER_TIFR_TOV0			((u8)0x01)
#define TIMER_TIFR_OCF0			((u8)0x02)
#define TIMER_TIFR_TOV2			((u8)0x40)
#define TIMER_TIFR_OCF2			((u8)0x80)

   
#define TIMER_ASSR_TCR2UB		((u8)0x01)
#define TIMER_ASSR_OCR2UB		((u8)0x02)
#define TIMER_ASSR_TCN2UB		((u8)0x04)
#define TIMER_ASSR_AS2			((u8)0x08)






void Timer_Init(void);
void Timer_LoadTCNT(u8 timer ,u8 Local_Value);
void Timer_LoadOCR(u8 timer ,u8 Local_Value);
void Timer_EnableInterrupt(u8 interrupt);
void Timer_DisableInterrupt(u8 interrupt);
void Pwm_SetDutyCycle(u8 timer ,u8 DutyCycle);
void Pwm_Volt2DutyCycle(u8 timer ,f32 volt);
void PWM_OutputPinDisconnect(u8 timer);
void PWM_OutputPinConnect(u8 timer);
void Timer_Disable(u8 timer);
void Timer_Enable(u8 timer);
void Timer_SetCompareMatch_ISR(u8 timer ,void (*Local_COMP_ISR)(void));
void Timer_SetOverFlow_ISR(u8 timer ,void (*Local_OV_ISR)(void));


#endif /* TIMER_H_ */
