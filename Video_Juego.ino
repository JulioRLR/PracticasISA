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

int boton = 2;
int potenciometro = A0;
int poten = 0;
int puntos;
int nivel;
int vida;
int mover;
int limite;
int pixelInicio;

boolean iniciar=false;
boolean bajar=false;


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds
                                                                                                                                                                                                                                                                                                                                                                            
  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,30);
  display.println("PRESS START");
  display.display();
  
  pinMode(boton,INPUT);
  attachInterrupt(digitalPinToInterrupt(boton),start,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(iniciar==true){
      if(vida < 1){
        iniciar = false;
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(35,35);
        display.println("GAME OVER");
        display.display();
        delay(2000);
        reiniciar();
    }
      
    else{
        switch(puntos){
          case 2:
            nivel=2;
            break;
          case 4:
            nivel=3;
            break;
          case 6:
            nivel=4;
            break;
         }
      if(!bajar){
        limite=5;
        pixelInicio = random(5,125);
        bajar = true;
      }
      else{
        delay(100);
        pixelInicio = random(pixelInicio-5,pixelInicio+5);
      }
     
      display.clearDisplay();
  
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println(" P:" + String(puntos) + "    N:" + String(nivel) + "    V:" + String(vida));
      display.drawPixel(pixelInicio,limite,WHITE);
  
      limite=limite+(2*nivel);
    
      mover = analogRead(potenciometro)/10;
    
      display.drawLine(mover, 60, mover+22, 60, WHITE);
  
      if(limite >= 60){
        if(pixelInicio >= mover && (pixelInicio <= (mover+22))){
          puntos++;
        }
        else{
          vida--;
        }
        bajar = false;
      }
    
      display.display(); 
    }
  }

}
void start(){
  if(iniciar==false){
    vida = 5;
    nivel = 1;
    puntos = 0;
    
    iniciar=true;
  }
  
 
}


void reiniciar(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35,22);
  display.println("PRESS START");
  display.display();
 

}
