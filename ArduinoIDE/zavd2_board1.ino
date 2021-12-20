const byte ledPin = 13;
volatile byte state = LOW;
 
void setup(){
   pinMode(ledPin, OUTPUT);
   pinMode(A0, INPUT_PULLUP);
  // PCMSK0 = B00001111; //d8 - d13
   PCMSK1 = B01111111; //enable PCINT8 (A0)
   PCMSK2 = B11111101; // d0 - f7
   PCIFR = B00000000; // clear all interrupt flags
   PCICR = B00000111; // enable PCIE1 group

   sei();
   // те саме, але по іншому записано:
   //PCMSK1 = 1 << PCINT8;
  // PCIFR = 0;
  // PCICR = 1 << PCIE1;
  Serial.begin(9600);

  
}
 
void loop(){
   
}
 
ISR(PCINT0_vect) {
   state = !state;
    digitalWrite(ledPin, state);
    Serial.println("ISR " + String(state));
}

ISR(PCINT1_vect) {
   state = !state;
   digitalWrite(ledPin, state);
    Serial.println("ISR " + String(state));
  
}

ISR(PCINT2_vect) {
   state = !state;
  
    Serial.println("ISR " + String(state));
    digitalWrite(ledPin, state);
}
