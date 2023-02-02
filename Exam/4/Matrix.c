#include<stdio.h>
#include<stdlib.h>

#include<errno.h> 
#include<string.h>
#include "U.h"
#include "Rx.h"

typedef struct _Mat_{
  int m, n;
  Rx **ent;
}Mat;

Mat iniMat(int m, int n,enum tipoCoeficiente tipo);
Mat multMat(Mat A, Mat B, enum tipoCoeficiente tipo);
Mat leeM(FILE *f, int p, enum tipoCoeficiente tipo);
int escMat(FILE *f, Mat A, enum tipoCoeficiente tipo);
Mat sumaMat(Mat A, Mat B, enum tipoCoeficiente tipo);
Mat restaMat(Mat A, Mat B, enum tipoCoeficiente tipo);

int main(int argc, char argv[])
{
  FILE *ent, *sal;
  Mat A, B, C;
  int m, n, i, j;
	//ABRIR ARCHIVO
  ent=fopen("Matcoef.txt", "rt");
  if(ent==NULL){
    int mi_error=errno; 
    printf("Hubo un error en la lectura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n", 
	   mi_error, strerror(mi_error));
    return -1;
  }
	//LEER TIPO DE COEFICIENTES DE LOS POLINOMIOS
	int tipo, p=0;
	tipo = leerTipo(ent);
	if(tipo==MODP){
		fscanf(ent,"%d",&p);
	}
	//LEER MATRICES
	A=leeM(ent,p,tipo);
	B=leeM(ent,p,tipo);
	//SALIDA
	sal = fopen("Matresult.txt","wt");
	if(sal==NULL){
		int mi_error=errno; 
		printf("Hubo un error en la escritura del archivo. Codigo: %d. Mensaje: <<%s>>\nPor finalizar la ejecucion del programa.\n", 
		mi_error, strerror(mi_error));
		return -1;
	}
	fprintf(sal,"-----Matrices ingresadas-----\n");
	fprintf(sal,"A = \n");
	escMat(sal,A,tipo);
	fprintf(sal,"B = \n");
	escMat(sal,B,tipo);
	fprintf(sal,"-----SUMA-----\n");
	if((A.n!=B.n)||(A.m!=B.m)) fprintf(sal,"La suma no se puede realizar (Los tamaños de las matrices son distintos)\n");
	else{
		C=sumaMat(A,B,tipo);
		escMat(sal,C,tipo);
		free(C.ent);
	    C.ent=NULL;
	}
    fprintf(sal,"-----RESTA-----\n");
    if((A.n!=B.n)||(A.m!=B.m)) fprintf(sal,"La resta no se puede realizar (Los tamaños de las matrices son distintos)\n");
	else{
		C=restaMat(A,B,tipo);
		escMat(sal,C,tipo);
		free(C.ent);
	    C.ent=NULL;
	}

    fprintf(sal,"-----PRODUCTO-----\n");
	if (A.n!=B.m){
		fprintf(sal,"No se puede efectuar la multiplicacion de matrices (%d!=%d)\n", A.n, B.m);
	}else{
		C=multMat(A,B,tipo);
		escMat(sal,C,tipo);
		free(C.ent);
	    C.ent=NULL;
	}

	free(A.ent);
	A.ent=NULL;
	free(B.ent);
	B.ent=NULL;
      
    fclose(ent); /*cerrar los archivos que tenemos abiertos en este momento*/
    fclose(sal);
    return 0;
}

Mat iniMat(int m, int n, enum tipoCoeficiente tipo)
{
  Mat ret={m:m, n:n, ent:NULL};
  Rx cero;
  cero.g = -1;
  int i, j;

  ret.ent = (Rx **)malloc(m*sizeof(Rx*));
  if(ret.ent==NULL) return ret;
  for(i=0; i<m; i++){
    ret.ent[i]=(Rx*)malloc(n*sizeof(Rx));
    if(ret.ent[i]==NULL){
      while(--i>=0) free(ret.ent[i]);
      free(ret.ent);
      ret.ent=NULL;
      break;
    }
    for (j=0; j<n; j++) ret.ent[i][j]=cero;
  }

  return ret;
}

