# include <iostream>

using namespace std;

int main(){

    int a, inva;

    cout<<"Escriba un entero: ";
    cin>>a;

    a = ((a%5)+5)%5;

    cout<<a<<endl;

    inva = a==2?3:a==3?2:a==4?4:a;

    cout<<"El inverso modulo "<< a << " es "<<inva;





}