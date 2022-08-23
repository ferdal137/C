
#include <stdio.h>

int main(int argc, char *argv[])
{
  char unCaracter; /*declaracion de una variable de tipo char*/
  int unEntero;    /*declaracion de una variable de tipo int*/
  double unReal;   /*declaracion de una variable de tipo double*/

  printf("\nDigite un caracter:");
  scanf("%c", &unCaracter);
  printf("Digite un entero:");
  scanf("%d", &unEntero);
  printf("Digite un real:");
  scanf("%lf", &unReal);
  printf("Digite una cadena ... pendiente :-(\n");

  printf("\nLos valores escritos fueron: %c, %d, %lf\n",
	 unCaracter, unEntero, unReal);


  return 0;
}