#include "image.h"

Image::Image(int w, int h, Pixel *data[]) {
    width = w;
    height = h;
    // pixels = 

}

Image::~Image() {
    delete[] pixels;
}

int Image::getWidth() {
    return width;
}

int Image::getHeight() {
    return height;
}

Pixel** Image::getData() {
    return pixels;
}