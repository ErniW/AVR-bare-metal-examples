## Pulse-width modulation (PWM)
A basic example of 8-bit timer to fade an LED.
- 8-bit values are between 0 and 255.
- I'm using **comparator** without prescaler (/1). The interrupt will occur when value reaches the duty cycle defined by brightness.
- I'm using phase-correct pwm mode defined in `TCCR0A` register.

The code uses comparator A of timer 0. According to ATMega328p pinout the `OC0A`is bound to port **PD6**. Enable it in `TCCR0A` register.

*There are various settings and ways to create PWM signal, it depends on your needs. The documentation explains the differences but to get the most of it you'll need an oscilloscope for testing.*