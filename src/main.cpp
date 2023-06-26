#include <iostream>
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
 * Função principal: ponto de partida do programa.
 */
int main(int argc, char const *argv[]) {
  string originPath;
  string destinyPath;
  string fontPath;
  int border;
  int space;

  /*
    argc e argv são parâmetros padrões na função main(). Enquanto argc indica quantos
    argumentos foram passados para o programa, argv contém esses argumentos na ordem
    em que eles foram passados. argc será sempre >= 1, pois argv[0] terá o nome do programa.
    Por exemplo, se um programa com `meu_prog` for chamado assim:
    $ ./meu_prog abc def ghi
    argc terá o valor 4, indicando que há 4 argumentos, sendo o 1º (argv[0]) o nome do
    próprio programa ("./meu_prog"), o 2º (argv[1]) será "abc", o 3º (argv[2]) será "def"
    e, por fim, o 4º (argv[3]) será "ghi."
  */

  // TO DO
  // 1) ler a imagem input_file
  // 2) alterar a imagem lida inserindo o efeito polaroid usando
  //    como border como tamanho da borda e space como espaço de texto.
  // 3) ler a fonte font_name
  // 4) inserir o texto msg na imagem usando a fonte lida
  // 5) salvar a imagem resultante em output_file

  if (argc == 1) {
    // se não houver pelo menos 1 argumento, então o programa está sendo usado incorretamente.
    // deve-se portanto imprimir como usá-lo.
    print_usage(argv[0]);
  } else if (argc > 1) {

    for (int i = 1; i < argc; i++) {
      if (argv[i] == "-h") {
        print_usage(argv[0]);
      } else if (argv[i] == "-i") {

      } else if (argv[i] == "-o") {
        
      } else if (argv[i] == "-f") {
        
      } else if (argv[i] == "-b") {
        
      } else if (argv[i] == "-s") {
        
      }

    }

  }

    string operation = argv[1]; // transforma o array de caracteres em string.

    // Declara as variaveis que irão receber os primeiros valores do arquivo ppm
    string identifier;
    int columns = 0, lines = 0, maxRGBVal;

    // Passa o valor da entrada padrão para suas respectivas variáveis correspondentes
    cin >> identifier >> columns >> lines >> maxRGBVal;

    // Com base no argumento obtido na entrada padrão, sua função correspondente é chamada, 
    // com os valores iniciais do arquivo ppm sendo passados como argumentos.

    // if (operation == "gray") {
    //   grayScale(identifier, columns, lines, maxRGBVal);

    // } else if (operation == "enlarge") {
    //   enlarge(identifier, columns, lines, maxRGBVal);

    // } else if (operation == "reduce") {
    //   reduce(identifier, columns, lines, maxRGBVal);
      
    // } else if (operation == "rotate") {
    //   rotate(identifier, columns, lines, maxRGBVal);
      
    // } else if (operation == "sharp") {
    //   sharp(identifier, columns, lines, maxRGBVal);
      
    // } else if (operation == "blur") {
    //   blur(identifier, columns, lines, maxRGBVal);
      
    // } 

  return 0;
}
