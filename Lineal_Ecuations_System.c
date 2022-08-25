#include <stdio.h>
#include <stdlib.h>


#define DET(a, b, c, d)  ((a)*(d)-(b)*(c))
#define LEER(X, fmt) printf("digite el valor de " #X ":");	\
  scanf(#fmt, &(X))


int main(int argc, char *argv[])
{
  double a, b, c, d, e, f, det, detx, dety, x, y;

  printf("Programa para la resolucion de un sistema lineal de dos ecuaiones con dos incognitas de la forma\n");
  printf("ax+by=c\ndx+ey=f\n");
  LEER(a, %lg);
  LEER(b, %lg);
  LEER(c, %lg);
  LEER(d, %lg);
  LEER(e, %lg);
  LEER(f, %lg);

  det=DET(a, b, d, e);
  detx=DET(c, b, f, e);
  dety=DET(a, c, d, f);

  x=detx/det;
  y=dety/det;

  printf("\nLa solucion es x=%lg, y=%lg.\n", x, y);
  printf("Fin del programa.\n");

  return 0;
}



