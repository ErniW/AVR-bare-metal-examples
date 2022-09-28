#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

uint8_t dutyCycle = 0;

//oc1a oc1b oc2a

ISR(TIMER0_OVF_vect){
	//OCR0A = dutyCycle;
    OCR0A = dutyCycle;
     OCR0B = dutyCycle;
}

ISR(TIMER2_OVF_vect){
	//OCR0A = dutyCycle;
    //OCR0A = dutyCycle;
    OCR2B = dutyCycle;
}

int main(){

    DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);

	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | ( 1<< WGM00);// | ( 1<< WGM01);
	TIMSK0 = ( 1 <<TOIE0);

    TCCR2A = (1 << COM2B1) | ( 1<< WGM00);// | ( 1<< WGM01);
	TIMSK2 = ( 1 <<TOIE2);

	sei();
    TCCR0B = (1 << CS00);// | (1<< CS02);
    TCCR2B = (1 << CS00);

    bool fade = false;

    while(true){
		_delay_ms(10);

        if(!fade) dutyCycle++;
        else dutyCycle--;
		
		if(dutyCycle == 255 || dutyCycle == 0){
			fade = !fade;
		}

        
    };

}



