int led = 3;
int luz;
int potencia;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  luz = analogRead(potencia);
  analogWrite(led,luz);
}
