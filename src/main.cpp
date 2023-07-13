#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <fstream>
#include "pixel.h"
#include "pixelmatrix.h"
#include "image.h"
#include "glyph.h"
#include "font.h"

using namespace std;

/**
 * Imprime uma ajuda explicando como o programa deve ser usado.
 * @param program_name Nome do arquivo executável.
 */
void print_usage(string program_name) {
  cerr << "Usage:" << endl;
  cerr << '\t' << program_name << " <argument>" << endl;
  cerr << "Where <argument> can be:" << endl;
  cerr << '\t' << "-h: shows information about the program usage, indicating the valid arguments and what they do." << endl;
  cerr << '\t' << "-i: indicates that the following argument represents the image file path, on which the polaroid effect will be applied." << endl;
  cerr << '\t' << "-o: indicates that the following argument represents the path where the updated image will be saved." << endl;
  cerr << '\t' << "-f: indicates that the following argument represents the path of the font file used to print the message on the image." << endl;
  cerr << '\t' << "-b: indicates the width, in pixels, of the borders that will be added around the image." << endl;
  cerr << '\t' << "-s: indicates the width, in pixels, of the border that will be added under the image." << endl;
  cerr << endl;
}

/**
 * Recebe os valores do arquivo ppm e retorna um objeto imagem com os dados.
 * @param originPath caminho do arquivo da imagem.
 * @param iceCream define se filtro será aplicado ou não.
 */
Image readImage(string originPath, bool iceCream) {
  string type;
  int lines, columns, maxRGBVal;
  char charVal;

  ifstream ppm(originPath); // abre o arquivo ppm original

  // lê as configurações da imagem original.
  ppm >> type >> columns >> lines >> maxRGBVal;

  PixelMatrix data(lines, columns);

  // a leitura da matriz de pixels se dá de forma diferente de acordo com o tipo do arquivo.
  if (type == "P3") {
    for (int l = 0; l < lines; l++) { // Para cada linha faça:
      for (int c = 0; c < columns; c++) { // Para cada coluna faça:
        unsigned char red;
        unsigned char green;
        unsigned char blue;

        for (int p = 0; p < 3; p++) { // Para cada valor RGB no pixel faça:

          // O filtro é aplicado caso a variável iceCream seja verdadeira.
          // Para isso, é adicionado um novo valor rgb no primeiro pixel da imagem,
          // que será interpretado como o red. Assim, todos os outros valores
          // são associados a uma outra cor, mudando a proporação de vermelho, 
          // verde e azul em toda a imagem.
          if (l == 0 && c == 0 && iceCream) {
            red = 0;
            p++;
          }

          int rgb;
          ppm >> rgb; // Recebe o valor de R, G ou B.
          switch (p)
          {
          case 0:
            red = rgb;
            break;
          case 1:
            green = rgb;
            break;
          case 2:
            blue = rgb;
            break;
          default:
            break;
          }
        }

        Pixel px(red, green, blue);
        
        data.add(px);
      }
    }
  } else if (type == "P6") {

    for (int l = 0; l < lines; l++) { // Para cada linha faça:
      for (int c = 0; c < columns; c++) { // Para cada coluna faça:
        char red;
        char green;
        char blue;

        if (l == 0 && c == 0 && !iceCream) {
          ppm.ignore();
        }

        for (int p = 0; p < 3; p++) { // Para cada valor RGB no pixel faça:
          switch (p)
          {
          case 0:
            ppm.get(red);
            break;
          case 1:
            ppm.get(green);
            break;
          case 2:
            ppm.get(blue);
            break;
          default:
            break;
          }
        }

        Pixel px((unsigned char)red, (unsigned char)green, (unsigned char)blue);
        
        data.add(px);
      }
    }
    
  }

  ppm.close();

  Image image(type, columns, lines, maxRGBVal, &data);

  return image;

}

/**
 * Função principal: ponto de partida do programa.
 */
int main(int argc, char *argv[]) {

  if (argc < 2) {
    // se não houver pelo menos 1 argumento, então o programa está sendo usado incorretamente.
    // deve-se portanto imprimir como usá-lo.
    print_usage(argv[0]);
  }
  
  string originPath;
  string destinyPath = "../output_file.ppm";
  string fontPath = "../fonts/ib16x16u.bdf";
  int border = 60; // valor padrão: 60 px
  int space = 120; // valor padrão: 120 px
  bool iceCream = false; // valor padrão: false (sem filtro)

  int option; // armazena as flags utilizadas na linha de comando
  
  // implementa ações específicas para cada argumento fornecido
  // obs: optarg é o parametro fornecido pelo usuário.
  while ((option = getopt(argc, argv, "hi:o:f:b:s:p")) != -1) {
    switch (option)
    {
    case 'h': // imprime mensagem de ajuda
      print_usage(argv[0]);
      break;
    case 'i': // recebe caminho da imagem original
      originPath = optarg;
      break;
    case 'o': // recebe caminho para salvar a imagem final
      destinyPath = optarg;
      break;
    case 'f': // recebe caminho da fonte a ser utilizada
      fontPath = optarg;
      break;
    case 'b': // recebe valor da borda
      border = atof(optarg);
      break;
    case 's': // recebe valor do espaço inferior
      space = atof(optarg);
      break;
    case 'p': // define se filtro será utilizado
      iceCream = true;
      break;
    default:
      break;
    }
  }

  // o programa retorna um erro caso não seja fornecido um caminho do arquivo ppm.
  if (originPath == "") {
       cout << "Please, enter the image path." << endl;
       return 1;
  }

  string message;

  cout << "Escreva a mensagem a ser apresentada na imagem:" << endl;
  cin >> message;

  // recebe um objeto imagem com os dados lidos do arquivo ppm
  Image original = readImage(originPath, iceCream);

  // converte a imagem para o modelo polaroid
  original.polaroid(border, space);

  // instancia um objeto contendo os dados da fonte a ser utilizada na mensagem.
  Font f;
  f.read_bdf("../fonts/ib16x16u.bdf");

  // escreve a mensagem na imagem final
  original.writeMessage(message, &f);

  // salva a imagem alterada no caminho especificado
  original.print(destinyPath);

  return 0;
}
