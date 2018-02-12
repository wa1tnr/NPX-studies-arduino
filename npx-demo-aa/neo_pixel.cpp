// Mon Feb 12 12:29:42 UTC 2018

// NeoPixel strip 8x - simple sketch (c) 2013 Shae Erisson

#include <Arduino.h>

#include "neo_pixel.h"
#include <Adafruit_NeoPixel.h> // REQUIRED: https://github.com/adafruit/Adafruit_NeoPixel

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN                1 // arbitrary assignment made for Trinket M0

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS          8 // NeoPixel strip 8x

// When we setup the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int numpixels =  NUMPIXELS;
int position  = 0; // position on the strand of several NeoPixels
int red       = 0;
int green     = 0;
int blue      = 0;

void setup_neoPixel(void) {
    pixels.begin(); // This initializes the NeoPixel library.
    pixels.show();
}

// rgb() is the workhorse of the entire demo program.
void rgb(void) {
    pixels.setPixelColor(position, pixels.Color(red, green, blue));
    pixels.show();
}

