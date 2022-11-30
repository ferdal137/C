# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct complejos{
    double re;
    double i;
    double j;
    double k;
}COMP;

COMP leerC();
void raices(COMP z);
COMP suma(COMP z, COMP y);
COMP resta(COMP z, COMP y);
COMP prod(COMP z, COMP y);
float mod(COMP z);
void escrib(COMP z);

int main(int argc, char *argv){

    COMP A, B, C;
    float k;

    A = leerC();
    printf("El primer numero es: ");
    escrib(A);
    
    B = leerC();
    printf("El segundo numero es: ");
    escrib(B);


    C = suma(A, B);
    printf("La suma es: ");
    escrib(C);
    
    C = resta(A, B);
    printf("La resta es: ");
    escrib(C);

    C = prod(A, B);
    printf("El producto es: ");
    escrib(C);

    k = mod(A);
    printf("El modulo del primer complejo es: %f", k);

    k = mod(B);
    printf("\nEl modulo del segundo complejo es: %f", k);

    //raices(A);

    return 0;

}


COMP leerC(){

    COMP z;

    printf("Por leer un numero complejo.\nDigite la parte real:");
    scanf("%lg", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%lg", &(z.im));


    return z;

}

void escrib(COMP z){
    
    printf("%lg %+lg i\n", z.re, z.im);
    
    return 0;
    
}

COMP suma(COMP z, COMP y){

    COMP c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


COMP resta(COMP z, COMP y){
    
    COMP c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


COMP prod(COMP z, COMP y){
    
    COMP c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float mod(COMP z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}