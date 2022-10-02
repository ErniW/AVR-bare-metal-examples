#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "serial/serial.h"
#include <stdlib.h>

volatile int adc = 0;

#define ADC_5 (1 << MUX0) | (1 << MUX2)
#define ADC_PRESCALER_128 (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)

void adcStartConversion(){
    ADCSRA |= (1 << ADSC);
};

void adcInit(){
    ADCSRA = (1 << ADEN) | (1 << ADIE) | ADC_PRESCALER_128;
    ADMUX = (1 << REFS0) | ADC_5;
	DIDR0 = (1 << ADC5D);
}

ISR(ADC_vect)
{
	adc = ADC;
	adcStartConversion();
}

int main(){

    serialSetBaudrate(9600);
    serialInit();

    adcInit();
    adcStartConversion();
    sei();

    while(true){
        char buffer[5] = {0};
        itoa(adc, buffer, 10);
        serialSendArray(buffer, 5);
        serialSend('\n');
    };
}



