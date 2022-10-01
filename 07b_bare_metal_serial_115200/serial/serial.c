#define F_CPU 16000000UL

#include "serial.h"
#include <avr/io.h>
#include <stdbool.h>

void serialSetBaudrate(unsigned long baudrate){
    unsigned long UBRR_value = ((F_CPU / 8 + baudrate / 2) / baudrate - 1);
    UBRR0 = UBRR_value;
}

void serialInit(){
    UCSR0A |= (1 << U2X0);
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

bool serialAvailable(){
    return (UCSR0A & (1<<RXC0));
}

void serialSend(unsigned char data){
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

unsigned char serialRead(){
    return UDR0;
}