#include <iostream>

using namespace std;

int main()
{
  int ini, fin, ind, tab;

  cout<<"programa para escribir parte de una tabla de multiplicar\n";
  cout<<"escribe un valor entre 1 y 100 para mostrar su tabla:";
  cin>>tab;
  if (tab<=0 || 100<tab ) {
    tab = 15;
    cout<<"Valor fuera de rango, se utilizara el valor de"<<tab;
  }

  cout<<"escribe el indice inicial y final de los valores a recorrer\n";
  cout<<"valor inicial (entre 1 y 100)";
  cin>>ini;
  if (ini<=0 || 100<ini){
    ini = 25;
    cout<<"valor fuera de rango, se utilizara el valor de"<<ini;
  }
  cout<<"valor final (entre "<<ini<<"y"<<ini+25;
  cin>>fin;
  if (fin<ini || (ini+25)<fin){
    fin = ini+25;
    cout<<"valor fuera de rango, se utilizara el valor de"<<fin;

  }

  for (ind = ini; ind <=fin; ind++){
    cout<<tab<<"x"<<ind<<tab*ind;
  }

  cout<<"\nfin del programa\n";

  return 0;
}