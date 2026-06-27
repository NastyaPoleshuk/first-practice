#include <Arduino.h>
#include <FastLED.h>

#define DATA_PIN 3
#define NUM_LEDS 64

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(200);
}

void loop() {
  FastLED.clear();
  leds[1] = CRGB::Blue; leds[2] = CRGB::Blue; leds[5] = CRGB::Blue; leds[6] = CRGB::Blue;
  for (int i = 8; i <= 23; i++) {
    leds[i] = CRGB::Blue;
  }
  for (int i = 25; i <= 30; i++) {
    leds[i] = CRGB::Blue;
  }
  for (int i = 34; i <= 37; i++) {
    leds[i] = CRGB::Blue;
  }
  leds[43] = CRGB::Blue; leds[44] = CRGB::Blue;
  leds[51] = CRGB::Blue; leds[52] = CRGB::Blue;
  FastLED.show();
  delay(3000);
  for (int wave = 0; wave < 5; wave++) {
    FastLED.clear();
    for (int i = 48; i < 64; i++) { 
      leds[i] = CRGB::Red;
    }
    FastLED.show();
    delay(200);
    FastLED.clear();
    for (int i = 16; i < 48; i++) { 
      leds[i] = CRGB::Green; 
    }
    FastLED.show();
    delay(200);
    FastLED.clear();
    for (int i = 0; i < 24; i++) { 
      leds[i] = CRGB::Purple; 
    }
    FastLED.show();
    delay(200);
  }
  FastLED.clear();
  FastLED.show();
  delay(1000);
  for (int i = 0; i < 8; i++) { leds[i] = CRGB::Red; }
  for (int i = 8; i < 16; i++) { leds[i] = CRGB::Orange; }
  for (int i = 16; i < 24; i++) { leds[i] = CRGB::Yellow; }
  for (int i = 24; i < 32; i++) { leds[i] = CRGB::Green; }
  for (int i = 32; i < 40; i++) { leds[i] = CRGB::Cyan; }
  for (int i = 40; i < 48; i++) { leds[i] = CRGB::Blue; }
  for (int i = 48; i < 64; i++) { leds[i] = CRGB::Purple; }
  FastLED.show();
  delay(4000);
  FastLED.clear();
  FastLED.show();
  delay(1000);
}