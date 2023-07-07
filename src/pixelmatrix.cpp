#include "pixelmatrix.h"

PixelMatrix::PixelMatrix() {
    lines = 10;
    columns = 10;
    size = 100;
    filledLines = 0;
    filledColumns = 0;
    length = 0;
    
    data = new Pixel*[lines];
    for (int i = 0; i < lines; i++) {
        data[i] = new Pixel[columns];
    }
}

PixelMatrix::PixelMatrix(int l, int c) {
    lines = l;
    columns = c;
    size = lines * columns;
    filledLines = 0;
    filledColumns = 0;
    length = filledLines + filledColumns;

    data = new Pixel*[lines];
    for (int i = 0; i < lines; i++) {
        data[i] = new Pixel[columns];
    }
}

PixelMatrix::~PixelMatrix() {
    for (int i = 0; i < lines; i++) {
        delete[] data[i];
    }

    delete[] data;
}

void PixelMatrix::add(Pixel p) {
    if (length == size) {
        // Declara novos tamanhos para s linhas e colunas da matriz
        int newLines = 2*lines;
        int newColumns = 2*columns;

        // Inicializa um ponteiro com dimensões maiores do que o original, para substituí-lo
        Pixel **newData = new Pixel*[newLines];
        for (int i = 0; i < newLines; i++) {
            newData[i] = new Pixel[newColumns];
        }

        // Copia os valores da matriz inicial para a nova
        for (int l = 0; l < lines; l++) {
            for (int c = 0; c < columns; c++) {
                newData[l][c] = data[l][c];
            }
        }

        // Libera a memória ocupada pela matriz original
        for (int i = 0; i < lines; i++) {
            delete[] data[i];
        }
        delete[] data;

        // Aponta o ponteiro original para a nova matriz, e incrementa o valor da variavel tamanho
        data = newData;
        size = newLines * newColumns;
        lines = newLines;
        columns = newColumns;
    }

    // Adiciona novo pixel
    data[filledLines][filledColumns] = p;
    
    if (filledColumns == columns - 1) {
        filledColumns = 0;
        filledLines++;
    } else {
        filledColumns++;
    }
    
    length++;


}

void PixelMatrix::copy(PixelMatrix *pm) {
    if ((*pm).getLines() != lines || (*pm).getColumns() != columns) {
        // Declara novos tamanhos para s linhas e colunas da matriz
        int newLines = (*pm).getLines();
        int newColumns = (*pm).getColumns();

        // Inicializa um ponteiro com dimensões maiores do que o original, para substituí-lo
        Pixel **newData = new Pixel*[newLines];
        for (int i = 0; i < newLines; i++) {
            newData[i] = new Pixel[newColumns];
        }

        // Libera a memória ocupada pela matriz original
        for (int i = 0; i < lines; i++) {
            delete[] data[i];
        }
        delete[] data;

        // Aponta o ponteiro original para a nova matriz, e incrementa o valor da variavel tamanho
        data = newData;
        size = newLines * newColumns;
        lines = newLines;
        columns = newColumns;
    }

    // Clona a matriz
    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
            Pixel newPx = (*pm).getData()[l][c];
            data[l][c] = newPx;
        }
    }
}

void PixelMatrix::transfer(PixelMatrix* pm, int border, int space) {
    // Transfere

    for (int l = 0; l < lines; l++) {
        for (int c = 0; c < columns; c++) {
            Pixel newPx(255, 255, 255);
            data[l][c] = newPx;   
        }
    }

    for (int l = border; l < lines - space; l++) {
        for (int c = border; c < columns - border; c++) {
            Pixel newPx = (*pm).getData()[l - border][c - border];
            data[l][c] = newPx;
        }
    }

}

Pixel** PixelMatrix::getData() { return data; }
int PixelMatrix::getLength() { return length; }
int PixelMatrix::getSize() { return size; }
int PixelMatrix::getLines() { return lines; }
int PixelMatrix::getColumns() { return columns; }
