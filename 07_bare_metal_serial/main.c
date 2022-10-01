#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>
#include "serial/serial.h"

int main(){

    serialSetBaudrate(9600);
    serialInit();

    DDRB |= (1 << PB5);

    while(true){

        while(serialAvailable()){
            char c = serialRead();

            if(c == 'x') PORTB |= (1 << PB5);
            else PORTB &=~ (1 << PB5);

            serialSend(c);
            serialSend('\n');
        }
    }

}