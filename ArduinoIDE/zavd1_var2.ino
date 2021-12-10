//const byte buttonPin = 12; // PB4
//const byte ledPin =  13; // PB5

int buttonState = 0;

void setup() {
      // встановимо 13 пін Arduino (5 пін регістра B) як вихід, а 12 пін Arduino (4 пін регістра B) як вхід
      // DDRB = B00100000; // DDRB = 0b00100000; // DDRB = (1 << 5); // DDRB = (1 << PB5);
  DDRB = DDRB | B00100000; // DDRB = DDRB | (1 << 5); // DDRB |= 1 << PB5; // pinMode(ledPin, OUTPUT);
  DDRB = DDRB & B11101111; // DDRB = DDRB & (~(1 << 4)); // DDRB &= ~(1 << PB4); // pinMode(buttonPin, INPUT); 
}

void loop() {
  byte mask = B00010000; // mask = 1 << 4; // mask = 1 << PB4; // створюємо "маску"  
  buttonState = (PINB & mask) >> PB4; // buttonState = digitalRead(buttonPin);

  if (buttonState == 1) {
    PORTB |= 1 << PB5; //PORTB |= 1<<5; // встановити "1" на лінії 5 порта B  //digitalWrite(ledPin, HIGH);
  } else {
    PORTB &= ~(1 << PB5); //PORTB &= ~(1<<5); // встановити "0" на лінії 5 порта B  //digitalWrite(ledPin, LOW);
  }
}
