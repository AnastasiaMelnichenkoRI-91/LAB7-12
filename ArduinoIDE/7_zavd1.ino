int j = 0;
int z = 0;
int t = 0;
int s = 0;
int r = 0;
byte numbers[] = {
  0x3F, //0
  0x06, //1
  0x5B, //2
  0x4F, //3
  0x66, //4
  0x6D, //5
  0x7D, //6
  0x07, //7
  0x7F, //8
  0x6F  //9

};

byte helloSegments[] = {
  0x76, // H
  0x79, // E
  0x38, // L
  0x38, // L
  0x5C, // o
  0x3F, //0
  0x3F, //0
  0x3F, //0
  0x3F,  //0
  0x00
};
int len = sizeof(helloSegments);
const long myDelay = 300;

void myF(int i, int &num, int j, int z, int t, int s, int r)
{
  PORTB |= ~PORTB; //PORTB = B111111; // встановлюємо високий рівень на пінах 8-13 порта В
  PORTB &= ~(1 << num); // встановлюємо низький рівень піна порта В
  int index = i - num >= 0 ? i - num : len - 1;
  index = index < len ? index : len - 1;
  if (j == 0)
  {
    PORTD = helloSegments[index];
  }
  else if (j > 0 && j <= 9)
  {
    helloSegments[8] = numbers[z];
    PORTD = helloSegments[index];
  }
  else if (j > 9 && j <= 99)
  {
    helloSegments[8] = numbers[z];
    helloSegments[7] = numbers[t];
    PORTD = helloSegments[index];
  }
  else if (j > 99 && j <= 999)
  {
    helloSegments[8] = numbers[z];
    helloSegments[7] = numbers[t];
    helloSegments[6] = numbers[s];
    PORTD = helloSegments[index];
  }
  else if (j > 999 && j <= 9999)
  {
    helloSegments[8] = numbers[z];
    helloSegments[7] = numbers[t];
    helloSegments[6] = numbers[s];
    helloSegments[5] = numbers[r];
    PORTD = helloSegments[index];
  }
  delay(1);
  num = (num + 1) % 4;
}


void setup() {
  DDRD = B11111111; // піни порту D (на платі 0-7 піни) позначаєм вихідними
  DDRB = B111111; // піни порту B (на платі 8-13 піни) позначаєм вихідними
  PORTB = B111111; // встановлюємо високий рівень пінів порта В (на платі 8-13 піни)
}

void loop() {

  for (int i = 0; i < len + 4; i++)
  {
    int num = 0;
    long myTime = millis();
    delay(1);
    while (millis() - myTime < myDelay)
    {
      myF(i, num, j, z, t, s, r);
    }

  }
  if (j <= 9999)
  {
    j++;
  }
  else
  {
    j = 0;
  }
  if (z <= 8)
  {
    z++;
  }
  else
  {
    z = 0;
    if (t <= 8)
    {
      t++;
    }
    else
    {
      t = 0;
      if (s <= 8)
      {
        s++;
      }
      else
      {
        s = 0;
        if (r <= 8)
        {
          r++;
        }
        else
        {
          r = 0;
        }
      }
    }
  }
}
