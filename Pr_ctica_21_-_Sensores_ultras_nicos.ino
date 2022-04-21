#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(-1);
const byte trigg = 3;
const byte echo = 2;
int distancia;
int i=0;
void setup() {
  Serial.begin(9600);
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigg,LOW);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  reseteo();
  display.drawPixel(i,(64-mide_distancia()),WHITE);
  display.fillRect(0,0,128,7,BLACK);
  delay(100);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,0);
  display.println("D: " + String(mide_distancia()));
  display.display();
}
void reseteo(){
  i++;
  if(i==128){
    display.clearDisplay();
    i=0;
  }
}
int mide_distancia(){
  gatillo();
  long tiempo = pulseIn(echo,HIGH);
  int distancia = tiempo / 58;
  return distancia;
}

void gatillo(){
  digitalWrite(trigg,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg,LOW);
}
