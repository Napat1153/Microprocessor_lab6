#define pinLed 7
int Sec = 0;

void setup()
  {
    Serial.begin(9600);
    Serial.println("START");
    pinMode(pinLed, OUTPUT);
  }

void loop()
  {
    if(Sec > 120)
    {
      digitalWrite(pinLed,LOW);
      delay(500);
    }
    else if(Sec%2==0)
    {
      digitalWrite(pinLed, HIGH);
      delay(1000);
      digitalWrite(pinLed, LOW);
      delay(1000);
      Serial.println(Sec);
      Sec = Sec+2;
    }
    if(Sec == 120)
    {
      Serial.print("STOP");
    }
  }
