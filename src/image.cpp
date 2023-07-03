#include "image.h"

Image::Image(string t, int w, int h, int mx, PixelMatrix* data) {
    type = t;
    width = w;
    height = h;
    maxRGBVal = mx;
    pixels.copy(data);
}

string Image::getType() {
    return type;
}

int Image::getWidth() {
    return width;
}

int Image::getHeight() {
    return height;
}

int Image::getMaxRGB() {
    return maxRGBVal;
}

void Image::print(string destiny) {
    ofstream file(destiny);
    file << type << endl;
    file << height << " " << width << endl;
    file << maxRGBVal;

    // PRINT P6
    if (type == "P6") {
        for (int l = 0; l < height; l++) {
            for (int c = 0; c < width; c++) {
                Pixel p = pixels.getData()[l][c];
                file << p.getRed() << p.getGreen() << p.getBlue();
            }
        }
    } else if(type == "P3") {
        file << endl;
        // PRINT P3
        for (int l = 0; l < height; l++) {
            for (int c = 0; c < width; c++) {
                Pixel p = pixels.getData()[l][c];
                file << int(p.getRed()) << " " << int(p.getGreen()) << " " << int(p.getBlue()) << " ";

                if (c + 1 == height) {
                    file << endl;
                }
            }
        }
    }


    

}