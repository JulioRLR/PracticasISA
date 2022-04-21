#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SSD1306 display(-1);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
    }

  display.display();
  delay(2000);
  display.clearDisplay();
  
  //display.fillRect(0,0,120,60,WHITE);
  //display.drawRect(5,5,110,50,BLACK);
  //display.drawRect(10,10,100,40,BLACK);
  //display.drawRoundRect(0,0,120,64,20,WHITE);
  display.fillRoundRect(0,0,120,64,20,WHITE);
  display.display();
  delay(2000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
