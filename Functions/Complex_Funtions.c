# include <stdio.h>
# include <stlib.h>
# include <math.h>

#define COMP_COMPLEJOS(X, Y) \
    (((X).re == (Y).re) && ((X).im == (Y).im))

typedef struct complejos{
    double re;
    double im;
}COMP;

COMP leerC();

int main(int argc, char *argv){

    COMP complejos uI = {0.0, 1.0}, uR = {im:0.0, re:1.0}, z;

    printf("Por leer un numero complejo.\nDigite la parte real:");
    scanf("%lg", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%lg", &(z.im));

    if (COMP_COMPLEJOS(uI, z))
        printf("Digito la unidad imaginaria\n");
    else if (COMP_COMPLEJOS(uR, z))
        printf("Digito la unidad real\n");
    else
        printf("El numero complejo que digito fue: %lg %+lg i\n", z.re, z.im);



    return 0;

}
