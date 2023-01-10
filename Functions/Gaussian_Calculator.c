# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct gaussianos{
    int re;
    int im;
}GAUSS;

GAUSS leerG();
GAUSS sumaG(GAUSS z, GAUSS y);
GAUSS restaG(GAUSS z, GAUSS y);
GAUSS prodG(GAUSS z, GAUSS y);
float modG(GAUSS z);
void escribG(GAUSS z);
//Division?

int main(int argc, char *argv){

    GAUSS A, B, C;
    float k;

    A = leerG();
    printf("El primer numero es: ");
    escribG(A);
    
    B = leerG();
    printf("El segundo numero es: ");
    escribG(B);


    C = sumaG(A, B);
    printf("La suma es: ");
    escribG(C);
    
    C = restaG(A, B);
    printf("La resta es: ");
    escribG(C);

    C = prodG(A, B);
    printf("El producto es: ");
    escribG(C);

    k = modG(A);
    printf("El modulo del primer gaussiano es: %f", k);

    k = modG(B);
    printf("\nEl modulo del segundo gaussiano es: %f", k);

    return 0;

}


GAUSS leerG(){

    GAUSS z;

    printf("Por leer un numero gaussiano.\nDigite la parte real:");
    scanf("%d", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%d", &(z.im));


    return z;

}

void escribG(GAUSS z){
    
    printf("%d %+d i\n", z.re, z.im);
    
    
}

GAUSS sumaG(GAUSS z, GAUSS y){

    GAUSS c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


GAUSS restaG(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


GAUSS prodG(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float modG(GAUSS z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}