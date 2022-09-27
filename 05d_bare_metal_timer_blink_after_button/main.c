#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <util/atomic.h>

#define INTERVAL_MS (65535 - (F_CPU/64)/1000)

volatile unsigned long time = 0;
unsigned long prevTime = 0;

ISR(TIMER1_OVF_vect){
    TCNT1 = INTERVAL_MS;
    time++;
}

int main(){

    DDRB |= (1<<PB4) | (1<<PB3) | (1<<PB2) | (1 << PB5);

    PORTD |= (1 << PD2);

    TCCR1B = (1 << CS10) | (1 << CS11);
    TCCR1A = 0;

    sei();

    unsigned long startingTime = 0;
    bool previousState = true;

    while(true){

        bool isPressed = PIND & (1 << PD2);

        if(isPressed && !previousState){
            TCNT1 = INTERVAL_MS;
            TIMSK1 = (1 << TOIE1);
            ATOMIC_BLOCK(ATOMIC_FORCEON){
                startingTime = time;
                time = 0;
            };
        }

        if(time >= 5000){
            PORTB ^= 1 << PB4;
            TIMSK1 &=~ (1 << TOIE1);
            time = 0;
        }

        previousState = isPressed;
    }
}