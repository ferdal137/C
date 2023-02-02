#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sturml.h"

int main(int argc, char *argv[]){
	FILE *entrada=fopen("polinomio.txt", "a+"), *salida=fopen("intervalos.txt", "w+"), *salidaDos=fopen("base.txt", "w+");
	
	if(entrada==NULL){
    	printf("No se pudo abrir el archivo 'polinomio'.txt ...\n");
    	fclose(entrada);
    	return 0;
	}
	if(salida==NULL){
    	printf("No se pudo abrir el archivo base.txt ...\n");
    	fclose(salida);
    	return 0;
	}
	if(salidaDos==NULL){
    	printf("No se pudo abrir el archivo 'intervalos'.txt ...\n");
    	fclose(salidaDos);
    	return 0;
	}
	
	Rx a, b, d, s, r={c:NULL, g:-1};
	
	PoliSturm StPa;
	Inter B={c:NULL, t:-1};
	int i;
	a=leeP(entrada);
	if(a.g>0){
		b=derivada(a);
		d=divR(a,MCD(a,b),&r);
		if(XD(-cota(d),cota(d),d)==0){
			fprintf(salida ,"\nEl polinomio no tiene raices reales");
		}else{
			B=separa(d);
			escribeSepa(salida, B);
		}
		liberaP(&b);
		liberaP(&d);
		liberaP(&r);
	}else if(a.g==0){
		fprintf(salida, "\nEl polinomio no cuenta con raices");
	}
	
	escribeD(salidaDos, B);
	liberaInter(&B);
	printf("\n\nPrograma realizado correctamente.\n");
	liberaP(&a);
	fclose(salida);
	fclose(entrada);
	return 0;
}