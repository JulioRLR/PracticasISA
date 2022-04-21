int Verde=2;
int Amarillo=4;
int Rojo=7;
void setup() {
  pinMode(Verde,OUTPUT);
  pinMode(Amarillo,OUTPUT);
  pinMode(Rojo,OUTPUT);
}

void loop() {
  //Verde
  digitalWrite(Verde,HIGH);
  delay(5000);
  digitalWrite(Verde,LOW);
  delay(500);
  digitalWrite(Verde,HIGH);
  delay(500);
  digitalWrite(Verde,LOW);
  delay(500);
  //Amarillo
  digitalWrite(Amarillo,HIGH);
  delay(3000);
  digitalWrite(Amarillo,LOW);
  //Rojo
  digitalWrite(Rojo,HIGH);
  delay(5000);
  digitalWrite(Rojo,LOW);
}
