#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

int fibonacci(int n);
int factorial(int n);
void hanoi(int n, char inicio, char auxiliar, char final);


int main(int argc, char *argv[])
{
  int n, aux;

  printf("Programa para mostrar recursividad\n");
  printf("por hallar factorial. Digite un entero n (n<=10):");
  scanf("%d", &n);
  aux = factorial(n);
  printf("(%d)!=%d\n", n, aux);
  printf("por hallar un termino de la sucesion de Fibonacci. Digite un entero n (n<=10):");
  scanf("%d", &n);
  aux = fibonacci(n);
  printf("el %d-esimo termino es: %d\n", n, aux);
  printf("por resolver el problema de las torres de Hanoi. Digite un entero n (n<=10):");
  scanf("%d", &n);
  printf("La solucion es:\n");
  hanoi(n, 'A', 'B', 'C');

  printf("\nFIN DEL PROGRAMA\n");      

  return 0;
}          


/*
 * la sucesion es a_n = a_{n-1}+a_{n-2}, con a_1=1 y a_2=1
 * 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 */
int fibonacci(int n)
{
  if (n<=2) return 1;

  return fibonacci(n-1)+fibonacci(n-2);  
}

/*n! = n x (n-1)!*/
int factorial(int n)
{
  if (n<=1) return 1;

  return n*factorial(n-1);
}

/*
 * n discos en la torre de origen, por pasarlos a la torre destino 
 * utilizando una torre auxiliar.
 * Estrategia:
 *   - si solo tengo un disco, lo paso de la torre de inicio 
 *     hasta la torre final directamente
 *   - si solo tengo n discos (n>=1), paso n-1 discos de la torre de 
 *     inicio a la torre auxiliar, luego paso el disco restante de la 
 *     torre de inicio hasta la torre final directamente, por ultimo
 *     paso los n-1 discos que estan en la torre auxiliar hasta la torre
 *     final
 */
void hanoi(int n, char inicio, char auxiliar, char final)
{
  if (n<=1){
    printf("   mover disco de %c a %c\n", inicio, final);
    return;
  }

  hanoi(n-1, inicio, final, auxiliar);
  printf("   mover disco de %c a %c\n", inicio, final);
  hanoi(n-1, auxiliar, inicio, final);
}