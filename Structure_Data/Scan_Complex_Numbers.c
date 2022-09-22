#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

#define COMP_COMPLEJOS(X, Y) \
  (((X).re == (Y).re) && ((X).im == (Y).im))

struct complejos {
  double re;     
  double im;     
};

int main(int argc, char *argv)
{
  struct complejos uI = {0.0, 1.0}, uR = {im:0.0, re:1.0}, z;

  printf("Por leer un numero complejo.\nDigite la parte real:");
  scanf("%lg", &(z.re));
  printf("Digite la parte imaginaria:");
  scanf("%lg", &(z.im));

  if (COMP_COMPLEJOS(uI, z))
    printf("Digito la unidad imaginaria\n");
  else if (COMP_COMPLEJOS(uR, z))
    printf("Digito la unidad real\n");
  else
    printf("El numero complejo que digito fue: %lg %+lg i\n", z.re, z.im);

  z.re += 3.0;

  printf("El numero complejo modificado es: %lg %+lg i\n", z.re, z.im);

  return 0;
}