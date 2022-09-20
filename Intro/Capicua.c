
#include <stdio.h>

/*se considera un numero de cinco digitos*/
#define esCapicua(X) ((X)/10000==(X)%10?((X)%10000)/1000==((X)%100)/10?1:0:0)

int main(int argc, char *argv[])
{
  int num;

  printf("Programa de ejemplo sobre numeros capicua de cinco digitos.\n");
  printf("Ingrese su entero positivo de cinco digitos:");
  scanf("%d", &num);
  printf("El entero %05d dado %s capicua.\n", num, esCapicua(num)?"si":"no");
  printf("Fin del programa.\n");

  return 0;
}