#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "pixel.h"
#include "pixelmatrix.h"
#include "glyph.h"

using namespace std;

/**
 * Classe que representa um arquivo de imagem.
 */

class Image {
    string type;
    int width;
    int height;
    int maxRGBVal;
    PixelMatrix pixels;

public:

    Image(string t, int w, int h, int mx, PixelMatrix* data);

    string getType();
    int getWidth();
    int getHeight();
    int getMaxRGB();
    void print(string destiny);
    void polaroid(int border, int space);
    void writeLetter(const Glyph *letter);
    void writeMessage();


};

#endif  // IMAGE_H