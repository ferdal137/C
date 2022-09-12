#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

#define MAX_CAR 10

int main(int argc, char *argv[])
{
  int i, j;
  char miCar='A';

  for (i=0; i<MAX_CAR; i++){
    for (j=0; j<=i; j++)
      printf("%c", miCar);
    printf("\n");
  }

  for (i=0; i<=MAX_CAR; i++) printf("-");
  printf("\n");

  for (i=1; i<=MAX_CAR; i++){
    for (j=10-i; j>=0; j--)
      printf("%c", miCar);
    printf("\n");
  }


  printf("\nFIN DEL PROGRAMA\n");

  return 0;
}