/*
 * File:   main.c
 * Author: mamm_
 *
 * Created on March 26, 2021, 2:36 PM
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED0 2
#define LED1 7
#define LED2 3
#define RELAY 2
#define Buzzer 3
#define Button0 0
#define Button1 6
#define Button2 2



void LEDs_init();
void RELAY_init();
void Buzzer_init();
void Buttons_init();

void LED0_ON();
void LED1_ON();
void LED2_ON();
void LEDs_ON();

void RELAY_ON();
void Buzzer_ON();

void LED0_OFF();
void LED1_OFF();
void LED2_OFF();
void LEDs_OFF();

void RELAY_OFF();
void Buzzer_OFF();

int Button0_isPressed();
int Button1_isPressed();
int Button2_isPressed();


int main(void) {
    
    LEDs_init();
    RELAY_init();
    Buzzer_init();   
    Buttons_init();
    while (1) {
        
        if(Button0_isPressed())
            LED0_ON();
        else
            LED0_OFF();
        
        if(Button1_isPressed())
            LED1_ON();
        else
            LED1_OFF();
        
        if(Button2_isPressed())
            LED2_ON();
        else
            LED2_OFF();
        
        if(Button0_isPressed() && Button1_isPressed())
            Buzzer_ON();
        else
            Buzzer_OFF();
        
        if(Button1_isPressed() && Button2_isPressed())
            RELAY_ON();
        else
            RELAY_OFF();
        
    }
}

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
