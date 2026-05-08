#define buzzer 3
#define v 5
#define r 4
int movi;
void setup()
{
  pinMode(movi,INPUT);
  pinMode(buzzer,OUTPUT);
   pinMode(v, OUTPUT);
    pinMode(r, OUTPUT);
}

void loop()
{
 movi = digitalRead(2);
  if (movi == HIGH){
    digitalWrite(r,HIGH);
    delay(1000);
    digitalWrite(r,LOW);
    tone(buzzer, 1000);
  }
    else{
      digitalWrite(v,HIGH);
      delay(1000);
      digitalWrite(v,LOW);
      noTone(buzzer);
    }
}