#include<stdio.h>
#include<stdlib.h>

#define MAXCOL 20
#define MAXREN 20

typedef struct _mat_{
  int m, n;
  double c[MAXREN][MAXCOL];
}matriz;

int main(int argc, char *argv[])
{
  matriz A, B, C;
  int i, j, k;
 
  printf("El siguiente programa calcula la suma, resta, producto y transpuesta de matrices\n");

  printf("Escriba el numero de renglones y el de columnas de la primera matriz:");
  scanf("%d%d", &A.m, &A.n);
  if (A.m<=0 || A.m>=MAXREN){
    A.m=2;
    printf("El numero de renglones ingresado esta fuera de rango. Se va a asignar el valor de: %d\n", A.m);
  }
  if (A.n<=0 || A.n>=MAXCOL){
    A.n=2;
    printf("El numero de columnas ingresado esta fuera de rango. Se va a asignar el valor de: %d\n", A.n);
  }
  printf("Introduzca las entradas de la matriz:");
  for(i=0; i<A.m; i++)
    for(j=0; j<A.n; j++){
      printf("ent[%d, %d]:", i+1, j+1);
      scanf("%lg", &(A.c[i][j]));
    }
   
  printf("Escriba el numero de renglones y el de columnas de la segunda matriz:");
  scanf("%d%d", &B.m, &B.n);
  if (B.m<=0 || B.m>=MAXREN){
    B.m=2;
    printf("El numero de renglones ingresado esta fuera de rango. Se va a asignar el valor de: %d\n", A.m);
  }
  if (B.n<=0 || B.n>=MAXCOL){
    B.n=2;
    printf("El numero de columnas ingresado esta fuera de rango. Se va a asignar el valor de: %d\n", A.n);
  }
  printf("Introduzca las entradas de la matriz:");
  for(i=0; i<B.m; i++)
    for(j=0; j<B.n; j++){
      printf("ent[%d, %d]:", i+1, j+1);
      scanf("%lg", &(B.c[i][j]));
    }

if(A.n==B.n && A.m==B.m){
C.n = A.n;
C.m = A.m;
for(i=0; i<C.m; i++)
          for(j=0; j<C.n; j++){
          C.c[i][j] = A.c[i][j] + B.c[i][j];
 }
printf("La suma es:\n");
for(i=0; i<C.m; i++){
          for(j=0; j<C.n; j++) printf(" %5lg ", C.c[i][j]);
        printf("\n");
      }
}else printf("No se puede realizar la suma\n");

if(A.n==B.n && A.m==B.m){
C.n = A.n;
C.m = A.m;
for(i=0; i<C.m; i++)
          for(j=0; j<C.n; j++){
          C.c[i][j] = A.c[i][j] - B.c[i][j];
 }
printf("La resta es:\n");
for(i=0; i<C.m; i++){
          for(j=0; j<C.n; j++) printf(" %5lg ", C.c[i][j]);
        printf("\n");
      }
}else printf("No se puede realizar la resta\n");

if(A.n==B.m){
C.m = A.m;
C.n = B.n;
for(i=0; i<C.m; i++)
          for(j=0; j<C.n; j++){
          C.c[i][j] = 0.0;
 }
for(i=0; i<C.m; i++)
for(j=0; j<A.n; j++)
 for(k=0; k<B.m; k++) C.c[i][j] += A.c[i][k]*B.c[k][j];
printf("El producto es:\n");
for(i=0; i<C.m; i++){
         for(j=0; j<C.n; j++) printf(" %5lg ", C.c[i][j]);
        printf("\n");
}
}else printf("El producto no se puede realizar");

C.n = A.m;
C.m = A.n;
for(i=0; i<C.m; i++){
     for(j=0; j<C.n; j++)
      C.c[i][j] = A.c[j][i];
}
printf("La transpuesta es:\n");
for(i=0; i<C.m; i++){
         for(j=0; j<C.n; j++) printf(" %5lg ", C.c[i][j]);
        printf("\n");
}


  printf("\nFin del programa.\n");


  return 0;
}