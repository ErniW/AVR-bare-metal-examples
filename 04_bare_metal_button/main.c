#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
    PORTD |= (1 << PD2);

    DDRB |= (1 << PB5);

    while(true){

        if(PIND & (1 << PD2)){
            PORTB &=~ 1 << 5;
        }
        else {
            PORTB |= 1 << 5;
        }

    }
}