// Project 33 - Addressing Areas on the Touchscreen

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#define TFT_CS        10
#define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         8

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int x,y = 0;

 int readX() // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);  // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr=analogRead(0);       // stores the value of the x-axis
  return xr;
}

 int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);  // set A0 to GND
  digitalWrite(16, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1);       // stores the value of the y-axis
  return yr; 
}

void setup()
{
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  tft.init(240, 320);
  tft.fillScreen(ST77XX_BLACK);
  Serial.println(F("Initialized"));

tft.invertDisplay(true);

  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);
}

void loop()
{
 //tft.drawPixel(tft.width()/2, tft.height()/2, ST77XX_GREEN);
 //240 x and 320 y
  //tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");

  Serial.print(" x = ");
  x=readX();
  x=(x-79)/3;
   Serial.print(x);
  y=readY();
  y=240-((y-99)/3.7);
  Serial.print(" y = ");
   Serial.println(y);
  delay (200);

  

  tft.drawPixel(y , x , ST77XX_GREEN);
  //delay(500);
}