#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "pixel.h"
#include "pixelmatrix.h"
#include "font.h"
#include "glyph.h"

using namespace std;

/**
 * Classe que representa um arquivo de imagem.
 */
class Image {
    string type; // tipo do arquivo ppm
    int width; // largura da imagem
    int height; // altura da imagem
    int maxRGBVal; // valor de rgb máximo
    PixelMatrix pixels; // matriz de pixels

public:

    Image(string t, int w, int h, int mx, PixelMatrix* data);

    /** Consulta o tipo do arquivo. */
    string getType();

    /** Consulta largura da imagem. */
    int getWidth();

    /** Consulta a altura da imagem. */
    int getHeight();

    /** Consulta valor rgb máximo. */
    int getMaxRGB();

    /**
     * Aplica o modelo polaroid na imagem a partir dos valores
     * de borda e espaço especificados
     * @param border espaçamento das bordas laterais e superior.
     * @param space espaçamento da borda inferior.
     */
    void polaroid(int border, int space);

    /**
     * Escreve uma letra na imagem, tendo como referência a posição
     * (x,y) na matriz de pixels.
     * @param letter glifo com os dados da letra a ser escrita.
     * @param x posição x da mensagem.
     * @param y posição y da mensagem.
     */
    void writeLetter(const Glyph *letter, int x, int y);

    /**
     * Escreve a mensagem completa na imagem.
     * @param message conteúdo da mensagem.
     * @param f ponteiro para o objeto contendo a fonte.
     */
    void writeMessage(string message, Font *f);

    /**
     * Escreve os dados da imagem em um novo arquivo que será salvo
     * no caminho especificado. (Salva a imagem alterada)
     * @param destiny caminho para salvar a imagem polaroid.
     */
    void print(string destiny);

};

#endif  // IMAGE_H