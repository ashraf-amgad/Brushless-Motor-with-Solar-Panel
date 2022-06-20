#ifndef ADC_INT_H_
#define ADC_INT_H_


#include <util/delay.h>
#include <avr/interrupt.h>
#include "../utils/std_types.h"
#include "../utils/utils.h"



void ADC_voidInit(void);

void ADC_voidSetISR(void (*Local_ISR)(void));

void ADC_voidStartConv(void);

u16 ADC_u16GetData(void);

#endif /* ADC_INT_H_ */
