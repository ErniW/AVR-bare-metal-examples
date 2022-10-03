#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

uint8_t brightness = 0;

ISR(TIMER0_OVF_vect){
    OCR0A = brightness;
    OCR0B = brightness;
}

ISR(TIMER2_OVF_vect){
    OCR2B = brightness;
}

int main(){

    DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);

    TCCR0A = (1 << COM0A1) | (1 << COM0B1) | ( 1<< WGM00);
    TIMSK0 = ( 1 <<TOIE0);

    TCCR2A = (1 << COM2B1) | ( 1<< WGM20);
    TIMSK2 = ( 1 <<TOIE2);


    TCCR0B = (1 << CS00);
    TCCR2B = (1 << CS20);

    sei();

    bool fade = false;

    while(true){
        _delay_ms(10);

        if(!fade) brightness++;
        else brightness--;
        
        if(brightness == 255 || brightness == 0){
            fade = !fade;
        }

    };

}



