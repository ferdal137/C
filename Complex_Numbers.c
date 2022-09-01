#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv){

    doble a,b,r1,r2,r;
    printf("Este programa calcula las raices de un numero complejo: ");
    printf("Introdusca el valor de la parte real: ");
    scanf("%d", &a);
    printf("Introdusca el valor de la parte imaginaria: ");
    scanf("%d", &b);
    if(b==0.0){
        if(a>0.0){
            r1=sqrt(a);
            printf("La soluciones son r1=%lg y r2=%lg",r1,-r1);
        }else if(a<0.0){
            r1=sqrt(-a);
            printf("La soluciones son r1=%lg y r2=%lg",r1,-r1);
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
            printf("+i%lg y r2=-%lg-i%lg",r2,r1,r2)
        }
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