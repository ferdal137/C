#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

/*
  tipo enumerado: enum ID_DE_TIPO { ID_VALIDOS separados por comas }
  los identificadores corresponden a valores enteros iniciando en 
  cero e incrementandose de uno en uno. Se puede alterar esa asignacion
  escribiendo ID_VALIDO = valor
*/
enum TIPOCOEF{ MODP, RAC, GAU, COMP, GAR, CUA};

typedef struct _ZP_{
	int a, p;
}Zp;

typedef struct Q{
  int p, q;        
}Q;

typedef struct gaussianos{
    int re;
    int im;
}GAUSS;

typedef struct complejos{
    double re;
    double im;
}COMP;



/*
  Con la union estamos representando a un tipo de coeficiente
  de una variedad. Falta implementar las funciones que manejen
  las operaciones aritmeticas (suma, multiplicacion, etc.)
*/
typedef union _coef_{
   Zp a;
   Q b;
   GAUSS c;
   COMP d;
   GAUSSRAC e;
}coef;

/*
  Estructura que se axilia de la forma de identificar el tipo
  de coeficiente y de la union para el coeficiente mismo.
 */
typedef struct _coeficiente_{
  int tipo;
  coef c;
}coeficiente;

//ZP
Zp sumaZp(Zp a, Zp b);
Zp restaZp(Zp a, Zp b);
Zp prodZp(Zp a, Zp b);
Zp inverZp(Zp x);
Zp divZp(Zp a, Zp b);
Zp LeerZp(int p);
int escZp(Zp a);
//

//Ra
int mcd(int a, int b);
Q sumaQ(Q a, Q b);    
Q restaQ(Q a, Q b);  
Q prodQ(Q a, Q b);  
Q divQ(Q a, Q b);  
Q simplificaQ(Q a);
Q leerQ(void);
void escribeQ(Q a);    
Q creaQ(int num, int den); 
//

//Gaussian
GAUSS leerG();
GAUSS sumaG(GAUSS z, GAUSS y);
GAUSS restaG(GAUSS z, GAUSS y);
GAUSS prodG(GAUSS z, GAUSS y);
float modG(GAUSS z);
void escribG(GAUSS z);
//

//Complex
COMP leerC();
COMP suma(COMP z, COMP y);
COMP resta(COMP z, COMP y);
COMP prod(COMP z, COMP y);
float mod(COMP z);
void escrib(COMP z);
//

//Gauss Racional


coeficiente leeCoe(int p);
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

//ZP
Zp sumaZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.a = a.a + b.a;
	c.a %= c.p;
	
	return c;
}

Zp restaZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.a = a.a - b.a;
	c.a = (c.a%c.p + c.p)%c.p;
	
	return c;
}

Zp prodZp(Zp a, Zp b){
	Zp c;
	c.p = a.p;
	c.a = a.a * b.a;
	c.a %= c.p;
	
	return c;
}

Zp inverZp(Zp x){
	
	int s0, a, b, r, s_1, q, s;
	a = x.a;
	b = x.p;
	
	s0 = 0;
    s_1 = 1;
    while((r=a%b)!=0){
      q = a/b;
      a=b;
      b=r;
      s=s0;
      s0=s_1-q*s0;
      s_1=s;
	}
	
	x.a = (s0%x.p + x.p)%x.p;
	
	return x;
	
}

Zp divZp(Zp a, Zp b){
	
	Zp c;
	
	c = inverZp(b);
	c = prodZp(c, a);
	
	return c;
	
}

Zp LeerZp(int p){
	
	Zp c;
	c.p = p;
	printf("Digite un entero: ");
	scanf("%d",&c.a);
	c.a = (c.a%c.p + c.p)%c.p;
	
	return c;
}

int escZp(Zp a){
	
	printf("%d",a.a);
	
	return 0;
}
//

//Rac
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

void escribeQ(Q a)
{
  printf("%d", a.p);
  if (a.q!= 1) printf("/%d", a.q);
}

Q creaQ(int num, int den)
{
  Q r = {num, den};

  r=simplificaQ(r);

  return r;
}

