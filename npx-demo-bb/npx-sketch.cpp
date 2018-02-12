// Mon Feb 12 09:15:01 UTC 2018

// NeoPixel strip 8x -  portions are (c) 2013 Shae Erisson

#include <Arduino.h>
#include "src/periph/neo_pixel.h"

// 61 void rgb(void) {
// 62     pixels.setPixelColor(position, pixels.Color(red, green, blue));
// 63     pixels.show();
// 64 }

extern int numpixels; // how many neopixels are on the strip
extern int position;  // every neopixel has a unique position number, starting with zero
extern int red;       // 0 thru 255 - input value to rgb()
extern int green;     // 0 thru 255
extern int blue;      // 0 thru 255
extern int wheelIn;   // 0 thru 255 - input value to the Wheel() function

void color_alldark(void) {
    red   = 0;
    green = 0;
    blue  = 0;
}

void color_berry(void) {
    red   = 7;
    green = 0;
    blue  = 1;
}

void color_grape(void) {
    red   = 1;
    green = 0;
    blue  = 7;
}

void color_blue(void) {
    red   = 0;
    green = 0;
    blue  = 11;
}

void color_cyan(void) {
    red   = 0;
    green = 1;
    blue  = 1;
}


void ouch(void) { // too bright for my eyes. Turn everthing off.
    color_alldark();
    for (int i = 0; i < (numpixels + 1); i++) {
        position = i;
        rgb();
    }
}

void rainbowMarch(void) {
    for (int i = 0; i < (numpixels + 1); i++) {
        int mult = 35; // a multiplier

        position = i;
        wheelIn = i * mult ; // when evaluated must fall within the range: 0 to 255
        rgbWheel();
        delay(2000);
    } 
}


/* ****************************************************** */
/* ***                                                *** */
/* ***                       setup                    *** */
/* ***                                                *** */
/* ****************************************************** */
void setup(void) {
    setup_neoPixel();

    position = 0;  // pixel number on the strip, starting with zero
    color_grape(); // desired color tuple - no exec, just data
    rgb();         // set the neopixel at position to current values for red green blue

    position = 1;
    color_berry();
    rgb();

    position = 2;
    color_blue();
    rgb();

    position = 3;
    color_cyan();
    rgb();         // rgb() directly sets the color


    // - - - - - - - - - - - - - - - - - - - - - - - -

    // change the color based on a color mapping function, Wheel()

    position = 4;
    wheelIn = 33;  // data - all possible rgb colors are expressed by this single integer
    rgbWheel();    // rgbWheel() calls Wheel() which maps, then sets the color

    position = 5;
    wheelIn = 88;
    rgbWheel();

    position = 6;
    wheelIn = 122;
    rgbWheel();

    position = 7;
    wheelIn = 211;
    rgbWheel();

    delay(5000);   // provide a moment to appreciate current display
    ouch();

    delay(3000);
    rainbowMarch();

    delay(4000);
    ouch();
}


// single-shot, do not do anything interesting in the loop
void loop(void) {
    delay(1000); // no real reason to populate this loop at all
}

