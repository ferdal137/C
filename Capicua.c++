
#include <iostream>

using namespace std;

/*se considera un numero de cinco digitos*/
#define esCapicua(X) ((X)/10000==(X)%10?((X)%10000)/1000==((X)%100)/10?1:0:0)

int main()
{
  int num;

  cout<<"Programa de ejemplo sobre numeros capicua de cinco digitos.\n";
  cout<<"Ingrese su entero positivo de cinco digitos:";
  cin<<num;
  cout<<"El entero"<<num<<"dado"<<esCapicua(num)?"si":"no"<<"es capicua\n";
  cout<<"Fin del programa.\n";


}