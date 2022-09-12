#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

int main(int argc, char *argv)
{
  int ini, fin, ind, tab;

  printf("programa para escribir parte de una tabla de multiplicar\n");
  printf("escribe un valor entre 1 y 100 para mostrar su tabla:");
  scanf("%d", &tab);
  if (tab<=0 || 100<tab ) {
    tab = 15;
    printf("Valor fuera de rango, se utilizara el valor de %d\n", tab);
  }

  printf("escribe el indice inicial y final de los valores a recorrer\n");
  printf("valor inicial (entre 1 y 100)");
  scanf("%d", &ini);
  if (ini<=0 || 100<ini){
    ini = 25;
    printf("valor fuera de rango, se utilizara el valor de %d\n", ini);
  }
  printf("valor final (entre %d y %d)", ini, ini+25);
  scanf("%d", &fin);
  if (fin<ini || (ini+25)<fin){
    fin = ini+25;
    printf("valor fuera de rango, se utilizara el valor de %d\n", fin);

  }

  for (ind = ini; ind <=fin; ind++){
    printf("%d x %d = %d\n", tab, ind, tab*ind);
  }

  printf("\nfin del programa\n");

  return 0;
}