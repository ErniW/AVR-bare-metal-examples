## Timers
Timers are another important concept. In Arduino you've used them for measuring time of `millis` function and `analogWrite` for PWM wave, but in detail they are more complex. Later I will show how they're used to control servo.

You can count single ticks of microcontroller CPU and use interrupt to do something when their amount overflows a selected threshold which sets a time interval or square wave period.

ATMega328p has three timers with two 8-bit (0, 2) and one 16-bit (1).

For measuring time we use 16-bit for better accuracy.

### How to configure timer?

This page can help you: 
https://eleccelerator.com/avr-timer-calculator/

**To measure a 1 second interval:**
- **Set the prescaler** in `TCCR1B` register to set the timer clock to main CPU clock divided by 1024.
- **Set the overflow of interval.** To create 1 second interval we set the timer frequency to 1Hz by counting 15625 ticks before it overflows.
- **Create an interrupt** when timer overflows.

