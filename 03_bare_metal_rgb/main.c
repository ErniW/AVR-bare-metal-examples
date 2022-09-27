#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
    uint8_t RGB_LED = (1<<PB4) | (1<<PB3) | (1<<PB2);

    DDRB = RGB_LED;

    while(true){
        PORTB ^= RGB_LED;
        _delay_ms(100);
    }
}