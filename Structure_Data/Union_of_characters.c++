#include <stdio.h>    
using namespace std;


union tipos {           
  char   unCar;
  int    unInt;
  double unRea;
};             

int main()
{
  union tipos unaVar = {unCar:'A', unInt:100, unRea:1.0}, otraVar;

  cout<<"Los valores de una variable son:"<<unaVar.unCar, unaVar.unInt, unaVar.unRea;

  cout<<"Digite un caracter seguido de enter:";
  cin>>otraVar.unCar;
  cout<<"El caracter que digito es: "<<otraVar.unCar<<"\n";

  cout<<"Digite un entero:";
  cin>>otraVar.unInt;
  cout<<"El entero que digito es: "<<otraVar.unInt<<"Y el caracter ahora es: "<<otraVar.unCar<<"\n";

  cout<<"Digite un real:";
  cin>>otraVar.unRea;
  cout<<"El real que digito es: "<<otraVar.unRea<<"\n"<<"Y el entero ahora es: "<<otraVar.unInt<<"\n"<<"Y el caracter ahora es: "<<otraVar.unCar<<"\n" ;

  cout<<"Fin del programa\n";

}