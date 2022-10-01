## SG-90 Servo control
If you didn't know - servo position is controlled with a PWM wave of specific duty cycle. You don't send it a value but a square wave with specified period which sets its angle.

## Servo control requirements:
- **Frequency**: 50Hz
- **Period**: (related to frequency): 20ms.
- **Pulse width**: 0.5 - 2.5ms. 

*Parameters are for SG-90 servo, you should check that range if you have more precise servo.*

*We shall use 16-bit timer. 8-bit timer would generate only a few steps to control the angle.*

*Pulse width of a square wave is sometimes described as duty cycle which is measured in percentage of period.*

## Servo configuration:
- Set Timer1 to `Fast-PWM mode`. Please note that Timer1 works differently than others and has more options, the WGM bits are separated between `TCCR1A` and `TCCR1B` registers.
- Set the prescaler to 64.
- To set the frequency to 50Hz we need to set `ICR1` as a threshold value. Using the formula `(F_CPU / 64 / 50) - 1;
` ICR1 will be equal to 4999. You can check that in https://eleccelerator.com/avr-timer-calculator/

*It's 4999 because we start from 0.*

## Generating the square wave for a specific angle:

- **Angle 0 should be 0.5ms** (0.5/20 = 0.025), so OCR1A = 4999 * 0.025 ~= 125
- **Angle 90 should be 1.5ms** (1.5/20 = 0.075), so OCR1A = 4999 * 0.075 ~= 375
- **Angle 180 should be 2.5ms** (2.5/20 = 0.125) so OCR1A = 4999 * 0.125 ~= 615