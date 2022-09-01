#include <iostream>

using namespace std;

int main(){

    doble a,b,r1,r2,r;

    cout<<"Este programa calcula las raices de un numero complejo: ";
    cout<<"Introdusca el valor de la parte real: ";
    cin<<a;
    cout<<"Introdusca el valor de la parte imaginaria: ";
    cin>>b;

    if(b==0.0){
        if(a>0.0){
            r1=sqrt(a);
            cout<<"La soluciones son r1=%lg y r2=%lg"<<r1<<-r1;
        }else if(a<0.0){
            r1=sqrt(-a);
            cout<<"La soluciones son r1=%lg y r2=%lg"<<r1<<-r1;
        }else{
            cout<<"0.0 es una solución doble";
        }


}

