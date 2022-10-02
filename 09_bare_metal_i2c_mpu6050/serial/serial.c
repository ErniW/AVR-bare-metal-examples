#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>

void serialSetBaudrate(unsigned long baudrate){
    unsigned long UBRR_value = (F_CPU/(baudrate*16))-1;

    UBRR0 = UBRR_value;
}

void serialInit(){
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

void serialSendArray(char* buffer, int length){
    for(int i=0; i<length; i++){
        serialSend(buffer[i]);
    }
}

unsigned char serialRead(){
    return UDR0;
}