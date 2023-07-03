#ifndef __POLAROID_H__
#define __POLAROID_H__

#include "image.h"

using namespace std;

/**
 * Classe que representa a imagem com o estilo polaroid.
 */

class Polaroid: public Image {
    int border;
    int base;

};

#endif  // POLAROID_H