int verde = 2;
int amarillo = 4;
int rojo = 7;
void setup()
{
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);
}
void loop()
{
  luzverde();
  delay(5000);
  apagado();
  delay(500);
  luzverde();
  delay(500);
  apagado();
  delay(500);
  luzverde();
  delay(500);
  luzamarillo();
  delay(3000);
  luzroja();
  delay(5000);
}

void luzverde()
{
  digitalWrite(verde, HIGH);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, LOW);
}

void luzamarillo()
{
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, HIGH);
  digitalWrite(rojo, LOW);
}

void luzroja()
{
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, HIGH);
}
void apagado()
{
  digitalWrite(verde, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(rojo, LOW);
}
