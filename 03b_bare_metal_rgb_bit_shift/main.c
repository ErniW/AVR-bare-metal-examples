#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
    DDRB = (7 << 2);

    while(true){
        PORTB = 1 << 2; 
        _delay_ms(400);
        PORTB <<= 1;
        _delay_ms(400);
        PORTB <<= 1;
        _delay_ms(400);
        PORTB = 0;
    }
}