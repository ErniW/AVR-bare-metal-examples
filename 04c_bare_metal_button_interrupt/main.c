#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

ISR (INT0_vect){
    PORTB ^= 1 << 5;
}

int main (void)
{
    //PD2, PD3 - 2,3 arduino pin

    PORTD |= (1 << PD2);
    DDRB |= (1 << PB5);

    SREG |= 1 << 7;
    EIMSK |= 1;
    EICRA |= 1 << 1;

    sei();

    while(true){

    }
}