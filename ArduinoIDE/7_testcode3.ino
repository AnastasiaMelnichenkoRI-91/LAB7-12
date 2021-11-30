const byte helloSegments[] = {
0x76, // H
0x79, // E
0x38, // L
0x38, // L
0x5C, // o
0x00 // нічого
};
int len = sizeof(helloSegments);
const long myDelay = 500;
void myF(int i, int &num)
{
PORTB |= ~PORTB; //PORTB = B111111; // встановлюємо високий рівень на пінах 8-13 порта В
PORTB &= ~(1 << num); // встановлюємо низький рівень піна порта В
int index = i - num >= 0 ? i - num : len - 1;
index = index < len ? index : len - 1;
PORTD = helloSegments[index];
delay(1);
num = (num + 1) % 4;
}
void setup() {
DDRD = B11111111; // піни порту D (на платі 0-7 піни) позначаєм вихідними
DDRB = B111111; // піни порту B (на платі 8-13 піни) позначаєм вихідними
PORTB = B111111; // встановлюємо високий рівень пінів порта В (на платі 8-13 піни)
}
void loop() {
for (int i = 0; i< len + 4; i++)
{
int num = 0;
long myTime = millis();
delay(1);
while (millis() - myTime < myDelay)
{
myF(i, num);
}
}
}
