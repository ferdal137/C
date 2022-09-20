#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

int main(int argc, char *argv)
{
  unsigned char c;

  printf("Programa para seleccionar un caracter\n");

  do{
    printf("escriba un caracter ('e' para salir) seguido de <ENTER>:");
    scanf("%c", &c);
   /*
    un caracter \"especial\" puede tener una codificacion en dos o mas bytes dependiendo de su codificacion, por ejemplo UTF-8, UNICODE, entre otros.
   */
    printf("El codigo ASCII del caracter seleccionado es el siguiente hex:%02x, dec:%3d, oct:%o\n", c, c, c);
    if (c>=0xc2) {
      scanf("%c%*c", &c);
      printf("El codigo ASCII del segundo byte del caracter seleccionado es el siguiente hex:%02x, dec:%3d, oct:%o\n", c, c, c);
    } else scanf("%*c");
  } while (c!='e' && c!= 'E');

  printf("\nfin del programa\n");

  return 0;
}