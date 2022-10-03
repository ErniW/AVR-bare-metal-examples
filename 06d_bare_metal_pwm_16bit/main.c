#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

volatile uint16_t brightness = 0;
//TIMER1_OVF_vect
//TIMER1_COMPA_vect 
ISR(TIMER1_OVF_vect ){ 
    //OCR1AH = brightness >> 8;
    //OCR1AL = brightness;
    // OCR1A = 10000;
}

int main(){

    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB5);

    TIMSK1 = ( 1 << TOIE1);
    TCCR1A = (1<<COM1A1) | (1<<WGM11); 
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS10);
   
    sei();
    ICR1 = 65535;
    OCR1A = 0;

    bool fade = false;

    while(true){
        _delay_ms(100);

        if(!fade) brightness++;
        else brightness--;

        if(brightness == 65535 || brightness == 0){
            fade = !fade;
            PORTB ^= (1 << PB5);
        }

        OCR1A = brightness;
    };
}