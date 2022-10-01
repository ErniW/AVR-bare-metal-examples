#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define INTERVAL_HALF_SECOND 65535 - (F_CPU/1024) / 2
#define PRESCALER_1024 (1 << CS10) | (1 << CS12)

long counter = 0;

ISR(TIMER1_OVF_vect){
    PORTB ^= (1 << PB5);
    TCNT1 = INTERVAL_HALF_SECOND;

    counter++;

    if(counter % 3 == 0) PORTB = (1 << PB4);
    else if(counter % 3 == 1) PORTB = (1 << PB3);
    else if(counter % 3 == 2) PORTB = (1 << PB2);
}

int main(){

    DDRB |= (1<<PB4) | (1<<PB3) | (1<<PB2);

    TCNT1 = INTERVAL_HALF_SECOND;
    TCCR1B = PRESCALER_1024;
    TCCR1A = 0;

    TIMSK1 = (1 << TOIE1);

    sei();

    while(true){

    }
}