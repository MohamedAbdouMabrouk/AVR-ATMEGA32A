
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <avr/iom32a.h>
#include <stdlib.h>
#include "KIT_IO.h"
#include "KIT_INT.h"
#include "ADC.h"
#include "Timer.h"
#include "mLCD.h"


#define setPoint 125
#define matchPoint (15625/setPoint)

ISR(TIMER0_OVF_vect){

    static int x = 0;
    char str1[]= ":";
    
    x++;
    
    if(x==61){
        static int second = 0;
        static int min = 0;
        static int hour = 0;
        second++;
        if(second == 60){
            second =0;
            min++;
        }
        if(min == 60)
        {
            min = 0;
            hour++;
        }
        if(hour == 12)
        {
            hour = 0;
        }
        LCD_clear_4bits();
        LCD_write_num_4bits(hour);
        LCD_write_str_4bits(str1);
        LCD_write_num_4bits(min);
        LCD_write_str_4bits(str1);
        LCD_write_num_4bits(second);
        
        x =0;
    }    
    //
}

ISR(TIMER0_COMP_vect)
{
    static int x = 0;
    char str1[]= ":";
    x++;
    
    if(x == matchPoint)
    {
        static int second = 0;
        static int min = 0;
        static int hour = 0;
        second++;
        if(second == 60){
            second =0;
            min++;
        }
        if(min == 60)
        {
            min = 0;
            hour++;
        }
        if(hour == 12)
        {
            hour = 0;
        }
        LCD_clear_4bits();
        LCD_write_num_4bits(hour);
        LCD_write_str_4bits(str1);
        LCD_write_num_4bits(min);
        LCD_write_str_4bits(str1);
        LCD_write_num_4bits(second);
        
        x =0;
    }
}


int main(void) {
    
    DDRC = 0xFF;
    LCD_init(_4BITS);
    Timer0_setMaxPoint(setPoint);
    Timer0_setOC0mode(CTC_clear);
    Timer0_init(CTC,CLK_1024);
    Timer0_OCINT_EnableOrDisable(ENABLE);
    
    sei();
    
    while(1){
       
    }
}
