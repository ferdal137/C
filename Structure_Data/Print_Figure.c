#include<stdio.h>
#include<stdlib.h>

typedef struct _miFigura_{  
  int h, a, e;
  char car;
}figura;


int main(int argc, char *argv[])
{
  int i, j, tope1, tope2;
  figura miF;

  printf("intruduzca altura, ancho, espaciado:");
  scanf("%d%d%d%*[^\n]", &miF.h, &miF.a, &miF.e); //* el asterisco es para que lo quite del buffer y no lo asigne a nadie
  printf("intruduzca un caracater:");
  for(miF.car='\n'; miF.car=='\n';) scanf("%c", &miF.car);   // hace que afuerzas escribas algo que no sea enter

  printf("Los valores introducidos son:%d, %d, %d, '%c'.\n", miF.h, miF.a, miF.e, miF.car);
  printf("La figura es:\n");

  for(i=0; i<miF.h; i++){
    tope1=i;
    tope2=miF.a-i;
    if (tope1>miF.a+miF.e) tope1=miF.a+miF.e;
    for(j=0; j<=tope1; j++) printf("%c", miF.car);
    for(j=0; j<miF.e; j++) printf(" ");
    for(j=0; j<tope2; j++) printf("%c", miF.car);
    printf("\n");
  }

  printf("\n\nFin del programa.\n");


  return 0;
}