#include "pixel.h"

Pixel::Pixel() {
    red = 0;
    green = 0;
    blue = 0;
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b) {
    red = r;
    green = g;
    blue = b;
}

unsigned char Pixel::getRed() {
    return red;
}

unsigned char Pixel::getGreen() {
    return green;
}

unsigned char Pixel::getBlue() {
    return blue;
}