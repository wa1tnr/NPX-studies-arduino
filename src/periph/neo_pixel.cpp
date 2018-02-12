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
  #define PIN                1 // arbitrary assignment? Trinket M0
#else
  #ifndef PIN // sieve fall-through clause
    #define PIN              2 // arbitrary assignment to non-specific board
  #endif
#endif // 15 Jan 2018

// How many NeoPixels are attached to the Arduino?

#undef NUMPIXELS

// local condition: NeoPixel 8 strip connected to Trinket M0:
#ifdef ADAFRUIT_TRINKET_M0
  #define NUMPIXELS          8 // NeoPixel strip 8x
#else
    #ifndef NUMPIXELS          // sieve fall-through clause
       #define NUMPIXELS     1 // other Adafruit SAMD21 boards
    #endif                     // Not zero - some other define can remove this code entirely
#endif // 15 Jan 2018

// When we setup the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int neoPixelNumber = 0; // zero is a legal value and names the first pixel in the string

int genA = 0;
int genB = 7;
int genC = 0;
int genD = 1;
int genE = 0;

void setup_neoPixel(void) {
  pixels.begin(); // This initializes the NeoPixel library.
}

/*
void _npx(void) { // ( pixel_number_in_string -- )
  neoPixelNumber = dStack_pop(); // set a global to TOS, destructively
}

void _npx_fetch(void) { // ( -- npx_number )
  dStack_push(neoPixelNumber);
}
*/


void _rgb(void) { // ( red green blue -- )
    int i = 0; // this may be the neoPixel 'number' on a string of neoPixels
    // _rgbp();
    // _npx_fetch();
    // pixels.setPixelColor(dStack_pop(), pixels.Color(dStack_pop(), dStack_pop(), dStack_pop()));
    pixels.setPixelColor(genA, pixels.Color(genB, genC, genD));
    pixels.show();
}

/*
void _darkNPX(void) { // darken the neoPixel
  dStack_push(0);
  dStack_push(0);
  dStack_push(0);
  _rgb();
}


void _cyan(void) {
    dStack_push(0);   // red
    dStack_push(1);  // green
    dStack_push(1);  // blue
    _rgb();
}

void _orange(void) {
    dStack_push(155); // red
    dStack_push(11);  // green
    dStack_push(0);   // blue
    _rgb();
}


void _blue(void) {
    dStack_push(0);   // red
    dStack_push(0);   // green
    dStack_push(254); // blue
    _rgb();
}

void _dullMagenta(void) {
    dStack_push(1);   // red
    dStack_push(0);   // green
    dStack_push(1);   // blue
    _rgb();
}

// showboat: do a bunch of different things with npx, in sequence:

void neoPixel(void) { // ainsuForth: invoke using the 'pixel' word
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){ // i=0 originally

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(1,0,0)); // Red
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).

    pixels.setPixelColor(i, pixels.Color(0,1,0)); // Green
    pixels.show();
    delay(delayval);

    pixels.setPixelColor(i, pixels.Color(0,0,1)); // Blue
    pixels.show();
    delay(delayval);

    _orange();
    delay(delaySval);

    _blue();
    delay(delaySval);

    _orange();
    delay(delaySval);

    _blue();
    delay(delaySval);
    _cyan();

  }
}

const char pixel_str[] = "pixel"; // local idiom ainsuForth
void _pixel(void) {
    neoPixel();
}

*/
