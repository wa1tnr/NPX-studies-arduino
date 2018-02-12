// Mon Feb 12 00:47:48 UTC 2018

// NeoPixel strip 8x - simple sketch (c) 2013 Shae Erisson

#include <Arduino.h>
#include "src/periph/neo_pixel.h"

extern int genA;
extern int genB;
extern int genC;
extern int genD;

void color_berry(void) {
    genB = 7;
    genC = 0;
    genD = 1;
}

void color_grape(void) {
    genB = 1;
    genC = 0;
    genD = 7;
}

void color_blue(void) {
    genB = 0;
    genC = 0;
    genD = 11;
}

void color_cyan(void) {
    genB = 0;
    genC = 1;
    genD = 1;
}

void setup(void) {
    setup_neoPixel();


    genA = 0; // pixel number on the strip, starting with zero
    color_grape(); // desired color tuple
    _rgb(); // execute 'rgb'


    genA = 1; // another pixel number
    color_berry(); // desired color
    _rgb(); // exec

    genA = 2; // pixel number
    color_blue();
    _rgb();

    genA = 3; // pixel number
    color_cyan();
    _rgb();
}

void loop(void) {}
