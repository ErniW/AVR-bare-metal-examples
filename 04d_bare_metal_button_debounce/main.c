#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

unsigned int debounceCounter = 0;

int main (void)
{
    PORTD |= (1 << PD2);
    DDRB |= (1 << PB5);

    bool previousState = false;

    while(true){

        bool isPressed = PIND & (1 << PD2);

        if(debounceCounter == 0){
            if(isPressed && !previousState){
                PORTB ^= 1 << 5;
                debounceCounter = 30000;
            }
        }
        else debounceCounter--;

        previousState = isPressed;
    }
    
}