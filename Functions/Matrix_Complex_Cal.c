#include <stdio.h>    /funciones de entrada y salida est'andar/
#include <stdlib.h>   /funciones de la biblioteca est'andar/   
#include <time.h>     /funciones de la biblioteca time, manejo de hora y fechas/   
#include <string.h>   /funciones de la biblioteca string, manejo de cadenas de caracteres/

typedef struct Q{
  int p, q;        
}Q;

#define MAXREN 10
#define MAXCOL 10

typedef struct matriz{
  int n, m;
  Q A[MAXREN][MAXCOL];
}MATRIZ;

/*
 * Declaracion de funciones de un ejemplo anterior sobre
 * operaciones de racionales
 */
int mcd(int a, int b);
Q sumaQ(Q a, Q b);    
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);
Q simplificaQ(Q a);
void escribeQ(Q a);    
Q creaQ(int num, int den);

/*
 * Declaracion de funciones para el manejo de matrices
 */

MATRIZ sumaM(MATRIZ X, MATRIZ Y);
MATRIZ restaM(MATRIZ X, MATRIZ Y);
MATRIZ prodM(MATRIZ X, MATRIZ Y);
void escribeM(MATRIZ X);


int main(int argc, char *argv[])
{
  MATRIZ a, b, r;
  int i, j, k;

  a.m = b.m = 3;
  a.n = b.n = 3;

  /* la declaracion de la funcion srand se encuentra en stdlib
   * y sirve iniciar la secuencia aleatoria utilizada en rand
   * time obtiene la hora del reloj en un formato especial que
   * no tiene importancia en este ejemplo. Para mayor informacion 
   * consultar la especificacion de la funcion time() 
   */
  srand(time(NULL));

  /* Se va a crear una matriz de forma "aleatoria", pero se debe
   * implementar una funcion que permita la lectura de una matriz
   * desde la entrada estandar
   */
  for (i=0; i<a.m; i++)
    for (j=0; j<a.n; j++){ 
    /* la declaracion de la funcion rand se encuentra en stdlib
     * y sirve para obtener numeros aleatorios.
     */
      a.A[i][j] = creaQ(rand()%20, (rand()%15)+1);
      b.A[i][j] = creaQ(rand()%20, (rand()%15)+1);
    }

  printf("las matrices a sumar son:\n\tPrimera matriz mxn (%d x %d):\n", a.m, a.n);
  escribeM(a);
  printf("\n\tSegunda matriz mxn (%d x %d):\n", b.m, b.n);
  escribeM(b);

  r = sumaM(a, b);
  printf("\nEl resultado es una matriz  mxn (%d x %d):\n", r.m, r.n);
  escribeM(r);
  
  r = restaM(a, b);
  printf("\nEl resultado es una matriz  mxn (%d x %d):\n", r.m, r.n);
  escribeM(r);

  r = prodM(a, b);
  printf("\nEl resultado es una matriz  mxn (%d x %d):\n", r.m, r.n);
  escribeM(r);
	

  printf("\n\nFIN DEL PROGRAMA\n");      

  return 0;
}          

/*
 * Definicion de funciones para el manejo de racionales
 * vistas en un ejemplo anterior
 */

int mcd(int a, int b)
{                    
  int r;             

  if (a < 0) a=-a;
  if (b < 0) b=-b;
  if (b == 0) return a;

  while ((r=a%b) != 0){
    a = b;             
    b = r;             
  }                    

  return b;
}          

Q simplificaQ(Q a)
{                     
  int d;
  Q regreso;

  regreso = a;
  d = mcd (a.p, a.q);
  if (d>1){            
    regreso.p /= d;         
    regreso.q /= d;         
  }                    
  if (regreso.q < 0){       
    regreso.p *= -1;        
    regreso.q *= -1;        
  }

  return regreso;
}

Q sumaQ(Q a, Q b)
{                
  Q r;           

  r.p = a.p*b.q + a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);

  return r;
}

Q restaQ(Q a, Q b)
{
	Q r;
	
	r.p = a.p*b.q - a.q*b.p;
	r.q = a.q*b.q;
	r=simplificaQ(r);
	
	return r;
}

Q prodQ(Q a, Q b)
{
	Q r;
	
	r.p = a.p*b.p;
	r.q = a.q*b.q;
	r=simplificaQ(r);
	
	return r;
}

Q divQ(Q a, Q b)
{
	Q r;
	
	r.p = a.p*b.q;
	r.q = a.q*b.p;
	r=simplificaQ(r);
	
	return r;
}

/* Modificacion a la funcion del ejemplo anterior 
 * para escribir un racional con cierto formato
 */
void escribeQ(Q a)
{
  char buferTemporal[128];
  int l;

  sprintf(buferTemporal, "%d", a.p);
  l = strlen(buferTemporal);
  if (a.q!= 1) sprintf(buferTemporal+l, "/%d", a.q);
  printf("%7s", buferTemporal);
}

Q creaQ(int num, int den)
{
  Q r = {num, den};

  r=simplificaQ(r);

  return r;
}

/*
 * Definicion de las funciones para el manejo de matrices
 */

MATRIZ sumaM(MATRIZ X, MATRIZ Y)
{
  MATRIZ porRegresar;
  int i, j;

  porRegresar.m = porRegresar.n = 0;

  if ( (X.m!=Y.m) || (X.n!=Y.n)){
    printf("No se puede realizar la suma de las matrices...\n");
    return porRegresar;
  }

  porRegresar.m = X.m;
  porRegresar.n = X.n;

  for (i=0; i<X.m; i++)
    for (j=0; j<X.n; j++)
      porRegresar.A[i][j] = sumaQ(X.A[i][j], Y.A[i][j]);

  return porRegresar;
}

MATRIZ prodM(MATRIZ X, MATRIZ Y)
{
  MATRIZ porRegresar;
  int i, j, k;

  porRegresar.m = porRegresar.n = 0;

  if ((X.n!=Y.m) || (X.m!=Y.n)){
    printf("No se puede realizar el producto de las matrices...\n");
    return porRegresar;
  }

  porRegresar.m = X.m;
  porRegresar.n = Y.n;

 for (i=0; i<X.m; i++)
    for (j=0; j<Y.n; j++)
    	porRegresar.A[i][j]=creaQ(0,1);
    	
	for (k=0; k<Y.n; k++)
	    for (i=0; i<X.m; i++)
	    	for (j=0; j<X.n; j++)
	    		porRegresar.A[i][k] = sumaQ(porRegresar.A[i][k], (prodQ(X.A[i][j], Y.A[j][k])) );

  return porRegresar;
}

MATRIZ restaM(MATRIZ X, MATRIZ Y)
{
  MATRIZ porRegresar;
  int i, j;

  porRegresar.m = porRegresar.n = 0;

  if ( (X.m!=Y.m) || (X.n!=Y.n)){
    printf("No se puede realizar la resta de las matrices...\n");
    return porRegresar;
  }

  porRegresar.m = X.m;
  porRegresar.n = X.n;

  for (i=0; i<X.m; i++)
    for (j=0; j<X.n; j++)
      porRegresar.A[i][j] = restaQ(X.A[i][j], Y.A[i][j]);

  return porRegresar;
}

void escribeM(MATRIZ X)
{
  int i, j;
  for (i=0; i<X.m; i++){
    for (j=0; j<X.n; j++){
      escribeQ(X.A[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}