Q leerQ(void){
	
	Q n;
	printf("Escribe el numerador: ");
	scanf("%d",&n.p);
	
	do{
		printf("Escribe un denominador distinto de cero: ");
		scanf("%d",&n.q);
	}while(n.q==0);
	
	n=simplificaQ(n);
	return n;
}
//

//Gaussian
GAUSS leerG(){

    GAUSS z;

    printf("Por leer un numero gaussiano.\nDigite la parte real:");
    scanf("%d", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%d", &(z.im));


    return z;

}

void escribG(GAUSS z){
    
    printf("%d %+d i\n", z.re, z.im);
    
    
}

GAUSS sumaG(GAUSS z, GAUSS y){

    GAUSS c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


GAUSS restaG(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


GAUSS prodG(GAUSS z, GAUSS y){
    
    GAUSS c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float modG(GAUSS z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}
//


//Complex
COMP leerC(){

    COMP z;

    printf("Por leer un numero complejo.\nDigite la parte real:");
    scanf("%lg", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%lg", &(z.im));


    return z;

}

void escrib(COMP z){
    
    printf("%lg %+lg i\n", z.re, z.im);
    
    return 0;
    
}

COMP suma(COMP z, COMP y){

    COMP c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


COMP resta(COMP z, COMP y){
    
    COMP c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


COMP prod(COMP z, COMP y){
	
    COMP c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
    
}

float mod(COMP z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}
//

coeficiente leeCoe(int p)
{
  int tipo, p;
  coeficiente A;

  printf(
    "digite  0 para coeficientes de tipo Entero mod.\n"
    "digite  1 para coeficientes de tipo Racional.\n"
    "digite  2 para coeficientes de tipo Gaussianos.\n"
    "digite  3 para coeficientes de tipo Complejos.\n"
    "digite  4 para coeficientes de tipo Gaussianos Racionales.\n"
    "digite  5 para coeficientes de tipo Cuaterniones.\n"
  );

  printf("Su opcion: ");
  scanf("%d", &tipo);

  A.tipo = tipo;
  switch(tipo){ 
    case Zp:
      A.c.a = leerZp(p);
      printf("digite un entero:"); scanf("%d", &A.c.m7);
      A.c.m7 = ((A.c.m7%7)+7)%7;
      break;
    case RAC:
      A.c.b = leerQ();
      printf("digite un entero:"); scanf("%d", &A.c.a);
      break;
    case GAU:
      A.c.c = leerG();
      printf("digite el numerador y denominador de un numero racional:");
      scanf("%d%d", &A.c.b.p, &A.c.b.q);
      /*simplificar racional para que quede p/q con mcd(p,q)=1 y q>0*/
      break;
    case COMP:
      A.c.d = leerC();
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
    case MODP: printf("%d", A.c.a); break;
    case ENT: printf("%+d", A.c.b); break;
    case RAC: printf("%+d", A.c.c);
              if (A.c.b.q>1) printf("/%d", A.c.b.q);
              break;
    case REA: printf("%+lg", A.c.d); break;
    case COM: printf("%+lg", A.c.e);
              if (A.c.d.b!=0.0) printf(" %+lg i", A.c.d.b);
              break;
    default: printf("tipo de dato invalido.");
  }

  return 0;
}

int main(int argc, char *argv){
	
	Zp a, b, c;
	int p;
	
	printf("Este programa opera numeros en Zp");
	printf("\nEscriba un numero primo: ");
	scanf("%d",&p);
	
	a = LeerZp(p);
	b = LeerZp(p);
	printf("\nLa suma de los numeros es: ");
	c = sumaZp(a, b);
	escZp(c);
	
	printf("\nLa resta de los numeros es: ");
	c = restaZp(a, b);
	escZp(c);
	
	printf("\nEl producto de los numeros es: ");
	c = prodZp(a, b);
	escZp(c);
	
	printf("\nEl inverso de los numeros es: ");
	c = inverZp(a);
	escZp(c);
	
	if(b.a==0){
		printf("\nNo se puede dividir");
	}else{
		printf("\nLa division de los numeros es: ");
		c = divZp(a, b);
		escZp(c);	
	}
		
	
	return 0;
}