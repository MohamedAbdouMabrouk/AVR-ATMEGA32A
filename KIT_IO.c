
#include <avr/io.h>
#include "KIT_IO.h"

void LEDs_init(){
    DDRC |= (1<<LED0) | (1<<LED1);
    DDRD |= (1<<LED2);
}

void RELAY_init(){
    DDRA |= (1<<RELAY);
}

void Buzzer_init(){
    DDRA |= (1<<Buzzer);
}

void Buttons_init(){
    DDRB &= ~(1<<Button0);
    DDRD &= ~((1<<Button1) | (1<<Button2));
}

void LED0_ON(){
    PORTC |= (1<<LED0);
}

void LED1_ON(){
    PORTC |= (1<<LED1);
}

void LED2_ON(){
    PORTD |= (1<<LED2);
}

void LEDs_ON(){
    LED0_ON();
    LED1_ON();
    LED2_ON();
}

void RELAY_ON(){
    PORTA |= (1<<RELAY);
}

void Buzzer_ON(){
    PORTA |= (1<<Buzzer);
}

void LED0_OFF(){
    PORTC &= ~(1<<LED0);
}

void LED1_OFF(){
    PORTC &= ~(1<<LED1);
}

void LED2_OFF(){
    PORTD &= ~(1<<LED2);
}

void LEDs_OFF(){
    LED0_OFF();
    LED1_OFF();
    LED2_OFF();
}

void RELAY_OFF(){
    PORTA &= ~(1<<RELAY);
}

void Buzzer_OFF(){
    PORTA &= ~(1<<Buzzer);
}

int Button0_isPressed(){
    if(PINB & (1<<Button0)){
        return 1;
        }
        else{
        return 0;
        }
}

int Button1_isPressed(){
   if(PIND & (1<<Button1)){
       return 1;
        }
        else{
       return 0;
        } 
}

int Button2_isPressed(){
    if(PIND & (1<<Button2)){
            return 1;
        }
        else{
            return 0;
        }
}

void LED0_Toggle()
{
    PORTC ^= (1<<LED0);
}

void LED1_Toggle()
{
    PORTC ^= (1<<LED1);
}

void LED2_Toggle()
{
    PORTD ^= (1<<LED2);
}