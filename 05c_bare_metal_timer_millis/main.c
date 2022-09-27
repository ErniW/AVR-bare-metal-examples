#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <util/atomic.h>

#define INTERVAL_MS (65535 - (F_CPU/64)/1000)

volatile unsigned long time = 0;
unsigned long prevTime = 0;
unsigned long prevBTime = 0;
unsigned long prevCTime = 0;

ISR(TIMER1_OVF_vect){
    TCNT1 = INTERVAL_MS;
    time++;
}

int main(){

    DDRB |= (1<<PB4) | (1<<PB3) | (1<<PB2) | (1 << PB5);

    TCNT1 = INTERVAL_MS;
    TCCR1B = (1 << CS10) | (1 << CS11);
    TCCR1A = 0;

    TIMSK1 = (1 << TOIE1);

    sei();

    unsigned long currentTime;

    while(true){

        ATOMIC_BLOCK(ATOMIC_FORCEON){
            currentTime = time;
        };

        if(currentTime - prevTime >= 1000){
            PORTB ^= 1 << PB4;
            prevTime = time;
        }
        if(currentTime - prevBTime >= 2000){
            PORTB ^= 1 << PB3;
            prevBTime = time;
        }
         if(currentTime - prevCTime >= 3000){
            PORTB ^= 1 << PB2;
            //TIMSK1 &=~ (1 << TOIE1);
            prevCTime = time;
        }
    }
}