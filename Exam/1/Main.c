#include <stdio.h>    
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#include "polisl.h"



int main(int argc, char *argv[]) {
  Rx a, b, q, r = {c : NULL, g : -1}, s, m, v,d;
  int tipo, p,e;
  Coeficiente c;
  FILE *entrada=fopen("policoef.txt","r");
  if(entrada==NULL){
    int mi_error=errno; 
    printf("Hubo un error en la lectura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n", 
	   mi_error, strerror(mi_error));
    return -1;
  } else {
  	
  tipo = leerTipo(entrada);
  if (tipo == 0) {
    fscanf(entrada,"%d", &p);
  } else p = 0;
  }
  
  FILE *salida=fopen("abrir.txt", "w");
  if (salida==NULL){
    int mi_error=errno; 
    printf("Hubo un error en la escritura del archivo: %d <<%s>>\nPor finalizar la ejecucion del programa.\n", 
      mi_error, strerror(mi_error));
    fclose(entrada);
    return -1;
  }

  TipoCoeficiente(salida, tipo);
  a = leeP(p, tipo,entrada);
  fprintf(salida,"\nEl primer polinomio es:\n");
  escP(a, tipo,salida);
  b = leeP(p, tipo,entrada);
  fprintf(salida,"\nEl segundo polinomio es:\n");
  escP(b, tipo,salida);

  fprintf(salida,"\nLa suma  es:\n");
  s = suma(a, b, tipo);
  escP(s, tipo,salida);
  liberaP(&s);
  fprintf(salida,"\nLa resta es:\n");
  m = rest(a, b, tipo);
  escP(m, tipo,salida);
  liberaP(&m);
  fprintf(salida,"\nEl producto es:\n");
  v = mult(a, b, tipo, p);
  escP(v, tipo,salida);
  liberaP(&v);

  if(tipo==2) {
    return;
  }else{
    if (esCero(b)) fprintf(salida,"\n No se puede dividir entre 0. Ingrese otro polinomio.\n");
    else{
      fprintf(salida,"\nLa división es:\n");
      d = divR(a, b, &r, tipo, p);
      escP(d, tipo,salida);
      fprintf(salida,"\nEl residuo es:\n");
      escP(r, tipo,salida);
      liberaP(&r);
      liberaP(&d);
    }
  }
  liberaP(&a);
  liberaP(&b);
  fclose(entrada);
  fclose(salida);
  
  printf("Programa realizado exitosamente");

  return 0;
}
