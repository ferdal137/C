#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

/*
  tipo enumerado: enum ID_DE_TIPO { ID_VALIDOS separados por comas }
  los identificadores corresponden a valores enteros iniciando en 
  cero e incrementandose de uno en uno. Se puede alterar esa asignacion
  escribiendo ID_VALIDO = valor
*/
enum TIPOCOEF{ MOD7, ENT, RAC, REA, COM};

typedef struct _Q_{
  int p, q;
}Q;

typedef struct _C_{
  double a, b;
}C;

/*
  Con la union estamos representando a un tipo de coeficiente
  de una variedad. Falta implementar las funciones que manejen
  las operaciones aritmeticas (suma, multiplicacion, etc.)
*/
typedef union _coef_{
   int m7;
   int a;
   Q b;
   double c;
   C d;
}coef;

/*
  Estructura que se axilia de la forma de identificar el tipo
  de coeficiente y de la union para el coeficiente mismo.
 */
typedef struct _coeficiente_{
  int tipo;
  coef c;
}coeficiente;

coeficiente leeCoeficiente(void);
int escribeCoeficiente(coeficiente A);



int main(int argc, char *argv[])
{
  coeficiente miCoef;

  printf("por leer un coeficiente de acuerdo al tipo seleccionado conforme a la siguiente codificacion:\n");
  miCoef = leeCoeficiente();
  printf("El valor ingresado es:");
  escribeCoeficiente(miCoef);
  printf("\nFin del programa\n");

  return 0;
}          

coeficiente leeCoeficiente(void)
{
  int tipo;
  coeficiente A;

  printf(
    "digite  0 para coeficientes de tipo Entero mod 7.\n"
    "digite  1 para coeficientes de tipo Entero.\n"
    "digite  2 para coeficientes de tipo Racional.\n"
    "digite  3 para coeficientes de tipo Real.\n"
    "digite  4 para coeficientes de tipo Comlejo.\n"
  );

  printf("Su opcion: ");
  scanf("%d", &tipo);

  A.tipo = tipo;
  switch(tipo){ 
    case MOD7:
      printf("digite un entero:"); scanf("%d", &A.c.m7);
      A.c.m7 = ((A.c.m7%7)+7)%7;
      break;
    case ENT:
      printf("digite un entero:"); scanf("%d", &A.c.a);
      break;
    case RAC:
      printf("digite el numerador y denominador de un numero racional:");
      scanf("%d%d", &A.c.b.p, &A.c.b.q);
      /*simplificar racional para que quede p/q con mcd(p,q)=1 y q>0*/
      break;
    case REA:
      printf("digite un numero real:");
      scanf("%lf", &A.c.c);
      break;
    case COM:
      printf("digite la parte real y la parte imaginaria de un numero compleo:");
      scanf("%lf%lf", &A.c.d.a, &A.c.d.b);
      break;
    default:
      printf("tipo de dato invalido...\n");
  }

  return A;
}



int escribeCoeficiente(coeficiente A)
{
  switch(A.tipo){
    case MOD7: printf("%d", A.c.m7); break;
    case ENT: printf("%+d", A.c.a); break;
    case RAC: printf("%+d", A.c.b.p);
              if (A.c.b.q>1) printf("/%d", A.c.b.q);
              break;
    case REA: printf("%+lg", A.c.c); break;
    case COM: printf("%+lg", A.c.d.a);
              if (A.c.d.b!=0.0) printf(" %+lg i", A.c.d.b);
              break;
    default: printf("tipo de dato invalido.");
  }

  return 0;
}
