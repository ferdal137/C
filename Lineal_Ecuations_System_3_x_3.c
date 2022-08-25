#include <stdio.h>
#include <stdlib.h>

#define DET(a,b,c,d,e,f,g,h,i) (((a*e*i)+(b*f*g)+(c*d*h))-((c*e*g)+(a*f*h)+(b*d*i)))
#define LEER(X,fmt) printf("Digite el valor de " #X ":"); \ //Cambiar de linea scan(#fmt, &(X))
    scan(#fmt, &(X))

int main(){

    double a, b, c, d, e, f, g, h, i, j, k, l, det, detx, dety, x, y;

  printf("Programa para la resolucion de un sistema lineal de dos ecuaiones con dos incognitas de la forma\n");
  printf("ax+by+cz=c\ndx+ey=f\n");
  LEER(a, %lg);
  LEER(b, %lg);
  LEER(c, %lg);
  LEER(d, %lg);
  LEER(e, %lg);
  LEER(f, %lg);
  LEER(g, %lg);
  LEER(h, %lg);
  LEER(i, %lg);

  det=



}
