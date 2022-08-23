#include <stdio.h>

int main()
{
  char unCaracter[2]='Aa';  /*declaracion de una variable de tipo char inicializada  */
  int unEntero=23;   
  double unReal=1.3;  

  printf("Por escribir algunos valores en la salida estandar\n");
  printf("\tun caracter: %c\n", 'A');
  printf("\tun entero: %d\n", 12345);
  printf("\tun flotante: %g\n", 1.23e125f); /*Por exceder el rango, la salida no se vera igual a lo que se esta tratando de escribir*/
  /*
   * el real float (flotante) tiene un menor rango y una menor
   * precision que el doble (double). 
   */
  printf("\tun doble: %lg\n", 1.23e125);
  printf("\tuna cadena de caracteres: %s\n", "esta es una cadena");
  printf("\tvaliables: (caracter) %c, (entero) %d, (real) %lg\n", 
	 unCaracter, unEntero, unReal);

  return 0;
}