#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

volatile uint8_t brightness = 0;

ISR(TIMER0_OVF_vect){
    OCR0A = brightness;
}

int main(){

    DDRD |= (1 << PD6);

	TCCR0A = (1 << COM0A1) | ( 1<< WGM00);
    TCCR0B = (1 << CS00);

	TIMSK0 = ( 1 <<TOIE0);

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



