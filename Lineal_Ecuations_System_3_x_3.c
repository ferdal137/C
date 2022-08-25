#include <stdio.h>
#include <stdlib.h>

#define DET(a,b,c,d,e,f,g,h,i) (((a*e*i)+(b*f*g)+(c*d*h))-((c*e*g)+(a*f*h)+(b*d*i)))
#define LEER(X,fmt) printf("Digite el valor de " #X ":"); \ //Cambiar de linea scan(#fmt, &(X))
    scan(#fmt, &(X))

int main(){

    double a, b, c, d, e, f, g, h, i, j, k, l, det, detx, dety, x, y;

  printf("Programa para la resolucion de un sistema lineal de dos ecuaiones con dos incognitas de la forma\n");
  printf("ax+by+cz=d\nex+gy+gz=h\nix+jy+kz=l");
  LEER(a, %lg);
  LEER(b, %lg);
  LEER(c, %lg);
  LEER(d, %lg);
  LEER(e, %lg);
  LEER(f, %lg);
  LEER(g, %lg);
  LEER(h, %lg);
  LEER(i, %lg);

  det = det(a,b,c,e,f,g,i,j,k);
  detx = det(d,b,c,h,f,g,l,j,k);
  dety = det(a,d,c,e,h,g,i,l,k);
  detz = det(a,b,d,e,f,h,i,j,l);

  x = detx/det;
  y = dety/det;
  z = detz/det; 

  det==0.0?printf("No hay solucion o hay infinitas soluciones"):printf()


 return 0;


}
