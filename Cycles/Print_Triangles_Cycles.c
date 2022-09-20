#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/

#define MAX_CAR 10

int main(int argc, char *argv[])
{
  int i, j;
  char miCar='A';

  for (i=0; i<MAX_CAR; i++){
    for (j=0; j<=i; j++)
      printf("%c", miCar);
    printf("\n");
  }
  i = 0;
  while(i<MAX_CAR){
  	j = 0; 
  	while(j<=i){
  		j++;
  		printf("%c", miCar);
	  }
	  printf("\n");
	  i++;
  }
  for (i=0; i<=MAX_CAR; i++) printf("-");
  printf("\n");

  for (i=1; i<=MAX_CAR; i++){
    for (j=MAX_CAR-i; j>=0; j--)
      printf("%c", miCar);
    printf("\n");
  }
  
  i=1;
  do{
  	j=MAX_CAR-i;
  	do{
  		printf("%c", miCar);
  		j--;
	  }while(j>=0);
	  printf("\n");
	  i++;
  }while(i<=MAX_CAR);
  
  printf("\nFIN DEL PROGRAMA\n");
  system("PAUSE");
  return 0;
}
