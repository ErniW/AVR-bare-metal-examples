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
    PORTD |= (1 << PD2);
    DDRB |= (1 << PB5);

    //SREG |= (1 << SREG_I);
    EIMSK |= (1 << INT0);
    EICRA |= (1 << ISC01);

    sei();

    while(true){

    }
}