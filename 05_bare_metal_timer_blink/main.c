#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define INTERVAL_1S 65535 - (F_CPU/1024)

ISR(TIMER1_OVF_vect){
    PORTB ^= (1 << PB5);
    TCNT1 = INTERVAL_1S;
}

int main(){

    DDRB |= (1 << PB5);

    TCNT1 = INTERVAL_1S;
    TCCR1B = (1 << CS10) | (1 << CS12);
    TCCR1A = 0;

    TIMSK1 = (1 << TOIE1);

    sei();

    while(true){

    }
}