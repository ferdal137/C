

#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

/*este ejemplo es la actualizacion  del ejemplo11a.c con la funcion opera,
 su tarea es poner todos los coeficientes con los que hemos trabajado: 
 Q,R,H,G,Zp y C. Usando la funcion 
 opera, con todas las operaciones en dichos coeficientes*/
 /*Recuerden cualquier duda por el whatsapp*/

enum tipoCoeficiente {ZP, RACIONALES, COMPLEJOS, GAUSS, GAUSSR, CU, TOTAL};

typedef struct _zp_{
  int a;
}ZP;

typedef struct _racionales_{
  int p, q;
}Q;

typedef struct _complejos_{
  double re, im;
}C;

typedef struct _gaussianos_{
  int re, im;
}G;

typedef struct _gaussianosr_{
  int p, q;
  double re, im;
}GR;

typedef struct _cuaterniones_{
  double re, i, j, k;
}CU;


typedef union _coeficiente_{
  ZP A;
  Q unRacional;
  C unComplejo;
  G unGaussiano;
  GR unGaussianoR;
  CU unCuaternion;
}Coeficiente;

int sumaZP(int a, int b);
Q sumaQ(Q a, Q b);
C sumaC(C z, C w);
G sumaG(G z, G w);
GR sumaGR(GR z, GR w);
CU sumaCUA(CU z, CU w);


Coeficiente opera(Coeficiente a, Coeficiente b, void *suma, enum tipoCoeficiente tipo);
int esccoef(Coeficiente a,enum tipoCoeficiente tipo);

int main(int argc, char *argv[])
{
  
  
  
  void *fs[]={sumaZ, sumaQ, sumaC, sumaG, sumaGR, sumaCU};
  void *fs[]={restaZ, restaQ, restaC, sumaG, restaGR, restaCU};
  void *operandos[]={&enta, &entb, &Qa, &Qb, &Ca, &Cb};  //////////// Añadir
  int i;
  Coeficiente a, b,c;

  printf("Ejemplo del uso de funciones y apuntadores\n");
  for(i=ENTEROS; i<TOTAL; i++){
    printf("%d) ", i);
    muestraA(operandos[2*i], operandos[2*i+1], fs[i], i);
  }

  printf("\nEjemplo del uso de uniones, funciones y apuntadores\n");
  a.unEntero = enta;
  b.unEntero = entb;
  muestraB(a, b, fs[ENTEROS], ENTEROS);
  a.unRacional = Qa;
  b.unRacional = Qb;
  muestraB(a, b, fs[RACIONALES], RACIONALES);
  a.unReal = reaa;
  b.unReal = reab;
  muestraB(a, b, fs[REALES], REALES);
  a.unComplejo = Ca;
  b.unComplejo = Cb;
  muestraB(a, b, fs[COMPLEJOS], COMPLEJOS);
  a.unZ11 = m11a;
  b.unZ11 = m11b;
  muestraB(a, b, fs[MOD11], MOD11);
  
    printf("\nEjemplo del uso de uniones, funciones y apuntadores, el bueno.\n");
  
  a.unEntero = enta;
  b.unEntero = entb;
    c=opera(a,b,fs[ENTEROS], ENTEROS);
    esccoef(a,ENTEROS);
    printf("+");
    esccoef(b,ENTEROS);
    printf("=");
    esccoef(c,ENTEROS);
     printf("\n");
   a.unRacional = Qa;
  b.unRacional = Qb;
  c=opera(a,b, fs[RACIONALES], RACIONALES);
    esccoef(a,RACIONALES);
    printf("+");
    esccoef(b,RACIONALES);
    printf("=");
    esccoef(c,RACIONALES);
     printf("\n");
  a.unReal = reaa;
  b.unReal = reab;
  c=opera(a,b,  fs[REALES], REALES);
    esccoef(a,REALES);
    printf("+");
    esccoef(b,REALES);
    printf("=");
    esccoef(c,REALES);
     printf("\n");
  a.unComplejo = Ca;
  b.unComplejo = Cb;    
  c=opera(a,b,fs[COMPLEJOS], COMPLEJOS);
    esccoef(a,COMPLEJOS);
    printf("+");
    esccoef(b,COMPLEJOS);
    printf("=");
    esccoef(c,COMPLEJOS);
     printf("\n"); 
  a.unZ11 = m11a;
  b.unZ11 = m11b;
  c=opera(a,b, fs[MOD11], MOD11);
    esccoef(a,MOD11);
    printf("+");
    esccoef(b,MOD11);
    printf("=");
    esccoef(c,MOD11);
     printf("\n"); 
  printf("\nFIN\n");

  return 0;
}



int sumaZ(int a, int b)
{ return a+b;
}
int sumam11(int a, int b)
{ return ((a+b)%11+11)%11;
}
Q sumaQ(Q a, Q b)
{
  Q ret;

  ret.p = a.p*b.q+a.q*b.p;
  ret.q = a.q*b.q;

  return ret;
}

double sumaR(double a, double b)
{
  return a+b;
}

C sumaC(C z, C w)
{
  C ret;

  ret.re = z.re+w.re;
  ret.im = z.im+w.im;

  return ret;
}

int sumaM11(int a, int b)
{
  return (((a+b)%11)+11)%11;
}

