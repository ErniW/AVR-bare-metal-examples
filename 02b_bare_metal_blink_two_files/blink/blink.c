#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>

void blink(){
    PORTB ^= _BV(PB5);
    _delay_ms(100);
}