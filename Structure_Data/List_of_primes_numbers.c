#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

int main(int argc, char *argv)
{                             
  int _10primos[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  double vals[5];
  int i, n;

  printf("A continuacion se enlistan los 10 primeros primos:\n");

  for(i=0; i<10; i++)
    printf("%3d) %d\n", i+1, _10primos[i]);

  printf("Por leer valores reales.\n");
  printf("Digita un entero entre 1 y 5:");
  scanf("%d", &n);
  if (n<=0 || n>5) n=3;
  printf("A continuacion se leeran %d reales.\n", n);
  for (i=0; i<n; i++){
    printf("digite un numero real:");
    scanf("%lg", &(vals[i]));
  }

  printf("Los valores leidos son:");
  for(i=0; i<n; i++) printf(" %lg", vals[i]);
  printf("\nFin del programa.\n");

  return 0;
}