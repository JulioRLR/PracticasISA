int led = 5;
int boton = 3;
bool estado_pulsador;
long tiempo_anterior;
long tiempo_actual;
long diferencia;
void setup(){
  Serial.begin(9600);

  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(boton),consulta_estado, CHANGE); //Pin que escucha (2 o 3 para interrupciones) , acción , definir la función que se va a realizar
}

void loop(){
  
}

void consulta_estado(){
  diferencia = millis()-tiempo_anterior;
  tiempo_anterior = millis();
  if(diferencia > 500){
    if(digitalRead(led)==true){
      digitalWrite(led,LOW);
      Serial.println(">> APAGADO <<");
      delay(500);
     }else {
      digitalWrite(led,HIGH);
      Serial.println(">> ENCENDIDO <<");
      delay(500);
     }
  }
}
