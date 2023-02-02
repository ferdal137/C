#ifndef _POLISL_
#define _POLISL_

#ifdef __cplusplus
extern "C" {
#endif
#define EPSILON 1e-5
//Racionales
typedef struct _Q_{
	int p, q;
}Q;

int mcd(int a, int b);
Q sumaQ(Q a, Q b);
Q restaQ(Q a, Q b);
Q prodQ(Q a, Q b);
Q divQ(Q a, Q b);
Q simplificaQ(Q a);
void escribeQ(Q a,FILE *archivo);
Q creaQ(int num, int den);
Q leerQ(FILE *archivo);

//Complejos
typedef struct _C_{
	double Re, Im;
}C;

C sumaC(C X, C Y);
C restaC(C X, C Y);
C prodC(C X, C Y);
C leerC(FILE *archivo);
C divC(C X, C Y);
void escribeC(C X,FILE *archivo);

//Gaussianos
typedef struct _G_{
	int Re;
	int Im;
}G;

G sumaG(G X, G Y);
G restaG(G X, G Y);
G prodG(G X, G Y);
G divG(G X, G Y);
void escribeG(G X,FILE *archivo);
G leerG(FILE *archivo);

//Gaussianos racionales
typedef struct _GR_{
	Q Re;
	Q Im;
}GR;

GR sumaGR(GR X, GR Y);
GR restaGR(GR X, GR Y);
GR prodGR(GR X, GR Y);
GR divGR(GR X, GR Y);
GR leerGR(FILE *archivo);
void escribeGR(GR X,FILE *archivo);
Q leerQG(FILE *archivo);

//Zp
typedef struct _zp_{
	int a, p;
}zp;

zp sumazp(zp a, zp b);
zp restazp(zp a, zp b);
zp prodzp(zp a, zp b);
zp invzp(zp x);
zp divzp(zp a, zp b);
zp leerzp(int p,FILE *archivo);
int escribezp(zp a,FILE *archivo);
zp neg(zp a);

//Cuaterniones
typedef struct _H_{
	double Re;     
	double Imi;     
	double Imj;
	double Imk;
}H;

H leerH(FILE *archivo);
H sumaH(H X, H Y);
H restaH(H X, H Y);
H prodH(H X, H Y);
H invH(H h);
H divH(H X, H Y);
int escribeH(H Z,FILE *archivo);
int escAuxH(double r, char h, char s,FILE *archivo);

//Coeficientes
enum tipoCoeficiente{MODP, RAC, GAU, COM, GAUR, QUA, TOTAL};
typedef union _coef_{
	zp a;
	Q b;
	G c;
	C d;
	GR e;
	H f;
}Coeficiente;

//Polinomios
typedef struct _Rx_ {
  int g;
  Coeficiente *c;
} Rx;

Rx leeP(int p, enum tipoCoeficiente tipo,FILE *archivo);
int escP(Rx p, enum tipoCoeficiente tipo,FILE *archivo);
Rx suma(Rx a, Rx b, enum tipoCoeficiente tipo);
Rx rest(Rx a, Rx b, enum tipoCoeficiente tipo);
Rx mult(Rx a, Rx b, enum tipoCoeficiente tipo, int p);
Rx multMonomio(Rx a, Coeficiente c, int e, int tipo, int p);
Rx divR(Rx a, Rx b, Rx *r, int tipo, int p);
int esCero(Rx a);
Rx copiaP(Rx a);
Rx copiaMenosP(Rx a);
int liberaP(Rx *a);
Rx ceroP(int grad, enum tipoCoeficiente tipo, int p);
int TipoCoeficiente(FILE *f, int Tipo);

Coeficiente opera(Coeficiente a, Coeficiente b, void *operacion, enum tipoCoeficiente tipo);//ya
int esccoef(Coeficiente a, enum tipoCoeficiente tipo, FILE *archivo);
Coeficiente leecoef(int p, enum tipoCoeficiente tipo,FILE *archivo);
int leerTipo(FILE *archivo);
int dacero(Coeficiente a, enum tipoCoeficiente tipo);
Coeficiente negativo(Coeficiente a, enum tipoCoeficiente tipo);

int dauno(Coeficiente a, int tipo);
void Parentesis(int tipo, int posicion,FILE *archivo);
int regresauno(Coeficiente a, int tipo);
int signo(Coeficiente a, int tipo);
Coeficiente givecero(enum tipoCoeficiente tipo, int p);

#ifdef __cplusplus
}
#endif

#endif