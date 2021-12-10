void setup() {
  DDRB = B00100000; // DDRB = 0x20; // DDRB = 32; // встановимо 13 пін Arduino (5 пін регістра B) як вихід, а інші піни як входи
}

void loop() {
  (PINB & (1 << PB4)) != 0   ?   PORTB |= 1 << PB5   :   PORTB &= ~(1 << PB5); // тернарна операція, аналог if...else...
}
