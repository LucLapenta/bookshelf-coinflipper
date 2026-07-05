#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "images.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int switchPin = D1;
int switchValue = 1; // start at 1 to match default value of PULLUP pin
int lastSwitchValue = 1;
long randomNumber = 0;

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed."));
    for(;;); // failed init, loop forever
  }

  display.clearDisplay();

  pinMode(switchPin, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop() {
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(F("Press to Flip"));
  display.display();
  delay(500);

  switchValue = digitalRead(switchPin);
  Serial.println(F("Switch value:"));
  Serial.println(switchValue);
  Serial.println(lastSwitchValue);
  
  // check for transition from LOW to HIGH for button release
  if(switchValue == 1 && lastSwitchValue == 0) {
    displayFlippingAnimation();   
    randomNumber = random(100);
    displayResult();
  }
  lastSwitchValue = switchValue;
}

void displayFlippingAnimation() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 9; j++) {
      display.clearDisplay();
      display.drawBitmap(
        44,
        12,
        epd_bitmap_allArray[j],
        40,
        40,
        1
      );
      display.display();
      delay(50);
    }
  }
  return;
}

void displayResult() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  if(randomNumber > 50) {
    display.println(F("HEADS"));
  }
  else {
    display.println(F("TAILS"));
  }
  display.display();
  delay(2500);
  return;
}
