## Analog-Digital conversion (ADC)
This example reads a value of, depending on your choice - potentiometer or photoresistor. The reading converts the voltage to 10-bit values between 0-1023.


### Things to configure:
1. In `ADCSRA` enable the ADC and interrupt. In the same register, the prescaler should be selected depending on your needs. **Higher frequency means lesser accuracy and vice-versa**.
2. Enable the ADC channel on pin A5. You should refer to table 23-4 **Input Chanels Selection** and set it in `ADMUX` register.
3. In the same register you have to select the voltage reference. We want to use the same as AVCC 5V.
4. In `DIDR0` disable the digital input of port `C5`.

### To start conversion:
Set the `ADSC` bit in `ADCSRA`. Do it every time you start conversion.

*Measuring multiple channels requires different approach.*

### Printing the value:
The `itoa` function converts an intiger to char array which is sent by `serialSendArray` from our previous examples.