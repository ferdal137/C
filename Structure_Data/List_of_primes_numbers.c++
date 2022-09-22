#include <iostream>
using namespace std;


int main()
{                             
  int _10primos[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  double vals[5];
  int i, n;

  cout<<"A continuacion se enlistan los 10 primeros primos:\n";

  for(i=0; i<10; i++)
    cout<<_10primos[i]<<"\n";
    i++;

  cout<<"Por leer valores reales.\n";
  cout<<"Digita un entero entre 1 y 5:";
  cin>>n;
  if (n<=0 || n>5) n=3;
  cout<<"A continuacion se leeran %d reales.\n";
  for (i=0; i<n; i++){
    cout<<"digite un numero real:";
    cin>>vals[i];
  }

  cout<<"Los valores leidos son:";
  for(i=0; i<n; i++) cout<<vals[i];
  cout<<"\nFin del programa.\n";


}