# include <iostream>

using namespace std;

#define DET(a, b, c, d)  ((a)*(d)-(b)*(c))


int main(){

  double a, b, c, d, e, f, det, detx, dety, x, y;

  cout<<"Programa para la resolucion de un sistema lineal de dos ecuaiones con dos incognitas de la forma\n";
  cout<<"ax+by=c\ndx+ey=f\n";
  cout<<"Escriba el valor: "; cin>>a;
  cout<<"Escriba el valor: "; cin>>b;
  cout<<"Escriba el valor: "; cin>>c;
  cout<<"Escriba el valor: "; cin>>d;
  cout<<"Escriba el valor: "; cin>>e;
  cout<<"Escriba el valor: "; cin>>f;
  
 

  det=DET(a, b, d, e);
  detx=DET(c, b, f, e);
  dety=DET(a, c, d, f);

  x=detx/det;
  y=dety/det;

  //det == 0.0?cout<<"El sistema tiene infinidad de soluciones o ninguna";

  cout<<"\nLa solucion es x= " << x << " y=" << y;
  cout<<"Fin del programa.\n";




    
}

