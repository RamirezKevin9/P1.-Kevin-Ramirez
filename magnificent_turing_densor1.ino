#define R 6
#define A 5
#define V 3
void setup()
{
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(V, OUTPUT);
  Serial.begin(9800);
}
  

void loop()
{

  for (int i = 1; i <= 255; i++){
     analogWrite(R,i);
     for(int x = 1; x <= 255; x++){
      analogWrite(A,x);
      for(int z = 1; z <= 255; z++){
      analogWrite(V,z);
      }
    }
  }
}