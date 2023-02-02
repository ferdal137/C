#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sturml.h"
#include "newrapl.h"

int main(int argc, char *argv[]){
	FILE *entrada=fopen("polinomio.txt", "r"), *entrada2=fopen("base.txt", "r"), *salida=fopen("raices.txt", "w+");
	Inter Cachos, Raices;
	Rx f;
	if(entrada==NULL){
    	printf("No se pudo abrir el archivo 'polinomio'.txt ...\n");
    	fclose(entrada2);
    	return 0;
	}
	if(entrada2==NULL){
    	printf("No se pudo abrir el archivo 'intervalos' .txt ...\n");
    	fclose(entrada2);
    	return 0;
	}
	if(salida==NULL){
    	printf("No se pudo abrir el archivo 'raices'.txt ...\n");
    	fclose(salida);
    	return 0;
	}
	f=leeP(entrada);
	Cachos=obtenerIntervalos(entrada2);
	if(Cachos.t!=0){
		Raices=obtenerRaices(Cachos, f);
		escribirRaices(salida, Raices);
	}else{
		printf("\n\nEl polinomio no tiene raices para calcular");
	}
	printf("\n\nPrograma realizado correctamente");
	fclose(salida);
	fclose(entrada);
	fclose(entrada2);
	return 0;
}