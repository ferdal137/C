#include <iostream>

using namespace std;

int main()
{
  int base, n, aux;

  cout<<"Programa para escribir un numero base 10 en otra base \n";
  cout<<"escribe la base a utilizar (entre 2 y 9): ";
  cin>>base;
  if (base<2 || base >9){
    base = 2;
    cout<<"valor fuera de rango, se utilizara el valor de "<<base<<"\n";
  }

  cout<<"Valor a convertir de base 10 a base "<<base<<": ";
  cin>>n;
  aux = n;
  if (aux<0) aux = -aux;

  cout<<"ADVERTENCIA: el numero se escribira en forma invertida (se debe leer de derecha a izquierda)\n";
  while(aux){
    cout<<aux%base;
    aux /= base;
  }

  cout<<"\nfin del programa\n";

}