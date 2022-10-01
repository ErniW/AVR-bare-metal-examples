## Button interrupt
As an introduction to interrupts I will show a basic button example.

If you aren't familiar with them, interrupts are an important concept in hardware. They immediately trigger an event when a certain action occurs without waiting for other things to finish.They can be internal or external. *ATMega328p has only two external interrupts so generally using them for button is a waste of resources. The buttons has a problem with debouncing which I will cover in next example*

### To enable external interrupt:
1. Set the **AVR status register** `SREG` bit 7 to enable interrupts. It's called `SREG_I`.
2. The button in port PD2 is bounded to external interrupt `INT0`. You need to enable it in `EIMSK` register.
3. `EICRA` defines the behavior of interrupt. You can trigger it when button is pressed, released or on any change.
4. Add handler of ISR function `INT0_vect`. 
5. Add `sei()` if you dont wan't to handle SREG_I directly.

As you can see you can do the same thing while the main loop remains empty.

You can see the **order of importance** in **Interrupts Vectors Table in ATMega328p** in chapter 11.1. Obviously the reset is most important.
