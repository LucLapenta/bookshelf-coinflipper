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

void displayText(const char* text, int delayMs=0, int textSize=2, int xCoord=0, int yCoord=0);

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed."));
    for(;;); // failed init, loop forever
  }

  display.clearDisplay();

  // use PULLUP mode so default value is HIGH (3.3V), then when button is pressed the value goes to LOW (0V)
  pinMode(switchPin, INPUT_PULLUP);
  randomSeed(rp2040.hwrand32());
}

void loop() {
  
  displayText("Press to \nFlip", 500);

  switchValue = digitalRead(switchPin);
  
  // check for transition from LOW to HIGH for button release
  if(switchValue == 1 && lastSwitchValue == 0) {
    displayFlippingAnimation();   
    displayResult();
    delay(5000);
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
  int randomNumber = random(100);
  if(randomNumber > 50) {
    displayText("HEADS");
    display.drawBitmap(
      44,
      18,
      epd_bitmap_allArray[0],
      40,
      40,
      1
    );
  }
  else {
    displayText("TAILS");
    display.drawBitmap(
      44,
      18,
      epd_bitmap_allArray[5],
      40,
      40,
      1
    );
  }
  display.display();
  return;
}

void displayText(const char* text, int delayMs, int textSize, int xCoord, int yCoord) {
  display.clearDisplay();
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(xCoord, yCoord);
  display.println(F(text));
  display.display();
  delay(delayMs);
}
