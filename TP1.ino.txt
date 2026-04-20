#define R1 11
#define V1 10
#define R2 8
#define A2 3
#define V2 9
#define R3 7
#define A3 6
#define V3 5

void setup()
{
  pinMode(R1, OUTPUT);
  pinMode(V1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(V3, OUTPUT);
}

void loop()
{
  analogWrite(R1,255);
  delay(1000);
  analogWrite(R1,0);
  Parpadeo();
  delay(1000);
  digitalWrite(R2,HIGH);
  digitalWrite(A2,HIGH);
  delay(1000);
  digitalWrite(R2,LOW);
  digitalWrite(R2,LOW);
  Parpadeo();
  analogWrite(V3,20);
  analogWrite(A3,20);
  delay(1000);
  analogWrite(V3,0);
  analogWrite(A3,0);
  Parpadeo();
  delay(1000);
}

void Parpadeo()
{
  for (int x = 1; x <= 4;x++){
    analogWrite(R1,255);
    analogWrite(R2,255);
    analogWrite(R3,255);
    analogWrite(V1,40);
    analogWrite(V2,40);
    analogWrite(V3,40);
    delay(100);
    analogWrite(R1,0);
    analogWrite(R2,0);
    analogWrite(R3,0);
    analogWrite(V1,0);
    analogWrite(V2,0);
    analogWrite(V3,0);
    delay(100);
  }
}