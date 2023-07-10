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

void Image::polaroid(int border, int space) {
    width = width + (2*border);
    height = height + space + border;

    PixelMatrix polaroidPixels(height, width);
    polaroidPixels.transfer(&pixels, border, space);

    pixels.copy(&polaroidPixels);

}

void Image::print(string destiny) {
    ofstream file(destiny);
    file << type << endl;
    file << width << " " << height << endl;
    file << maxRGBVal << endl;

    // PRINT P6
    if (type == "P6") {
        for (int l = 0; l < height; l++) {
            for (int c = 0; c < width; c++) {
                Pixel p = pixels.getData()[l][c];
                file << p.getRed() << p.getGreen() << p.getBlue();
            }
        }
    } else if(type == "P3") {
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

void Image::writeLetter(const Glyph *letter, int x, int y) {
    for (int l = 0; l < letter->get_height(); l++) {
        for (int c = 0; c < letter->get_width(); c++) {
            if (letter->get_bit(c, l)) {
                Pixel p(0, 0, 0);
                pixels.getData()[l + y][c + x] = p;
            }
        }
    }
}

void Image::writeMessage(string message, Font *f) {
    int x = width*2/100;
    int y = height*90/100;

    for(char& c : message) {
        const Glyph *current = (*f).get_glyph(c);
        // cout << c << ": " << "offsetX: " << current->get_x_offset() << " | width: " << current->get_width() << " | deviceX: " << current->get_device_width_x() << endl;
        writeLetter(current, x, y);

        x += current->get_device_width_x();
    }
    
}