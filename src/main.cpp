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

void printInfo(string op, string dp, string fp, int bw, int sw) {
  cout << "caminho da imagem: " << op << endl;
  cout << "destino da imagem: " << dp << endl;
  cout << "caminho da fonte: " << fp << endl;
  cout << "tamanho da borda: " << bw << endl;
  cout << "tamanho da base: " << sw << endl;

}

Image readImage(string originPath) {
  string type;
  int lines, columns, maxRGBVal;
  char charVal;

  ifstream ppm(originPath);

  ppm >> type >> columns >> lines >> maxRGBVal;

  PixelMatrix data(lines, columns);

  if (type == "P3") {

    for (int l = 0; l < lines; l++) { // Para cada linha faça:
      for (int c = 0; c < columns; c++) { // Para cada coluna faça:
        unsigned char red;
        unsigned char green;
        unsigned char blue;

        for (int p = 0; p < 3; p++) { // Para cada valor RGB no pixel faça:
          int rgb;
          ppm >> rgb; // Recebe o valor de R, G ou B da entrada padrão.
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

        if (l == 0 && c == 0) {
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
  string destinyPath = "default/save/path/";
  string fontPath = "../fonts/a.bdf";
  int border = 60;
  int space = 120;

  int option;
  
  while ((option = getopt(argc, argv, "hi:o:f:b:s:")) != -1) {
    switch (option)
    {
    case 'h':
      print_usage(argv[0]);
      break;
    case 'i':
      originPath = optarg;
      break;
    case 'o':
      destinyPath = optarg;
      break;
    case 'f':
      fontPath = optarg;
      break;
    case 'b':
      border = atof(optarg);
      break;
    case 's':
      space = atof(optarg);
      break;
      
    // case ':':
    //   switch (optopt)
    //   {
    //   case 'o':
    //     oResult("default/path");
    //     break;
    //   case 'f':
    //     fResult("default/path");
    //     break;
    //   case 'b':
    //     bResult(100);
    //     break;
    //   case 's':
    //     sResult(300);
    //     break;
    //   default:
    //     break;
    //   }
    //   break;

    default:
      break;
    }
  }

  if (originPath == "") {
       cout << "Please, enter the image path." << endl;
       return 1;
  }

  Image original = readImage(originPath);

  original.polaroid(border, space);

  // Font f;
  // f.read_bdf(fontPath);

  // const Glyph *a = f.get_glyph('a');

  // cout << a->get_width() << " " << a->get_height() << endl;

  // original.writeLetter(a);

  original.print(destinyPath);

  // printInfo(originPath, destinyPath, fontPath, border, space);

  // TO DO
  // 1) ler a imagem input_file
  // 2) alterar a imagem lida inserindo o efeito polaroid usando
  //    como border como tamanho da borda e space como espaço de texto.
  // 3) ler a fonte font_name
  // 4) inserir o texto msg na imagem usando a fonte lida
  // 5) salvar a imagem resultante em output_file

  return 0;
}
