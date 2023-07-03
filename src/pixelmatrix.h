#ifndef __PIXELMATRIX_H__
#define __PIXELMATRIX_H__

#include <iostream>
#include "pixel.h"

using namespace std;

/**
 * Classe que representa uma matriz dinâmica de pixels.
 */

class PixelMatrix {
    int lines;
    int columns;
    int size;
    int length;
    int filledLines;
    int filledColumns;
    Pixel **data;

public:
    PixelMatrix();

    PixelMatrix(int l, int c);

    ~PixelMatrix();

    void add(Pixel p);
    void copy(PixelMatrix *pm);
    void transfer(PixelMatrix* pm, int border, int space);

    Pixel** getData();
    int getLength();
    int getSize();
    int getLines();
    int getColumns();


};

#endif  // PIXELMATRIX_H