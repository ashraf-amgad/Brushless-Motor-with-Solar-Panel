
#include "adc.h"

void (*ADC_ISR)(void) = '\0';

void ADC_voidInit(void)
{
        CLRBIT(ADMUX, REFS0);
        CLRBIT(ADMUX, REFS1);
       

        CLRBIT(ADMUX, MUX4);
        CLRBIT(ADMUX, MUX3);

        CLRBIT(ADMUX, MUX2);
        CLRBIT(ADMUX, MUX1);
        CLRBIT(ADMUX, MUX0);
        

        CLRBIT(ADMUX, ADLAR);

        /*** Configure control and status register ***/
        SETBIT(ADCSRA, ADEN);
        CLRBIT(ADCSRA, ADSC);
        CLRBIT(ADCSRA, ADATE);
        SETBIT(ADCSRA, ADIF);
        SETBIT(ADCSRA, ADIE);

        SETBIT(ADCSRA, ADPS0);
        SETBIT(ADCSRA, ADPS1);
        SETBIT(ADCSRA, ADPS2);

}



void ADC_voidSetISR(void (*Local_ISR)(void))
{
    ADC_ISR = Local_ISR;
}



void ADC_voidStartConv(void)
{
    SETBIT(ADCSRA, ADSC);
}



u16 ADC_u16GetData(void)
{
    return ADCW;
}


ISR(ADC_vect)
{
    ADC_ISR();
}