Mat multMat(Mat A, Mat B,enum tipoCoeficiente tipo)
{
	void *fs[]={sumaZp, sumaQ, sumaG, sumaC, sumaGr, sumaH};
	void *fp[]={prodZp, prodQ, prodG, prodC, prodGr, prodH};
  Mat ret={m:0, n:0, ent:NULL};
  int i, j, k, p;

  if (A.n!=B.m) return ret;
  p=A.n;
  ret=iniMat(A.m, B.n,tipo);
  for(i=0; i<ret.m; i++)
    for(j=0; j<ret.n; j++)
      for(k=0; k<p; k++)
	ret.ent[i][j]=suma(ret.ent[i][j], mult(A.ent[i][k], B.ent[k][j],fs[tipo],fp[tipo],tipo),fs[tipo],tipo);

  return ret;
}

Mat leeM(FILE *f,int p,enum tipoCoeficiente tipo){
int m,n,i,j;
Mat B;

  fscanf(f, "%d%d", &m, &n);
  B = iniMat(m, n, tipo);
  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      B.ent[i][j]=leeP(f,p,tipo);
      
return B;	
}
int escMat(FILE *f, Mat A,enum tipoCoeficiente tipo)
{
  int i, j,k;
  FILE *aux;
  int espaciosMax[A.n];
  int sizeAux;
  char *cadena;
  long int size;
  fprintf(f, "%dx%d\n", A.m, A.n);
  //CALCULAR mayor numero de caracteres por columna
	for(j=0; j<A.n; j++){
		espaciosMax[j] = 0;
		for(i=0; i<A.m; i++){
			aux = fopen("auxiliarMat.txt","w");
			escP(aux,A.ent[i][j],tipo);
			fseek(aux,0,SEEK_END);
			size = ftell(aux);
			sizeAux = size/sizeof(char);
			fclose(aux);		
			//printf("%d ",sizeAux);
			if(espaciosMax[j]<sizeAux) espaciosMax[j] = sizeAux;
		}
	}
  for(i=0; i<A.m; i++){
    for(j=0; j<A.n; j++){
    	aux = fopen("auxiliarMat.txt","w");
    	escP(aux,A.ent[i][j],tipo);
    	escP(f,A.ent[i][j],tipo);
    	fseek(aux,0,SEEK_END);
		long int size = ftell(aux);
		sizeAux = size/sizeof(char);
		fclose(aux);
		//printf("%d ",sizeAux);
		if(sizeAux!=espaciosMax[j]){
			for(k=0; k<(espaciosMax[j]-sizeAux); k++){
				fprintf(f," ");
			}
		}
		
    	fprintf(f,"\t\t");
	}
    fprintf(f, "\n\n");
  }

  return 0;
}

Mat sumaMat(Mat A, Mat B, enum tipoCoeficiente tipo){
	void *fs[]={sumaZp, sumaQ, sumaG, sumaC, sumaGr, sumaH};
	Mat ret;
	ret=iniMat(A.m,A.n,tipo);
	int i,j;
	ret.n = A.n;
	ret.m = A.m;
	
	for(i=0; i<ret.m; i++){
		for(j=0; j<ret.n; j++){
			ret.ent[i][j] = suma(A.ent[i][j],B.ent[i][j],fs[tipo],tipo);
		}
	}
	return ret;
}

Mat restaMat(Mat A, Mat B, enum tipoCoeficiente tipo){
	void *fr[]={restaZp, restaQ, restaG, restaC, restaGr, restaH};
	Mat ret;
	ret=iniMat(A.m,A.n,tipo);
	int i,j;
	
	ret.n = A.n;
	ret.m = A.m;
	
	for(i=0; i<ret.m; i++){
		for(j=0; j<ret.n; j++){
			ret.ent[i][j] = rest(A.ent[i][j],B.ent[i][j],fr[tipo],tipo);
		}
	}
	return ret;
}