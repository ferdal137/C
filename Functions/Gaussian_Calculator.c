# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct gaussianos{
    int re;
    int im;
}GAUSS;

GAUSS leerC();
void raices(GAUSS z);
GAUSS suma(GAUSS z, GAUSS y);
GAUSS resta(GAUSS z, GAUSS y);
GAUSS prod(GAUSS z, GAUSS y);
float mod(GAUSS z);
void escrib(GAUSS z);

int main(int argc, char *argv){

    GAUSS A, B, C;
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

    k = mod(A);
    printf("El modulo del primer gaussiano es: %f", k);

    k = mod(B);
    printf("\nEl modulo del segundo gaussiano es: %f", k);

    //raices(A);

    return 0;

}


GAUSS leerC(){

    GAUSS z;

    printf("Por leer un numero gaussiano.\nDigite la parte real:");
    scanf("%d", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%d", &(z.im));


    return z;

}

void escrib(GAUSS z){
    
    printf("%d %+d i\n", z.re, z.im);
    
    
}

GAUSS suma(GAUSS z, GAUSS y){

    GAUSS c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


GAUSS resta(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


GAUSS prod(GAUSS z, GAUSS y){
    
    
}

float mod(GAUSS z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}