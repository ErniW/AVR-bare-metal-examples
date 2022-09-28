#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

 uint16_t dutyCycle = 0;
//TIMER1_OVF_vect
//TIMER1_COMPA_vect 
ISR(TIMER1_OVF_vect ){
   
    //    OCR1AH = dutyCycle >> 8;
    //  OCR1AL = dutyCycle;
   // OCR1A = 10000;
}

int main(){


    int FAST_PWM_A =  ( 1<< WGM10) | ( 1<< WGM11);
    int FAST_PWM_B = ( 1<< WGM12) | ( 1<< WGM13);

    int PRESCALER_1 = (1 << CS10);
    int PRESCALER_8 = (1 << CS11);
    int PRESCALER_64 = (1 << CS10) | (1 << CS11);
    int PRESCALER_256 = (1 << CS12);
    int PRESCALER_1024 = (1 << CS10) | (1 << CS12);

    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB5);
    
	// TCCR1A = (1 << COM1A0) | FAST_PWM_A;
    // TCCR1B =  PRESCALER_1 | FAST_PWM_B;
	 TIMSK1 = ( 1 << TOIE1);
    TCCR1A = (1<<COM1A1) + (1<<WGM11); 
  TCCR1B = (1<<WGM13) + (1<<WGM12) + (1<<CS10);
   
     sei();
    ICR1 = 65535;
    OCR1A = 0;

    bool fade = false;

    while(true){
		_delay_ms(100);

        if(!fade) dutyCycle++;
        else dutyCycle--;
		
		if(dutyCycle == 65535 || dutyCycle == 0){
			fade = !fade;
            PORTB ^= (1 << PB5);
		}

         OCR1A = dutyCycle;
    };
}


/*


//oc1a oc1b oc2a

// ISR(TIMER0_OVF_vect){
// 	//OCR0A = dutyCycle;
//     OCR0A = dutyCycle;
//      OCR0B = dutyCycle;
// }

// ISR(TIMER2_OVF_vect){
// 	//OCR0A = dutyCycle;
//     //OCR0A = dutyCycle;
//     OCR2B = dutyCycle;
// }






    DDRD |= (1 << PD3) | (1 << PD5) | (1 << PD6);

	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | ( 1<< WGM00);// | ( 1<< WGM01);
	// TIMSK0 = ( 1 <<TOIE0);

    TCCR2A = (1 << COM2B1) | ( 1<< WGM00);// | ( 1<< WGM01);
	// TIMSK2 = ( 1 <<TOIE2);

	sei();
    TCCR0B = (1 << CS00);// | (1<< CS02);
    TCCR2B = (1 << CS00);

    bool fade = false;
    uint8_t which_led = 0;

    while(true){
		_delay_ms(10);

        if(!fade) dutyCycle++;
        else dutyCycle--;
		
		if(dutyCycle == 255 || dutyCycle == 0){
			fade = !fade;

            if(!fade && dutyCycle == 0){
                which_led++;
                which_led = which_led % 3;
            }
		}

        
    };

*/