## Measuring miliseconds.

This time we create something similar to Arduino `millis` counter. We need an 64 prescaler and divide by 1000. We do that because 1024 won't result in intiger casuing timing issues.

I'm using `ATOMIC_BLOCK` and `volatile` time because interrupts can cause unexpected results during the measurments (by interrupting them). **Maybe it's not necessary in such a basic case** but it's good to be aware of that.