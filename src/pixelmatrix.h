#ifndef __PIXELMATRIX_H__
#define __PIXELMATRIX_H__

#include "pixel.h"

using namespace std;

/**
 * Classe que representa uma matriz dinâmica de pixels.
 */

class PixelMatrix {
    int lines;
    int columns;
    Pixel **data;



public:

    PixelMatrix();

    PixelMatrix(int l, int c) {
        lines = l;
        columns = c;
        data = new Pixel*[lines];

        for (int i = 0; i < lines; i++) {
            data[i] = new Pixel[columns];
        }

    }


};

#endif  // PIXELMATRIX_H