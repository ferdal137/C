# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct quaterniones{
    double re;
    double i;
    double j;
    double k;
}QUA;

QUA leerQ();
QUA sumaQ(QUA z, QUA y);
QUA restaQ(QUA z, QUA y);
QUA prodQ(QUA z, QUA y);
float modQ(QUA z);
void escribQ(QUA z);

int main(int argc, char *argv){

    QUA A, B, C;
    float k;

    A = leerC();
    printf("El primer quaternion es: ");
    escrib(A);
    
    B = leerC();
    printf("El segundo quaternion es: ");
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
    printf("El modulo del primer quaternion es: %f", k);

    k = mod(B);
    printf("\nEl modulo del segundo quaternion es: %f", k);

    //raices(A);

    return 0;

}


QUA leerC(){

    QUA z;

    printf("Por leer un quaternion.\nDigite la parte real:");
    scanf("%lg", &(z.re));
    printf("Digite la parte i:");
    scanf("%lg", &(z.i));
    printf("Digite la parte j:");
    scanf("%lg", &(z.j));
    printf("Digite la parte k:");
    scanf("%lg", &(z.k));


    return z;

}

void escrib(QUA z){
    
    printf("%lg %+lg i %+lg j %+lg k\n", z.re, z.im);
    
    return 0;
    
}

QUA suma(QUA z, QUA y){

    QUA c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


QUA resta(QUA z, QUA y){
    
    QUA c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


QUA prod(QUA z, QUA y){
    
    QUA c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float mod(QUA z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}