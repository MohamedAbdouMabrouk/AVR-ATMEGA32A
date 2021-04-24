
#include <avr/io.h>
#include "ADC.h"

void ADC_selectVref(int Vref)
{
    ADMUX &= ~ ((1 << REFS0) | (1 << REFS1));
    ADMUX |= (Vref << 6);
}

void ADC_selectChannel(int ChannelNumber)
{
    ADMUX &= ~31;
    ADMUX |= ChannelNumber;
}

void ADC_selectPrescalar(int Prescalar)
{
    ADCSRA &= ~7;
    ADCSRA |= Prescalar;
}

void ADC_ENABLE()
{
    ADCSRA |= (1 << ADEN);
}

void ADC_DISABLE()
{
   ADCSRA &= ~(1 << ADEN); 
}

void ADC_START()
{
    ADCSRA |= (1 << ADSC);
}

void ADC_INIT(int ChannelNumber, int Verf, int Prescalar)
{
    ADC_selectChannel(ChannelNumber);
    ADC_selectVref(Verf);
    ADC_selectPrescalar(Prescalar);
    ADC_ENABLE();
}

int ADC_READ_R()
{
   int data = ADCL;
   data |= (ADCH << 8);
   return data;
}

int ADC_READ_L()
{
    int data = ADC_READ_R();
    return (data >> 6);
}

