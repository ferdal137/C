
#include <iostream>

using namespace std;

/*se considera un numero de cinco digitos*/
#define esCapicua(X) ((X)/10000==(X)%10?((X)%10000)/1000==((X)%100)/10?1:0:0)

int main(){
  int num;

  cout<<"Programa de ejemplo sobre numeros capicua de cinco digitos.\n";
  cout<<"Ingrese su entero positivo de cinco digitos:";
  cin>>num;
  s_n = esCapicua(num)?"si":"no";
  cout<<"El entero"<<num<<"dado"<<s_n<<"es capicua\n";
  cout<<"Fin del programa.\n";


}