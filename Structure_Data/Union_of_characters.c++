#include <iostream>
using namespace std;

union tipos {           
  char   unCar;
  int    unInt;
  double unRea;
};             

int main()
{
  union tipos unaVar;
  union tipos otraVar;
  unaVar.unCar='A'; 
  unaVar.unInt=100;
  unaVar.unRea=1.0;

  cout<<"Los valores de una variable son:"<<unaVar.unCar; 
  cout<<unaVar.unInt;
  cout<<unaVar.unRea;

  cout<<"\nDigite un caracter seguido de enter:";
  cin>>otraVar.unCar;
  cout<<"El caracter que digito es: "<<otraVar.unCar<<"\n";

  cout<<"Digite un entero:";
  cin>>otraVar.unInt;
  cout<<"El entero que digito es: "<<otraVar.unInt<<" Y el caracter ahora es: "<<otraVar.unCar<<"\n";

  cout<<"Digite un real:";
  cin>>otraVar.unRea;
  cout<<"El real que digito es: "<<otraVar.unRea<<"\n"<<"Y el entero ahora es: "<<otraVar.unInt<<"\n"<<"Y el caracter ahora es: "<<otraVar.unCar<<"\n" ;

  cout<<"Fin del programa\n";
  
  return 0;

}