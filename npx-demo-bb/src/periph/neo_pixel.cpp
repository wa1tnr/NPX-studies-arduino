// Mon Feb 12 00:47:48 UTC 2018

// NeoPixel strip 8x - simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Arduino.h>

#include "neo_pixel.h"
#include <Adafruit_NeoPixel.h> // REQUIRED: https://github.com/adafruit/Adafruit_NeoPixel

// Which pin on the Arduino is connected to the NeoPixels?
// #define PIN               1 // Trinket M0 (arbitrarily chosen pin)

#undef PIN

#ifdef ADAFRUIT_TRINKET_M0
  #define PIN                1 // arbitrary assignment made for Trinket M0
#else
  #ifndef PIN // sieve fall-through clause
    #define PIN              2 // any other board - modify this
  #endif
#endif

// How many NeoPixels are attached to the Arduino?

#undef NUMPIXELS

// local condition: NeoPixel 8 strip connected to Trinket M0:
#ifdef ADAFRUIT_TRINKET_M0
  #define NUMPIXELS          8 // NeoPixel strip 8x
#else
    #ifndef NUMPIXELS          // sieve fall-through clause
       #define NUMPIXELS     1 // any other board - modify this
    #endif                     // Not zero - some other define can remove this code entirely
#endif

// When we setup the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// int neoPixelNumber = 0; // zero is a legal value and names the first pixel in the string

int numpixels =  NUMPIXELS;
int position = 0; // position on the strand of several NeoPixels
int red   = 7;
int green = 0;
int blue  = 1;
int wheelIn = 0;

void setup_neoPixel(void) {
    pixels.begin(); // This initializes the NeoPixel library.
    pixels.show();
}

void  rgbWheel(void) { // alias
    pixels.setPixelColor(position, Wheel(wheelIn));
    pixels.show();
}

void rgb(void) {
    pixels.setPixelColor(position, pixels.Color(red, green, blue));
    pixels.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
