#include "libNixieModule.h"
#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define ADDR0 0x4F
#define ADDR1 0x4D

#define NIX_DOT_A A0
#define NIX_DOT_B A1
#define PIN_LED 6

NixieModule_IN_14 nix0 = NixieModule_IN_14(ADDR0);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, PIN_LED, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("nix module IN-14 Single Tube Demo");
  nix0.init();

  nix0.setTransitionMode(TMODE_NORMAL);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t step = 100;
  Serial.println("Normal transition mode");

  step = 100;
  nix0.setTransitionMode(TMODE_FADE);
  
  for(int i=0; i<10; i++){
    Serial.println(i);
    nix0.setNumber(i, step);

    for(int j=0; j<step; j++){
      nix0.update();

      delay(2);
    }
    delay(500);
  }

  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  delay(1000);

}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

