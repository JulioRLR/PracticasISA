float numero =  32;
float numero2 =23;
float resultado;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
  resultado = numero/numero2;
  Serial.println("el resultado es:" + String(resultado,2));
}

void loop() {
  // put your main code here, to run repeatedly:

}
