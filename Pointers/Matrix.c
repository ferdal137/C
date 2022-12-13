#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

typedef struct complejos{
    double re;
    double im;
}COMP;

typedef struct _matriz_{
  int m, n;
  COMP **A;
}MATRIZ;


MATRIZ creaEspacioMatriz(int m, int n);
int leeMatriz(MATRIZ *mat);
int escMatriz(MATRIZ mat);
int liberaEspacioMatriz(MATRIZ *mat);


int main(int argc, char *argv[])
{
  MATRIZ X;

  leeMatriz(&X);
  printf("Los valores asignados a los elementos de la matriz son:\nm=%d, n=%d, A=%p\n", X.m, X.n, X.A);
  escMatriz(X);
  printf("Ahora se va a liberar el espacio creado ...\n");
  liberaEspacioMatriz(&X);
  printf("Espacio liberado.\n");
  printf("Los valores asignados a los elementos de la matriz son:\nm=%d, n=%d, A=%p\n", X.m, X.n, X.A);

  printf("FIN\n");

  return 0;
}

MATRIZ creaEspacioMatriz(int m, int n)
{
  MATRIZ ret={m:m, n:n, A:NULL}; /*en caso que esto no la aceptara el 
                                   compilador, se puede usar
                                   ret = {m, n, NULL} debido a que
                                   sabemos el orden de los campos
                                  */
  int i;

  ret.A = (double**)malloc(m*sizeof(double*));
  if (ret.A!=NULL){
    for(i=0; i<m; i++){
      ret.A[i] = (double *)malloc(n*sizeof(double));
      if (ret.A[i]==NULL){
        while(i>0){
          free(ret.A[--i]);/*liberando espacio previamente reservado
                         (i disminuyo antes de ser liberado A[])
                        */
          ret.A[i] = NULL;
        }
        break;
      }
    }
  }

  return ret;
}

int leeMatriz(MATRIZ *mat)
{
  int m, n, i, j;
  COMP z;

  if (mat == NULL) return -1; /*codigo de error*/
  printf("Digite numero de renglones m:");
  scanf("%d", &m);
  printf("Digite numero de columnas n:");
  scanf("%d", &n);
  *mat = creaEspacioMatriz(m, n);
  printf("digite las entradas de la matriz:\n");
  for(i=0; i<m; i++)
    for (j=0; j<n; j++){
      printf("Por leer un numero complejo de la celda [%2d, %2d]= ", i, j);
      printf("\nDigite la parte real: ");
      scanf("%lg", &(z.re)); 
      printf("Digite la parte imaginaria:");
      scanf("%lg", &(z.im));
      //printf("[%2d, %2d]=", i, j);
      mat->A[i][j] = z;
    }

  return 0; /*codigo de terminacion exita*/
}

int escMatriz(MATRIZ mat)
{
  int i, j;

  for (i=0; i<mat.m; i++){
    printf("\n");
    for (j=0; j<mat.n; j++){
      printf("%6lg ", mat.A[i][j]);
    }
  }
  printf("\n");

  return 0;
}

int liberaEspacioMatriz(MATRIZ *mat)
{
  int i;

  for (i=0; i<mat->m; i++){
    free(mat->A[i]);
    mat->A[i]=NULL;
  }
  free(mat->A);
  mat->A=NULL;
  mat->m = mat->n = 0;

  return 0;
}