#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "pixel.h"

using namespace std;

/**
 * Classe que representa um arquivo de imagem.
 */

class Image {
    int width;
    int height;
    Pixel *pixels[];

public:

    Image(int w, int h, Pixel *data);
    ~Image();

    int getWidth();
    int getHeight();
    Pixel** getData();


};

#endif  // IMAGE_H