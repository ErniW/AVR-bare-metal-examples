#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>
#include "serial/serial.h"

int main(){

    serialSetBaudrate(9600);
    serialInit();

    DDRB |= (1 << PB5);

    while(true){

        char message[] = "Hello World!\n";
        int messageLength = sizeof(message)/sizeof(char);
        serialSendArray(message, messageLength);
        
    }

}