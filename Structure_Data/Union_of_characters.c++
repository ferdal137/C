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

  cout<<"Los valores de una variable son: %c, %d, %lg\n",
         unaVar.unCar, unaVar.unInt, unaVar.unRea;

  cout<<"Digite un caracter seguido de enter:";
  scanf("%c%*c", &(otraVar.unCar));
  cout<<"El caracter que digito es: %c\n", otraVar.unCar);

  cout<<"Digite un entero:";
  scanf("%d", &(otraVar.unInt));
  cout<<"El entero que digito es: %d\nY el caracter ahora es:%c\n",
         otraVar.unInt, otraVar.unCar;

  cout<<"Digite un real:";
  scanf("%lg", &(otraVar.unRea));
  cout<<"El real que digito es: %lg\n"
         "Y el entero ahora es:%d\nY el caracter ahora es:%c\n",
         otraVar.unRea, otraVar.unInt, otraVar.unCar;

  cout<<"Fin del programa\n");

}