int muestraA(void *a, void *b, void *suma, enum tipoCoeficiente tipo)
{
  ZP (*)
  Q (*fRacional)(Q, Q);
  C (*fCompleja)(C, C);
  int enteroA, enteroB;
  Q racionalA, racionalB, retQ;
  double realA, realB;
  C complejoA, complejoB, retC;

  if (tipo==ENTEROS){
    fEntera = suma;
    enteroA = *(int*)a;
    enteroB = *(int*)b;
    printf("F(%d, %d) = %d\n", enteroA, enteroB, fEntera(enteroA, enteroB));
  } else if (tipo==RACIONALES){
    racionalA = *(Q *)a;
    racionalB = *(Q *)b;
    fRacional = suma;
    retQ = fRacional(racionalA, racionalB);
    printf("F(%d/%d, %d/%d) = %d/%d\n", 
	   racionalA.p, racionalA.q, 
	   racionalB.p, racionalB.q, retQ.p, retQ.q);
  } else if (tipo==REALES){
    realA = *(double*)a;
    realB = *(double *)b;
    fReal = suma;
    printf("F(%lg, %lg) = %lg\n", realA, realB, fReal(realA, realB));
  } else if (tipo==COMPLEJOS){
    complejoA = *(C *)a;
    complejoB = *(C *)b;
    fCompleja = suma;
    retC = fCompleja(complejoA, complejoB);
    printf("F(%lg%+lg i, %lg%+lg i) = %lg%+lg i\n", 
	   complejoA.re, complejoA.im,
	   complejoB.re, complejoB.im, retC.re, retC.im);
  } else if (tipo==MOD11){
    enteroA = *(int*)a;
    enteroB = *(int*)b;
    fEntera = suma;
    printf("F(%d, %d) = %d\n", enteroA, enteroB, fEntera(enteroA, enteroB));
  } 

  return 0;
}

int muestraB(Coeficiente a, Coeficiente  b, void *suma, enum tipoCoeficiente tipo)
{
  int (*fEntera)(int, int);
  Q (*fRacional)(Q, Q);
  double (*fReal)(double, double);
  C (*fCompleja)(C, C);
  Q retQ;
  C retC;

  if (tipo==ENTEROS){
    fEntera = suma;
    printf("F(%d, %d) = %d\n", a.unEntero, b.unEntero, fEntera(a.unEntero, b.unEntero));
  } else if (tipo==RACIONALES){
    fRacional = suma;
    retQ = fRacional(a.unRacional, b.unRacional);
    printf("F(%d/%d, %d/%d) = %d/%d\n", 
	   a.unRacional.p, a.unRacional.q, 
	   b.unRacional.p, b.unRacional.q, retQ.p, retQ.q);
  } else if (tipo==REALES){
    fReal = suma;
    printf("F(%g, %g) = %g\n", a.unReal, b.unReal, fReal(a.unReal, b.unReal));
  } else if (tipo==COMPLEJOS){
    fCompleja = suma;
    retC = fCompleja(a.unComplejo, b.unComplejo);
    printf("F(%lg%+lg i, %lg%+lg i) = %lg%+lg i\n", 
	   a.unComplejo.re, a.unComplejo.im, 
	   b.unComplejo.re, b.unComplejo.im, retC.re, retC.im);
  } else if (tipo==MOD11){
    fEntera = suma;
    printf("F(%d, %d) = %d\n", a.unZ11, b.unZ11, fEntera(a.unZ11, b.unZ11));
  } 

  return 0;
}

Coeficiente opera(Coeficiente a, Coeficiente  b, void *suma, enum tipoCoeficiente tipo)
{
  ZP (*fZP)(ZP, ZP);     
  Q (*fRacional)(Q, Q);
  C (*fCompleja)(C, C);
  G ()
  GR
  CU
  Coeficiente ret;

  switch(tipo){
  	case 0: fZP=suma;
  	ret.A=fZP(a.A, b.A);
  	break;
  	case 1: fQ=suma;
  	ret.B=fQ(a.B b.B);
  	break;
  	case 2: fC=suma;
  	ret.C=fC(a.C,b.C);
  	break;
  	case 3: fG=suma;
  	ret.D=fG(a.D, b.D);
  	break;
  	case 4: fGR=suma;
  	ret.E=fGR(a.E,b.E);
  	break;
  	case 5: fCU=suma;
  	ret.F=fCU(a.F,b.F);
  	break;
  }

/*
  if (tipo==ENTEROS){
    fEntera = suma;
     ret.unEntero= fEntera(a.unEntero, b.unEntero);
  } else if (tipo==RACIONALES){
    fRacional = suma;
    ret.unRacional = fRacional(a.unRacional, b.unRacional);
   } else if (tipo==REALES){
    fReal = suma;
    ret.unReal=fReal(a.unReal, b.unReal);
  } else if (tipo==COMPLEJOS){
    fCompleja = suma;
    ret.unComplejo = fCompleja(a.unComplejo, b.unComplejo);
  
  } else if (tipo==MOD11){
    fm11 = suma;
    ret.unZ11 =fm11(a.unZ11, b.unZ11);
  }*/

  return ret;
}
/* Recuerden que hicimos una funcion escribe
 coeficiente, entonces para que se parezca es
necesario que también deben tener funciones 
para escribir cada tipo, es decir escQ,escC,escm11,etc
En nuestro ejemplo de clase el tipo estaba 
dentro de la estructura Coef, esta otra forma es equivalente*/ 
int esccoef(Coeficiente a,enum tipoCoeficiente tipo)
{
   if (tipo==ENTEROS){
    printf(" %d", a.unEntero);
  } else if (tipo==RACIONALES){
    printf(" %d/%d", a.unRacional.p, a.unRacional.q);
  } else if (tipo==REALES){
    printf("%lg", a.unReal);
  } else if (tipo==COMPLEJOS){
      printf("%lg%+lg i",a.unComplejo.re, a.unComplejo.im);
  } else if (tipo==MOD11){
    printf("%d", a.unZ11);
  } 

  return 0;	
}