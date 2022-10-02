## ADC Multiple channels
The main difference is switching the `ADMUX` register to switch channels (Table 23-4). Connect another potentiometer to pin A4.

The trick is to reset the selected `ADMUX` channel:

1. Clear all bits responsible for multiplexing by using number `15` which is equal to `0b00001111` in binary.
2. Depending on which channel we are using, store its value and set the channel to the next.
3. Start new conversion.

*When printing the values I'm using the same char array. `memset` clears its elements.*