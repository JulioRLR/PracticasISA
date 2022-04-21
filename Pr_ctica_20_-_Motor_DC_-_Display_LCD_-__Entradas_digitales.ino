#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SSD1306 display(-1);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

const byte motorIzquierdoA=11;
const byte motorIzquierdoB=12;
const byte enableIzquierdo=6;
byte vel=0;
int botonMas = 3;
int botonMenos = 2;
byte velInicial = 0;
boolean sentido = true;
long tiempo;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
                                                                                                                                                                                                                                                                                                                                                                            
  // Clear the buffer
  
  pinMode(motorIzquierdoA,OUTPUT);
  pinMode(motorIzquierdoB,OUTPUT);
  pinMode(botonMas,INPUT);
  pinMode(botonMenos,INPUT);
  attachInterrupt(digitalPinToInterrupt(botonMas),aumentar,CHANGE);
  attachInterrupt(digitalPinToInterrupt(botonMenos),disminuir,CHANGE);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println("Girando " + giro());
  display.setCursor(10,20);
   display.println("V=" + String(velInicial));
   switch(velInicial){
    case 130:
      display.fillRect(0,59,128,1,WHITE);
      break;
    case 150:
      display.fillRect(0,52,128,1,WHITE);
      break;
    case 170:
      display.fillRect(0,44,128,1,WHITE);
      break;
    case 190:
        display.fillRect(0,36,128,1,WHITE);
      break;
    case 210:
        display.fillRect(0,28,128,1,WHITE);
      break;
    case 230:
        display.fillRect(0,20,128,1,WHITE);
      break;
    case 250:
        display.fillRect(0,12,128,1,WHITE);
      break;
  }
  display.display();
  control_izq(sentido,velInicial);

}

void control_izq(bool sent, byte vel){
  if(sent){
    digitalWrite(motorIzquierdoA,HIGH);
    digitalWrite(motorIzquierdoB,LOW);
  }
  else{
    digitalWrite(motorIzquierdoA,LOW);
    digitalWrite(motorIzquierdoB,HIGH);
  }
  analogWrite(enableIzquierdo,vel);
}

String giro(){
  if(sentido)
    return "Adelante";
  else
    return "Atras";
}

void aumentar(){
  long diferencia;
  diferencia = millis() - tiempo;
  tiempo = millis();
  if(diferencia > 500){
    if(velInicial == 0){
      velInicial = 130;
      sentido = true;
    }
    else{
      velInicial += 20;  
    }
  }
}

void disminuir(){
  long diferencia;
  diferencia = millis() - tiempo;
  tiempo = millis();
  if(diferencia > 500){
    if(velInicial == 0){
      velInicial = 130;
      sentido = false;
    }
    else{
      velInicial -=20;
      
      if(velInicial < 130 && !sentido){
        control_izq(true,0);
        delay(1500);
        velInicial=130;
        sentido = true;
      }
      else if(velInicial <130 && sentido){
        control_izq(true,0);
        delay(1500);
        velInicial=130;
        sentido = false;
      }
    }
  }
}
