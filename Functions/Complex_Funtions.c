# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct complejos{
    double re;
    double im;
}COMP;

COMP leerC();

int main(int argc, char *argv){

    COMP A;

    A = leerC();
    printf("El numero complejo que digito fue: %lg %+lg i\n", A.re, A.im);


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