#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/


struct complejos {
  double re;     
  double i;    
  double j; 
  double k; 
};

int main(int argc, char *argv)
{
  struct complejos z;

  printf("Por leer un numero complejo.\nDigite la parte real:");
  scanf("%lg", &(z.re));
  printf("Digite la parte i:");
  scanf("%lg", &(z.i));
  printf("Digite la parte j:");
  scanf("%lg", &(z.j));
  printf("Digite la parte k:");
  scanf("%lg", &(z.k));

  printf("El numero complejo que digito fue: %lg %+ lgi %+ lgj %+ lgk\n", z.re, z.i, z.j, z.k);

  z.re += 3.0;

  printf("El numero complejo modificado es: %lg %+ lgi %+ lgj %+ lgk\n", z.re, z.i, z.j, z.k);

  return 0;
}