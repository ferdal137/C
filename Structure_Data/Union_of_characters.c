#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

union tipos {           //sobre escribe en funcion del caracter con el numero de bite más largo
  char   unCar;
  int    unInt;
  double unRea;
};             

int main(int argc, char *argv)
{
  union tipos unaVar = {unCar:'A', unInt:100, unRea:1.0}, otraVar;

  printf("Los valores de una variable son: %c, %d, %lg\n",
         unaVar.unCar, unaVar.unInt, unaVar.unRea);

  printf("Digite un caracter seguido de enter:");
  scanf("%c%*c", &(otraVar.unCar));
  printf("El caracter que digito es: %c\n", otraVar.unCar);

  printf("Digite un entero:");
  scanf("%d", &(otraVar.unInt));
  printf("El entero que digito es: %d\nY el caracter ahora es:%c\n",
         otraVar.unInt, otraVar.unCar);

  printf("Digite un real:");
  scanf("%lg", &(otraVar.unRea));
  printf("El real que digito es: %lg\n"
         "Y el entero ahora es:%d\nY el caracter ahora es:%c\n",
         otraVar.unRea, otraVar.unInt, otraVar.unCar);

  printf("Fin del programa\n");

  return 0;
}