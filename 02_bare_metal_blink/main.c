#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(){

    DDRB |= (1 << PB5);

    while(true){
        PORTB ^= (1 << PB5);
        _delay_ms(500);
    }
}