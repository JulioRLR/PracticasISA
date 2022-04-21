#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temperatura;
int ventilador = 5;
int boton = 3;
int maxtemp = 28;
long tiempo_anterior;
long diferencia;
bool estado_pulsador;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(boton, INPUT);
  pinMode(ventilador, OUTPUT) ;
  attachInterrupt(digitalPinToInterrupt(boton),consulta_estado, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensors.requestTemperatures();
    temperatura = sensors.getTempCByIndex(0);
    if(temperatura > maxtemp && estado_pulsador == true){
      digitalWrite(ventilador,HIGH);
      Serial.println(">>Ventilador prendido <<");
      }else{ 
        digitalWrite(ventilador,LOW);
        }
    Serial.println("La temperatura es:"+ String(temperatura));
    delay(100);
}
void consulta_estado(){
  diferencia = millis() - tiempo_anterior;
  tiempo_anterior = millis();

  if(diferencia > 500){
    
    if(digitalRead(ventilador) == true){
      digitalWrite(ventilador ,LOW);
      Serial.println("VENTILADOR APAGADO");
      estado_pulsador = false;
      delay(500);
    }else {
      digitalWrite(ventilador,HIGH);
      estado_pulsador = true;
      Serial.println("VENTILADOR ENCENDIDO");
      delay (500);
    }
  }
}
