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

    A = leerQ();
    printf("El primer quaternion es: ");
    escribQ(A);
    
    B = leerQ();
    printf("El segundo quaternion es: ");
    escribQ(B);


    C = sumaQ(A, B);
    printf("La suma es: ");
    escribQ(C);
    
    C = restaQ(A, B);
    printf("La resta es: ");
    escribQ(C);

    C = prodQ(A, B);
    printf("El producto es: ");
    escribQ(C);

    k = modQ(A);
    printf("El modulo del primer quaternion es: %f", k);

    k = modQ(B);
    printf("\nEl modulo del segundo quaternion es: %f", k);

    //raices(A);

    return 0;

}


QUA leerQ(){

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

void escribQ(QUA z){
    
    printf("%lg %+lg i %+lg j %+lg k\n", z.re, z.im);
    
    return 0;
    
}

QUA sumaQ(QUA z, QUA y){

    QUA c;
    
    c.re = z.re + y.re;
    c.i = z.i + y.i;
    c.j = z.j + y.j;
    c.k = z.k + y.k;

    return c;

}


QUA restaQ(QUA z, QUA y){
    
    QUA c;
    
    c.re = z.re - y.re;
    c.i = z.i - y.i;
    c.j = z.j - y.j;
    c.k = z.k - y.k;

    return c;
    
}


QUA prodQ(QUA z, QUA y){
    
    QUA c;
    
    c.re = (z.re*y.re) - (z.i*y.i) - (z.j*y.j) - (z.k*y.k);
    c.i =  (z.re*y.re) + (z.i*y.re) + (z.j*y.k) - (z.k*y.j);
    c.j =  (z.re*y.j) - (z.i*y.k) + (z.j*y.re) + (z.k*y.i);
    c.k =  (z.re*y.k) + (z.i*y.j) - (z.j*y.i) + (z.k*y.re);

    return c;
}

float modQ(QUA z){

    float c;

    c = sqrt((z.re*z.re)+(z.i*z.i)+(z.j*z.j)+(z.k*z.k));

    return c;

}