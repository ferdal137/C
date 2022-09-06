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

    
    if(b>0.0){
        r=sqrt(a*a+b*b);
        r1=sqrt((a+r)/2.0);
        r2=sqrt((-a+r)/2.0);
        cout<<"La soluciones son r1=%lg"<<r1;
        if(r2==1.0){
            cout<<"+i y r2=-%lg-i"<<r1;
        }else {
            cout<<"+i%lg y r2=-%lg-i%lg"<<r2<<r1<<r2;
        }
    }

    }
    
    if (b<0.0){
    	cout<<"Las soluciones son: r1=%lg"<<r1;
    	if(r2==1.0){
    		cout<<"-i y r2=-%lg+i"<<r1;
		}else{
			cout<<"-i%lg y r2=-%lg+i%lg"<<r2<<r1<<r2;
		}
	}



}

