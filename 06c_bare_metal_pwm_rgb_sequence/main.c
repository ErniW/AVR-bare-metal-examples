#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

uint8_t brightness = 0;

// ISR(TIMER0_OVF_vect){
// 	OCR0A = brightness;
//  OCR0A = brightness;
//  OCR0B = brightness;
// }

// ISR(TIMER2_OVF_vect){
// 	OCR0A = brightness;
//  OCR0A = brightness;
//  OCR2B = brightness;
// }

int main(){

    DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);

	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | ( 1<< WGM00);
	// TIMSK0 = ( 1 <<TOIE0);

    TCCR2A = (1 << COM2B1) | ( 1<< WGM20);
	// TIMSK2 = ( 1 <<TOIE2);

	sei();
    TCCR0B = (1 << CS00);
    TCCR2B = (1 << CS20);

    bool fade = false;
    uint8_t which_led = 0;

    while(true){
		_delay_ms(10);

        if(!fade) brightness++;
        else brightness--;
		
		if(brightness == 255 || brightness == 0){
			fade = !fade;

            if(!fade && brightness == 0){
                which_led++;
                which_led = which_led % 3;
            }
		}

        switch (which_led){
            case 0:
                OCR0A = brightness;
                OCR0B = 0;
                OCR2B = 0;
                break;
            case 1:
                OCR0A = 0;
                OCR0B = brightness;
                OCR2B = 0;
                break;
            case 2:
                OCR0A = 0;
                OCR0B = 0;
                OCR2B = brightness;
                break;
        }

        
    };

}



