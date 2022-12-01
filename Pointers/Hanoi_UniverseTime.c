#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/  
#include <time.h> 
#include <unistd.h> 

void hanoi(int n, char inicio, char auxiliar, char final);


int main(int argc, char *argv[])
{
  int n, aux;
  double time_spent = 0.0;
  
  printf("Programa para mostrar recursividad\n");
  printf("por resolver el problema de las torres de Hanoi. Digite un entero n (n<=10):");
  scanf("%d", &n);
  printf("La solucion es:\n");
  hanoi(n, 'A', 'B', 'C');

  printf("\nFIN DEL PROGRAMA\n");      

  return 0;
}          


void hanoi(int n, char inicio, char auxiliar, char final)
{
  double time_spent = 0.0;
   
  if (n<=1){
    printf("   mover disco de %c a %c\n", inicio, final);
    return;
  }
 
  clock_t begin = clock();

  hanoi(n-1, inicio, final, auxiliar);
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  printf("The elapsed time is %f seconds", time_spent);
  printf("   mover disco de %c a %c\n", inicio, final);
  
  hanoi(n-1, auxiliar, inicio, final);
}