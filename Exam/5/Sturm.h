#ifndef _STURML_
#define _STURML_

#ifdef __cplusplus
extern "C" {
#endif

//////Polinomios
typedef struct _Polinomios_{
  int g;
  double *c;
}Rx;

FILE *f;
Rx leeP(FILE *f);
void escP(Rx p);
Rx suma(Rx a, Rx b);
Rx rest(Rx a, Rx b);
Rx mult(Rx a, Rx b);
Rx multMonomio(Rx a, double c, int e);
Rx divR(Rx a, Rx b, Rx *r);
int esCero(Rx a);
Rx copiaP(Rx a);
Rx copiaMenosP(Rx a);
int  liberaP(Rx *a);
Rx derivada(Rx a);
Rx ResiduoSimple(Rx a,Rx b);
Rx MCD(Rx a, Rx b);
double cota(Rx a);
double EvaluaP(Rx a, double c);
double potencia(double c, int n);

////Sturm
typedef struct _PolinomiosSturm_{
  int h;
  Rx *p;
}PoliSturm;
typedef struct _Orillas_{
  int k;
  double *e;
}Orillas;
typedef struct _Intervalos_{
  int t;
  double *c;
}Inter;
FILE *f;
PoliSturm sistemaSturm(Rx a);
int escribeSturm(Rx a);
int variaciones(double a, Rx p);
void  liberaPoliSturm(PoliSturm *a);
int XD(double a, double b, Rx p);
Inter separa(Rx p);
void  liberaInter(Inter *a);
void  liberaOrillas(Orillas *a);
void  escribeSepa(FILE *f, Inter J);
void escribeD(FILE *f, Inter J);
void escArchP(FILE *f, Rx a);
void Sturm(FILE *ent, FILE *sal, FILE *SalDos);

#ifdef __cplusplus
}
#endif

#endif