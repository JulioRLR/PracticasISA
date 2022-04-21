#include <Servo.h>

Servo servo;  

int potenciometro = A0; 
int valor;   

void setup() {
servo.attach(9);  

}

void loop() {
  
valor = analogRead(potenciometro);
valor = map(valor, 0, 1023, 0, 180);
servo.write(valor);

delay(20);

}
