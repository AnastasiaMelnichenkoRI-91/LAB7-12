//const byte buttonPin = 12; // PB4
//const byte ledPin =  13; // PB5

int buttonState = 0;

void setup() {
  //DDRB = B00100000; // встановимо 13 пін Arduino (5 пін регістра B) як вихід, а 12 пін Arduino (4 пін регістра B) як вхід
  DDRB |= 1 << PB5; // DDRB = DDRB | (1 << 5); // pinMode(ledPin, OUTPUT);
  DDRB &= ~(1 << PB4); // DDRB = DDRB & (~(1 << 4)); // pinMode(buttonPin, INPUT); 
}

void loop() {
  buttonState = ( PINB & (1 << PB4) ) >> PB4; // buttonState = digitalRead(buttonPin);
  
  buttonState == 1 ? PORTB |= 1 << PB5 : PORTB &= ~(1 << PB5);
}
