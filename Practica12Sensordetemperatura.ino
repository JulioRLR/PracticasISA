#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temperatura;
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Inicio Sensor de temperatura Dallas");
}
void loop(void)
{ 
  sensors.requestTemperatures();
  temperatura = sensors.getTempCByIndex(0);
  Serial.println("La temperatura es:"+ String(temperatura));
}
