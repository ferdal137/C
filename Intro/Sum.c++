#include <iostream>

using namespace std;

#define Suma(n) n*(n+1)/2
#define S2(n) (n*(n+1)*(2*n+1))/6
#define S3(n) Suma(n) * Suma(n)
#define S3p(n) 2*(n*(n+1) * n*(n+1))
#define S3p2(n) 8*Suma(n)*Suma(n)


int main(){

    int n, s;

    cout<<"Este programa suma enteros. Ingrese el n-esimo término: \n";

    cin>>n;

    s = Suma(n);

    cout<<"Suma de los primeros"<<n<<"numeros es:"<<s<<endl;

    s = S2(n);

    cout<<"Suma de los cuadrados de los primeros"<<n<<"numeros es:"<<s<<endl;

    s = S3(n);

    cout<<"Suma de los cubos de los primeros"<<n<<"numeros es:"<<s<<endl;

    s = S3p(n);

    cout<<"Suma de los cubos de los primeros"<<n<<"numeros pares es:"<<s<<endl;

    s = S3p2(n);

    cout<<"Suma de los cubos de los primeros"<<n<<"numeros pares es:"<<s<<endl;


}