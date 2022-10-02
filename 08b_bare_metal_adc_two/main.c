#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdlib.h>
#include "serial/serial.h"

volatile int adc5 = 0;
volatile int adc4 = 0;
volatile unsigned int channel = 0;

#define ADC_5 (1 << MUX0) | (1 << MUX2)
#define ADC_4 (1 << MUX2)

#define ADC_PRESCALER_128 (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2)

void adcStartConversion(){
    ADCSRA |= (1 << ADSC);
};

void adcInit(){
    ADCSRA = (1 << ADEN) | (1 << ADIE) | ADC_PRESCALER_128;
    ADMUX = (1 << REFS0) | ADC_5;
	DIDR0 = (1 << ADC5D) | (1 << ADC4D);
}

ISR(ADC_vect)
{
    channel++;

    ADMUX &=~ 15;

    switch(channel % 2){
        case 0:
            adc4 = ADC; 
            ADMUX |= ADC_5;
            break;
        case 1:
            adc5 = ADC;
            ADMUX |= ADC_4;
            break;
    }

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
        itoa(adc5, buffer, 10);
        serialSendArray(buffer, sizeof(buffer));
        serialSend(',');

        memset(buffer, 0, sizeof(buffer));
        itoa(adc4, buffer, 10);
        serialSendArray(buffer, 5);
        serialSend('\n');
    };
}



