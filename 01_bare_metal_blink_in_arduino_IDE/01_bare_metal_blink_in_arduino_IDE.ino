void setup() {
  DDRB |= (1 << PB5);
}

void loop() {
  PORTB ^= (1 << PB5);
  _delay_ms(500);
}
