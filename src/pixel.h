#ifndef __PIXEL_H__
#define __PIXEL_H__

using namespace std;

/**
 * Classe que representa um pixel.
 */

class Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;

public:

    Pixel();

    Pixel(unsigned char r, unsigned char g, unsigned char b);

    unsigned char getRed();

    unsigned char getGreen();

    unsigned char getBlue();

};

#endif  // PIXEL_H