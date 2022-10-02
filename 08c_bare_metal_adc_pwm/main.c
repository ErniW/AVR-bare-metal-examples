#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdlib.h>

volatile int adc = 0;
volatile int brightness = 0;

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

ISR(TIMER0_OVF_vect){
    brightness = adc / 4;
    OCR0A = brightness;
}

int main(){
    adcInit();
    adcStartConversion();

    DDRD |= (1 << PD6);

	TCCR0A = (1 << COM0A1) | ( 1<< WGM00);
    TCCR0B = (1 << CS00);

	TIMSK0 = ( 1 <<TOIE0);

    sei();

    while(true){

    };
}



