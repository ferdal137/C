# include <iostream>

using namespace std;

#define DET(a, b, c, d)  ((a)*(d)-(b)*(c))
#define LEER(X, fmt) cout<<"digite el valor de " #X ":";	\
  cin>>#fmt, &(X)

int main(){

  double a, b, c, d, e, f, det, detx, dety, x, y;

  cout<<"Programa para la resolucion de un sistema lineal de dos ecuaiones con dos incognitas de la forma\n";
  cin>>"ax+by=c\ndx+ey=f\n";
  LEER(a);
  LEER(b);
  LEER(c);
  LEER(d);
  LEER(e);
  LEER(f);

  det=DET(a, b, d, e);
  detx=DET(c, b, f, e);
  dety=DET(a, c, d, f);

  x=detx/det;
  y=dety/det;

  //det == 0.0?cout<<"El sistema tiene infinidad de soluciones o ninguna";

  cout<<"\nLa solucion es x=%lg, y=%lg.\n", x, y;
  cout<<"Fin del programa.\n";




    
}

