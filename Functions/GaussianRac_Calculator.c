# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct gaussianos{
    float re;
    float im;
}GAUSS;

GAUSS leerGR();
GAUSS sumaGR(GAUSS z, GAUSS y);
GAUSS restaGR(GAUSS z, GAUSS y);
GAUSS prodGR(GAUSS z, GAUSS y);
float modGR(GAUSS z);
void escribGR(GAUSS z);

int main(int argc, char *argv){

    GAUSS A, B, C;
    float k;

    A = leerGR();
    printf("El primer numero es: ");
    escribGR(A);
    
    B = leerGR();
    printf("El segundo numero es: ");
    escribGR(B);


    C = sumaGR(A, B);
    printf("La suma es: ");
    escribGR(C);
    
    C = restaGR(A, B);
    printf("La resta es: ");
    escribGR(C);

    C = prodGR(A, B);
    printf("El producto es: ");
    escribGR(C);

    k = modGR(A);
    printf("El modulo del primer gaussiano es: %f", k);

    k = modGR(B);
    printf("\nEl modulo del segundo gaussiano es: %f", k);



    return 0;

}


GAUSS leerGR(){

    GAUSS z;

    printf("Por leer un numero gaussiano.\nDigite la parte real:");
    scanf("%f", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%f", &(z.im));


    return z;

}

void escribGR(GAUSS z){
    
    printf("%f %+f i\n", z.re, z.im);
    
    
}

GAUSS sumaGR(GAUSS z, GAUSS y){

    GAUSS c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


GAUSS restaGR(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


GAUSS prodGR(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float modGR(GAUSS z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}