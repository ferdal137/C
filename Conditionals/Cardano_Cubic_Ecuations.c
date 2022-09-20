#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEER(x) printf("Escriba el valor de"#x": " ); scanf("%lg", &x);

int main(int argc, char *argv[]) {

double a,b,c,p,q,del,u,v,x1,x2,x3;
printf("Este programa resuelve ecuacines cubicas de la forma x^3 + ax^2 + bx + c = 0");

LEER(a);
LEER(b);
LEER(c);

p=(3*b-pow(a,2))/3.0;
q=((2*pow(a,3))-(9*a*b)+(27*c))/27;
delta=(pow(q,2)/4)+(pow(p,3)/27);

if(del==0.0){
if(p==0.0 && q==0.0){
printf("La ecuacion tiene una raiz tripe y es %lg", -a/3);
}else{
printf("La ecuacion tiene a x1=%lg como raiz doble y a x2=%lg como raiz simple",(-((3*q)/(2*p))-a/3),(-((4*p*p)/(9q))-a/3))
}
}

return 0;
}