#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

void serialSetBaudrate(unsigned long baudrate){
    unsigned long UBRR_value = (F_CPU/(baudrate*16))-1;
    UBRR0 = UBRR_value;
}

void serialInit(){
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0) |  (1 <<RXCIE0);
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

    SREG |= (1 << SREG_I);
}

ISR(USART_RX_vect){
    char c = UDR0;

    if (c == 'x') PORTB |= ( 1 << PB5);
    else PORTB &=~ ( 1 << PB5);
}

int main(){

    serialSetBaudrate(9600);
    serialInit();

    DDRB |= (1 << PB5);

    sei();

    while(true){
        _delay_ms(1000);
    };

}