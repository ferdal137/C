#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

int main(int argc, char *argv)
{
  int base, n, aux;

  printf("Programa para escribir un numero base 10 en otra base");
  printf("escribe la base a utilizar (entre 2 y 9):");
  scanf("%d", &base);
  if (base<2 || base >9){
    base = 2;
    printf("valor fuera de rango, se utilizara el valor de %d\n", base);
  }

  printf("Valor a convertir de base 10 a base %d:", base);
  scanf("%d", &n);
  aux = n;
  if (aux<0) aux = -aux;

  printf("ADVERTENCIA: el numero se escribira en forma invertida (se debe leer de derecha a izquierda)\n");
  while(aux){
    printf("%d", aux%base);
    aux /=base;
  }

  printf("\nfin del programa\n");

  return 0;
}