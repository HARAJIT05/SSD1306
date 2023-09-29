#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "eyes.h"

unsigned long lastAnimationTime = 0;
unsigned long animationDelay = 15000; // Increase this value for a slower animation (15 seconds delay)

int mood = 1;
int xp = 16;
int xd = 0;
int step = 0;

void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  Serial.begin(115200);
  Serial.println("Booting");
  delay(5000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

  display.display();
  display.clearDisplay();
  display.display();
}

unsigned char readkey(void) {
  unsigned char ret = 0;
  if (digitalRead(8) == 0) ret = 1;  //izquierda
  if (digitalRead(9) == 0) ret += 2; //arriba
  if (digitalRead(10) == 0) ret += 4; //abajo
  if (digitalRead(11) == 0) ret += 8; //fuego
  return (ret);
}

void loop() {
  unsigned long currentMillis = millis();
  int n;

  // Check if it's time to change the animation
  if (currentMillis - lastAnimationTime >= animationDelay) {
    lastAnimationTime = currentMillis;

    // Randomly select the next animation mood
    mood = random(0, 6);
  }

  int x1, x2;
  x1 = xd + (xp > 16 ? (16 + 2 * (xp - 16)) : xp);
  x2 = 64 + xd + (xp < 16 ? (-16 + (xp * 2)) : xp);

  switch (step) {
    case 0:
      display.clearDisplay();
      if (xp < 6) {
        display.drawBitmap(x1, 8, peyes[mood][2][0], 32, 32, WHITE);
        display.drawBitmap(x2, 8, peyes[mood][1][1], 32, 32, WHITE);
      } else if (xp < 26) {
        display.drawBitmap(x1, 8, peyes[mood][0][0], 32, 32, WHITE);
        display.drawBitmap(x2, 8, peyes[mood][0][1], 32, 32, WHITE);
      } else {
        display.drawBitmap(x1, 8, peyes[mood][1][0], 32, 32, WHITE);
        display.drawBitmap(x2, 8, peyes[mood][2][1], 32, 32, WHITE);
      }
      display.display();
      animationDelay = random(20000, 40000); // Randomize delay between 20 to 40 seconds
      n = 7;
      if (n == 6) {
        step = 1;
      } else {
        step = 2;
      }
      break;

    case 1:
      display.clearDisplay();
      display.drawBitmap(x1, 8, eye0, 32, 32, WHITE);
      display.drawBitmap(x2, 8, eye0, 32, 32, WHITE);
      display.display();
      animationDelay = 5000; // Set a fixed delay for this animation (8 seconds)
      step = 0;
      break;

    case 2:
      n = random(0, 10);
      if (n < 5) xd--;
      if (n > 5) xd++;
      if (xd < -4) xd = -3;
      if (xd > 4) xd = 3;
      animationDelay = 5000;
      step = 0;
      break;
  }
}
