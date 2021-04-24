#include <avr/io.h>
#include <avr/iom32a.h>
#include "Timer.h"


void Timer0_init(int mode, int clk)
{
    TCCR0 &= ~(9 << 3);
    TCCR0 &= ~7;
    TCCR0 |= (mode << 3);
    TCCR0 |= clk;
}

void Timer0_OVINT_EnableOrDisable(int state)
{
    if(state)
        TIMSK |= (1 << TOIE0);
    else
        TIMSK &= ~(1 << TOIE0);
}

void Timer0_setMaxPoint(unsigned char val)
{
    OCR0 = val;
}

void Timer0_OCINT_EnableOrDisable(int state)
{
    if(state)
        TIMSK |= (1 << OCIE0);
    else
        TIMSK &= ~(1 << OCIE0);
}

void Timer0_setOC0mode(int mode)
{
    TCCR0 &= ~(3 << 4);
    if(mode != CTC_OC0_Disconnected)
        DDRB |= (1 << 3);
    TCCR0 |= (mode << 4);
}