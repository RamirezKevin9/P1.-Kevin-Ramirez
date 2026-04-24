#define R 11
#define A 10
#define V 6
#define PR A0
#define PA A1
#define PV A2
#define Boton 2
int ValorR;
int ValorV;
int Valor A;
bool ValorBoton;

void setup()
{
  pinMode(Boton,INPUT);
  pinMode(R,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(V,OUTPUT);
  Serial.begin(9800);
}

void loop()
{
  ValorBoton digitalRead(Boton);
  delay(100);
  if(ValorBoton == LOW){
   Serial.println("Se prendera en 10 segundos");
    dealy(10000);
    ValorR = analogRead(PR);
    ValorV = analogRead(PV);
    ValorA = analogRead(PA);
    ValorR = map(ValorR,0,1023,0,255);
    ValorA = map(ValorA,0,1023,0,255);
    ValorV = map(ValorV,0,1023,0,255);
    
    Leer();
    Serial.print("El LED esta usando esta config");
    Serial.println(ValorR);
    Serial.println(ValorV);
    Serial.println(ValorA);
    
    PrendeApaga();
  }
  
}

void PrendeApaga(){
 analogWrite(R,ValorR);
 analogWrite(V,ValorV);
 analogWrite(A,ValorA);
 delay(1000);
 analogWrite(R,0);
 analogWrite(V,0);
 analogWrite(A,0);
}

void Leer (){
 ValorR = analogRead(PR);
 ValorV = analogRead(PV);
 ValorA = analogRead(PA);
 ValorR = map(ValorR,0,1023,0,255);
 ValorV = map(ValorV,0,1023,0,255);
 ValorA = map(ValorA,0,1023,0,255);
}