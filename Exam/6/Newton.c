#include <stdio.h>   
#include <stdlib.h>   
#include <math.h>

#include "sturml.h"
#include "newrapl.h"

Inter obtenerIntervalos(FILE *f){
	Inter Cachos;
	int numRaiz, i;
	fscanf(f, "%d", &numRaiz);
	printf("%d", numRaiz);
	Cachos.t=2*numRaiz;
	if((Cachos.c=(double*)malloc((Cachos.t+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    	Cachos.t=-1;
		return Cachos;
	}
	for(i=0;i<numRaiz;i++){
		fscanf(f,"%lg %lg", &Cachos.c[i], &Cachos.c[i+numRaiz]);
	}
	return Cachos;
}
double RapNew(double a, double b, Rx f){
	Rx Df, auxf;
	double c, multi=1.0, r, s, aControl, bControl;
	int i=0;
	r=a;
	s=b;
	auxf=copiaP(f);
	Df=derivada(f);
	c=(s+r)/2.0;
	do{
		i++;
		if(EvaluaP(auxf, r)==0.0){
			c=r;
			i=60;
		}else if(EvaluaP(auxf, s)==0.0){
			c=s;
			i=80;
		}
		if(c<r||c>s){
			i=0;
			aControl=EvaluaP(auxf, r);
			bControl=EvaluaP(auxf, s);
			c=EvaluaP(auxf, c);
			if(aControl>0&&bControl>0){
				do{
					r=(r+s)/2.0;
				}while(aControl>0);
			}else if(aControl<0&&bControl<0){
				do{
					r=(r+s)/2.0;
				}while(aControl<0);
			}
			if(c>0.0&&aControl>0.0){
				r=c;
			}else if(c>0.0&&bControl>0.0){
				s=c;
			}else if(c<0.0&&aControl<0){
				r=c;
			}else if(c<0.0&&bControl<0.0){
				s=c;
			}
			c=(r+s)/2.0;
		}
		if(EvaluaP(Df, c)==0.0&&i<10){
			c=(s+r)/2.0;
			i=0;
		}else if(EvaluaP(Df, c)==0.0&&i>=45){
			i==80;
		}else if((EvaluaP(Df, c)==0.0)&&(i<=45)&&(c<a||c>b)){
			c=(r+a)/2.0;
			i=0;
		}
		c-=(EvaluaP(auxf, c)/EvaluaP(Df, c));
	}while(i<=75);
	if(c>-0.0000000001&&c<0.0000000001){
		c=0.0;
	}
	return c;		
}
Inter obtenerRaices(Inter J, Rx f){
	Inter Raices;
	int i;
	Raices.t=J.t/2;
	if((Raices.c=(double*)malloc((Raices.t)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    	Raices.t=-1;
		return Raices;
	}
	for(i=0; i<Raices.t; i++){
		Raices.c[i]=RapNew(J.c[i], J.c[i+Raices.t], f);
	}
	return Raices;
}
void escribirRaices(FILE *f, Inter J){
	int i;
	fprintf(f, "\nLas raices del polinomio son: ");
	for(i=0; i<J.t; i++){
		fprintf(f, "\n\t%lg", J.c[i]);
	}
}