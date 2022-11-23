# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct complejos{
    double re;
    double im;
}COMP;

COMP leerC();
void raices(COMP z);
COMP suma(COMP z, COMP y);
COMP resta(COMP z, COMP y);
COMP prod(COMP z, COMP y);

int main(int argc, char *argv){

    COMP A, B, C;

    A = leerC();
    printf("El primer numero complejo es: %lg %+lg i\n", A.re, A.im);
    B = leerC();
    printf("\nEl segundo numero complejo es : %lg %+lg i\n", B.re, B.im);


    C = suma(A, B);
    printf("\nLa suma es : %lg %+lg i\n", C.re, C.im);

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


COMP suma(COMP z, COMP y){

    COMP c;

    c.re = z.re + y.re;
    c.im = z.im + z.im;

    return c;

}


COMP resta(COMP z, COMP y);


COMP prod(COMP z, COMP y);



void raices(COMP z){

    double a,b,r1,r2,r;

    a = z.re;
    b = z.im;
    if(b==0.0){
        if(a>0.0){
            r1=sqrt(a);
            printf("La soluciones son r1=%lg y r2=%lg",r1,-r1);
        }else if(a<0.0){
            r1=sqrt(-a);
            if(r1==1.0) printf("Las soluciones son i y -i");
            else printf("La soluciones son r1=%lgi y r2=%lgi ",r1,-r1);
        }else{
            printf("0.0 es una solución doble");
        }

    if(b>0.0){
        r=sqrt(a*a+b*b);
        r1=sqrt((a+r)/2.0);
        r2=sqrt((-a+r)/2.0);
        printf("La soluciones son r1=%lg",r1);
        if(r2==1.0){
            printf("+i y r2=-%lg-i",r1);
        }else {
            printf("+i%lg y r2=-%lg-i%lg",r2,r1,r2);
        }
    }

    
    if (b<0.0){
    	printf("Las soluciones son: r1=%lg",r1);
    	if(r2==1.0){
    		printf("-i y r2=-%lg+i",r1);
		}else{
			printf("-i%lg y r2=-%lg+i%lg",r2,r1,r2);
		}
	}

}
}
