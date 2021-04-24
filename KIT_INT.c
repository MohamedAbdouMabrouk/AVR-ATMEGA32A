
#include <avr/io.h>
#include "KIT_INT.h"

void INT_ENABLE(int INT_name, int INT_mode)
{
    if(INT_name == INT_0)
    {
        GICR &= ~(1 << INT0);
        switch(INT_mode)
        {
            case INT_mode_LOW:
                MCUCR &= ~((1<<ISC00) | (1 <<ISC01));
                break;
            case INT_mode_any:
               MCUCR |= (1<<ISC00); 
               MCUCR &= ~(1<<ISC01);
                break;
            case INT_mode_falling:
                MCUCR &= ~(1<<ISC00);
                MCUCR |= (1<<ISC01);
                break;
            case INT_mode_rising:
                MCUCR |= ((1<<ISC00) | (1<<ISC01));
                break;
        }
        GICR |= (1 << INT0);
    }else if(INT_name == INT_1)
    {
        GICR &= ~(1 << INT1);
        switch(INT_mode)
        {
            case INT_mode_LOW:
                MCUCR &= ~((1<<ISC10) | (1 <<ISC11));
                break;
            case INT_mode_any:
                MCUCR |= (1<<ISC10); 
                MCUCR &= ~(1<<ISC11);

                break;
            case INT_mode_falling:
                MCUCR &= ~(1<<ISC10);
                MCUCR |= (1<<ISC11);
                break;
            case INT_mode_rising:
                MCUCR |= ((1<<ISC10) | (1<<ISC11));
        }
        GICR |= (1 << INT1);
    }else if(INT_name == INT_2)
    {
        GICR &= ~(1 << INT2);
        switch(INT_mode)
        {
            case INT_mode_falling:
                MCUCSR &= ~(1<<ISC2);
                break;
            case INT_mode_rising:
                MCUCSR |= (1<<ISC2);
        }
        GICR |= (1 << INT2);
    }
 
}

void INT_DISABLE(int INT_name){
    if(INT_name == INT_0)
        GICR &= ~(1<< INT0);
    else if(INT_name == INT_1)
        GICR &= ~(1<< INT1);
    else if(INT_name == INT_2)
        GICR &= ~(1<< INT2);
    
}