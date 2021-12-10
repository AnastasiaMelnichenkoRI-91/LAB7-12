void setup() {
  DDRB = B00100000; // DDRB = 0x20; // DDRB = 32; // встановимо 13 пін Arduino (5 пін регістра B) як вихід, а інші піни як входи
  DDRC = B11000010; // пін А1 як вихід (1 пін регістра С), пін А0 як вхід (0 пін регістра С), інші піни теж як входи

  PORTC =B00000000;
}

void loop() {
  // тернарна операція, аналог if...else...
  // читаєм сигнал з 4го піна регістру В і подаємо сигнал на 5й пін регістру В
  (PINB & (1 << PB4)) != 0   ?   PORTB |= 1 << PB5   :   PORTB &= ~(1 << PB5);
  // читаєм сигнал з 0го піна регістру С і подаємо сигнал на 1й пін регістру С
  (PINC & (1 << PC0)) != 0   ?   PORTC |= 1 << PC1   :   PORTC &= ~(1 << PC1);
}
