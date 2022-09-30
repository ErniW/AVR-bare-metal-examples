#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

#define PRESCALER_64 (1 << CS11) | (1 << CS10)
#define FAST_PWM_A (1 << WGM11)
#define FAST_PWM_B (1 << WGM13) | (1 << WGM12)

int main(){

    TCCR1A = FAST_PWM_A | (1 << COM1A1);
    TCCR1B = FAST_PWM_B | PRESCALER_64;
    ICR1 = (F_CPU / 64 / 50) - 1;

    DDRB |= (1 << PB1);

    while(true){
        OCR1A = 125;
        _delay_ms(2000);
         OCR1A = 370;
        _delay_ms(2000);
        OCR1A = 615;
        _delay_ms(2000);
    }

}