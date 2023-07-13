#ifndef __PIXEL_H__
#define __PIXEL_H__

using namespace std;

/**
 * Classe que representa um pixel.
 */
class Pixel {
    // valores rgb do pixel.
    unsigned char red;
    unsigned char green;
    unsigned char blue;

public:

    Pixel();

    Pixel(unsigned char r, unsigned char g, unsigned char b);

    /** Consulta o valor do vermelho no pixel. */
    unsigned char getRed();

    /** Consulta o valor do verde no pixel. */
    unsigned char getGreen();

    /** Consulta o valor do azul no pixel. */
    unsigned char getBlue();

};

#endif  // PIXEL_H