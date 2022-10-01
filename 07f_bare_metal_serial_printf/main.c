#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdio.h>

void serialSetBaudrate(unsigned long baudrate){
    unsigned long UBRR_value = (F_CPU/(baudrate*16))-1;
    UBRR0 = UBRR_value;
}

void serialInit(){
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
    //UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}

bool serialAvailable(){
    return (UCSR0A & (1<<RXC0));
}

void usart_send_byte(char byte, FILE *stream) {
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = byte;
}

char usart_get_byte(FILE *stream) {
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

FILE uart_out = FDEV_SETUP_STREAM(usart_send_byte, NULL, _FDEV_SETUP_WRITE);
FILE uart_in = FDEV_SETUP_STREAM(NULL, usart_get_byte, _FDEV_SETUP_READ);

int main(){

    serialSetBaudrate(9600);
    serialInit();

    stdout = &uart_out;
	stdin = &uart_in;

    int x = 1234;
    printf("Value: %d\n", x);
    _delay_ms(100);

    while(true){

        char test[20];

        fgets(test, 20,stdin);
        printf("Value: %s", test);

    };

}