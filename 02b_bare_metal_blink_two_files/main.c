#define F_CPU 16000000UL

#include "blink/blink.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main (void)
{
    DDRB |= (1<<PB5);

    while(true){
        blink();
    }
}