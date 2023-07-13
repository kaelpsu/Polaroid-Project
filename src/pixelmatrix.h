#ifndef __PIXELMATRIX_H__
#define __PIXELMATRIX_H__

#include <iostream>
#include "pixel.h"

using namespace std;

/**
 * Classe que representa uma matriz dinâmica de pixels.
 */
class PixelMatrix {
    int lines; // linhas (altura)
    int columns; // colunas (largura)
    int size; // capacidade
    int length; // espaço utilizado
    int filledLines; // linhas utilizadas
    int filledColumns; // colunas utilizadas
    Pixel **data; // armazena ponteiros para a matriz

public:
    PixelMatrix();

    PixelMatrix(int l, int c);

    ~PixelMatrix();

    /**
     * Adiciona um pixel à matriz.
     * @param p pixel a ser adicionado
     */
    void add(Pixel p);

    /**
     * Iguala esta matriz à recebida como argumento.
     * @param pm ponteiro da matriz a ser copiada
     */
    void copy(PixelMatrix *pm);

    /**
     * Transfere, para esta matriz, o conteúdo de uma outra, sem alterar
     * as dimensões desta. (Cria o modelo polaroid com base nos valores de borda e espaço).
     * @param pm ponteiro da matriz a ser copiada
     * @param border valor da borda branca da imagem final
     * @param space valor da base branca da imagem final
     */
    void transfer(PixelMatrix* pm, int border, int space);

    /** Consulta o conteúdo da matriz. */
    Pixel** getData();

    /** Consulta o espaço preenchido da matriz. */
    int getLength();

    /** Consulta a capacidade da matriz. */
    int getSize();

    /** Consulta a altura da matriz. */
    int getLines();

    /** Consulta a largura da matriz. */    
    int getColumns();


};

#endif  // PIXELMATRIX_H