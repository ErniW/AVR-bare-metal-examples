#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
    PORTD |= (1 << PD2);
    DDRB |= (1 << PB5);

    bool previousState = false;

    while(true){

        bool isPressed = PIND & (1 << PD2);

        if(isPressed == true && isPressed != previousState){
            PORTB ^= 1 << 5;
        }

        previousState = isPressed;

    }
}