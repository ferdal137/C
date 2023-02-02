#include <stdio.h>   
#include <stdlib.h>   
#include <math.h>

#include "polisl.h"

//Coeficientes

Coeficiente opera(Coeficiente A, Coeficiente B, void *operacion,  enum tipoCoeficiente tipo){
  zp (*fzp)(zp, zp);
  Q (*fQ)(Q, Q);
  C (*fC)(C, C);
	GR (*fGR)(GR, GR);
	G (*fG)(G, G);
	H (*fH)(H, H);
  Coeficiente ret;

  switch (tipo) {
  case 0:
    fzp = operacion; 
    ret.a = fzp(A.a, B.a);
    break;
  case 1:
    fQ = operacion;
    ret.b = fQ(A.b, B.b);
    break;
  case 2: fG=operacion;
		ret.c = fG(A.c, B.c);
	  break;	
	case 3: fC=operacion;
		ret.d = fC(A.d ,B.d);
	  break;	
	case 4: fGR=operacion;
		ret.e = fGR(A.e,B.e);
    break;	
	case 5: fH=operacion;
    ret.f = fH(A.f,B.f);
	  break;	

  default:
    printf("Dato invalido");
}
  return ret;
}

int esccoef(Coeficiente A, enum tipoCoeficiente tipo,FILE *archivo) {

  switch (tipo) {
  case 0: escribezp(A.a,archivo); break;
  case 1:
    escribeQ(A.b,archivo);
    break;
  case 2: 
    escribeG(A.c,archivo); 	
    break;
  case 3: 
    escribeC(A.d,archivo); 	
    break;
  case 4: 
    escribeGR(A.e,archivo);	
    break;
  case 5: 
    escribeH(A.f,archivo);	
    break;
  default:
    printf("tipo de dato invalido.");
  }
  return 0;
}

Coeficiente leecoef(int p, enum tipoCoeficiente tipo,FILE *archivo) {
  Coeficiente ret;

  switch (tipo) {
  case 0:
    ret.a = leerzp(p, archivo);
    break;
  case 1:
    ret.b = leerQ(archivo);
    break;
  case 2:
    ret.c = leerG(archivo);	
    break;
	case 3:	
    ret.d = leerC(archivo);	
    break;
	case 4:	
    ret.e = leerGR(archivo);	
    break;
	case 5:	
    ret.f = leerH(archivo);	
    break;
	default: printf("tipo de dato invalido...\n");
  }
  return ret;
}

int leerTipo(FILE *archivo) {

  int tipo;
  fscanf(archivo,"%d", &tipo);

  return tipo;
}

int dacero(Coeficiente a, enum tipoCoeficiente tipo) {
  int x;
  switch (tipo) {
  case 0:
    if (a.a.a == 0) 
      x = 0;
    else 
      x = 1;
    break;
  case 1:
    if (a.b.p == 0) x = 0;
    else x = 1;
    break;
  case 2: 
    if(a.c.Im == 0 && a.c.Re == 0) x = 0;
		else x = 1;
		break;
  case 3:
    if(a.d.Im == 0.0 && a.d.Re == 0.0) x = 0;
		else x = 1;
		break;
  case 4:
    if(a.e.Im.p == 0 && a.e.Re.p == 0) x = 0;
		else x = 1;
		break;
  case 5:
    if(a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0 && a.f.Re == 0.0) x = 0;
		else x = 1;
		break;
    default: printf("Dato invalido");
  }
  return x;
}

Coeficiente negativo(Coeficiente ret, enum tipoCoeficiente tipo) {
  zp p;
  p = ret.a;
  Coeficiente sort;
  switch (tipo) {
  case 0:
    sort.a.a = -ret.a.a; //-ret.a.a;
    break;
  case 1:
    sort.b.p = -ret.b.p;
    break;
  case 2:
    sort.c.Re=-ret.c.Re;
    sort.c.Im=-ret.c.Im;
    break;
  case 3: 
    sort.d.Re=-ret.d.Re;
    sort.d.Im=-ret.d.Im;
    break;
  case 4:
    sort.e.Re.p=-ret.e.Re.p;
    sort.e.Im.p=-ret.e.Im.p;
    break;
  case 5:
    sort.f.Re = -ret.f.Re;
		sort.f.Imi = -ret.f.Imi;
		sort.f.Imj = -ret.f.Imj;
		sort.f.Imk = -ret.f.Imk;
		break;
  default: printf("tipo de dato invalido...\n");
  }
  return sort;
}

int dauno(Coeficiente a, int tipo){
  	int sort;
	
	switch(tipo){
		case 0:
			if(a.a.a == 1) sort = 1;
			else if(a.a.a == -1) sort = -1;
			else sort = 3;
			break;
		case 1:
			if(a.b.p == 1 && a.b.q == 1) sort = 1;
			else if(a.b.p == -1 && a.b.q == 1) sort = -1;
			else sort = 3;
			break;
		case 2:
			if(a.c.Re == 1 && a.c.Im == 0) sort = 1;
			else if(a.c.Re == -1.0 && a.c.Im == 0) sort = -1;
			else sort = 8;
			break;
		case 3:
			if(a.d.Re == 1.0 && a.d.Im == 0.0) sort = 1;
			else if(a.d.Re == -1.0 && a.d.Im == 0.0) sort = -1;
			else sort = 11;
			break;
		case 4:
			if(a.e.Im.p == 0 && a.e.Re.p == 1 && a.e.Re.q == 1) sort = 1;
			else if(a.e.Im.p == 0 && a.e.Re.p == -1 && a.e.Re.q == 1) sort = -1;
			else sort = 13;
			break;
		case 5:
			if(a.f.Re == 1.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0) sort = 1;
			else if(a.f.Re == -1.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0) sort = -1;
			else sort = 19;
			break;
	}
	return sort;
}

void Parentesis(int tipo, int posicion,FILE *archivo){
  if(tipo == 0){
		return;
	}
	else{
		fprintf(archivo,"%s", posicion==0?"(":")");
	}	
	return;
}

int regresauno(Coeficiente a, int tipo){
	int sort;
	
	switch(tipo){
		case 0:
			if(a.a.a != 0) sort = 1;
			else sort = 23;
			break;
		case 1:
			if(a.b.p != 0) sort = 1;
			else sort = 3;
			break;
		case 2:
			if(a.c.Re == 0 && a.c.Im != 0) sort = 1;
			else if(a.c.Re != 0 && a.c.Im == 0) sort = 1;
			else sort = 29;
			break;
		case 3:
			if(a.d.Re == 0.0 && a.d.Im != 0.0) sort = 1;
			else if(a.d.Re != 0.0 && a.d.Im == 0.0) sort = 1;
			else sort = 13;
			break;
		case 4:
			if(a.e.Re.p == 0 && a.e.Im.p != 0.0) sort = 1;
			else if(a.e.Re.p != 0 && a.e.Im.p == 0.0) sort = 1;
			else sort = 5;
			break;
		case 5:
			if(a.f.Re == 0.0 && a.f.Imi != 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0) sort = 1;
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imj != 0.0 && a.f.Imk == 0.0) sort = 1;
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk != 0.0) sort = 1;
			else if(a.f.Re != 0.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0) sort = 1;
			else sort = 11;
			break;
	}
	return sort;
}

int signo(Coeficiente a, int tipo){
  	int sort;
	
	switch(tipo){
		case 0:
			if(a.a.a > 0) sort = 1;
			else sort = -1;
			break;
		case 1:
			if(a.b.p >0) sort = 1;
			else sort = -1;
			break;
		case 2:
			if(a.c.Im == 0 && a.c.Re > 0) sort = 1;
			else if(a.c.Im == 0 && a.c.Re < 0) sort = -1; 		
			else if(a.c.Re == 0 && a.c.Im > 0) sort = 1;
			else if(a.c.Re == 0 && a.c.Im < 0) sort = -1;		
			break;
		case 3:
			if(a.d.Im == 0.0 && a.d.Re > 0.0) sort = 1;
			else if(a.d.Im == 0.0 && a.d.Re < 0.0) sort = -1;	
			else if(a.d.Re == 0.0 && a.d.Im > 0.0) sort = 1;
			else if(a.d.Re == 0.0 && a.d.Im < 0.0) sort = -1;	
			break;
		case 4:
			if(a.e.Im.p == 0 && a.e.Re.p > 0) sort = 1;
			else if(a.e.Im.p == 0 && a.e.Re.p < 0) sort = -1; 	
			else if(a.e.Re.p == 0 && a.e.Im.p > 0) sort = 1;	
			else if(a.e.Re.p == 0 && a.e.Im.p < 0) sort = -1;	
			break;
		case 5:
			if(a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk== 0.0 && a.f.Re > 0.0) sort = 1;
			else if(a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk== 0.0 && a.f.Re < 0.0) sort = -1;	
			else if(a.f.Re == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0 && a.f.Imi > 0.0) sort = 1;
			else if(a.f.Re == 0.0 && a.f.Imj == 0.0 && a.f.Imk == 0.0 && a.f.Imi < 0.0) sort = -1;	
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imk == 0.0 && a.f.Imj > 0.0) sort = 1;
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imk == 0.0 && a.f.Imj < 0.0) sort = -1;	
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk > 0.0) sort = 1;
			else if(a.f.Re == 0.0 && a.f.Imi == 0.0 && a.f.Imj == 0.0 && a.f.Imk < 0.0) sort = -1; 
			break;
	}
	return sort;
}

Coeficiente givecero(enum tipoCoeficiente tipo, int p){
Coeficiente ret;
  switch (tipo) {
  case 0:
    ret.a.a = 0;
    ret.a.p = p;
    break;
  case 1:
    ret.b.p = 0;
    ret.b.q = 1;
    break;
  case 2:
    ret.c.Re=0;
    ret.c.Im=0;
    break;
  case 3:
    ret.d.Re=0;
    ret.d.Im=0;
    break;
  case 4: 
    ret.e.Re.p=0;
    ret.e.Re.q=1;
    ret.e.Im.p=0;
    ret.e.Im.q=1;
    break;
  case 5:
    ret.f.Re=0;
    ret.f.Imi=0;
    ret.f.Imj=0;
    ret.f.Imk=0;
    break;
  default: printf("Dato invalido");
  }
  return ret;
}

//Complejos

C sumaC(C X, C Y){ 		
	C Z;
  
	Z.Re = X.Re + Y.Re; 
	Z.Im = X.Im + Y.Im;
	return Z;
}

C restaC(C X, C Y){			
	C Z;
  
	Z.Re = X.Re - Y.Re; 
	Z.Im = X.Im - Y.Im;
	return Z;
}

C prodC(C X, C Y){			
	C Z;
  
	Z.Re = X.Re*Y.Re - X.Im*Y.Im; 
	Z.Im = X.Re*Y.Im + Y.Re*X.Im;
	return Z;
}

void escribeC(C X,FILE *archivo){
	
	if(X.Re==0){
		if(X.Im==1 || X.Im==-1){
			fprintf(archivo,"%si", X.Im==1?"":" ");
		}
		else{
			if(X.Im==0){
				fprintf(archivo,"0");
			}else{
				fprintf(archivo,"%lgi", X.Im);
			}
		}
	}else{
		fprintf(archivo,"%lg",X.Re);
		if(X.Im != 0){
			if(X.Im==1 || X.Im==-1){
				fprintf(archivo,"%si", X.Im==1?"+":"-");
			}else{
				fprintf(archivo,"%s%lgi", X.Im>0?"+":" ", X.Im);	
			}
		}
	}
		return;	
}

C leerC(FILE *archivo){
	C Z;

	fscanf(archivo,"%lg", &Z.Re);
	fscanf(archivo, "%lg", &Z.Im);
	return Z;	
}

C divC(C X, C Y){
	C ret;
	ret.Re = ((X.Re* Y.Re) + (X.Im*Y.Im))/((Y.Re*Y.Re) + (Y.Im*Y.Im));
	ret.Im = ((X.Im* Y.Re) - (X.Re*Y.Im))/((Y.Re*Y.Re) + (Y.Im*Y.Im));
	return  ret;
}

//Gaussianos

G sumaG(G X, G Y){ 			
	G Z;
  
	Z.Re = X.Re + Y.Re; 
	Z.Im = X.Im + Y.Im;
	return Z;
}

G restaG(G X, G Y){			
	G Z;
  
	Z.Re = X.Re - Y.Re; 
	Z.Im = X.Im - Y.Im;
	return Z;
}

G prodG(G X, G Y){			
	G Z;
  
	Z.Re = X.Re*Y.Re - X.Im*Y.Im; 
	Z.Im = X.Re*Y.Im + Y.Re*X.Im;
	return Z;
}

G leerG(FILE *archivo){
	G Z;

	fscanf(archivo,"%d", &Z.Re);
	fscanf(archivo,"%d", &Z.Im);
	return Z;	
}

G divG(G X, G Y){
	G ret;
	ret = X;
	printf("Aun no se define bien");
	return  ret;
}

void escribeG(G X,FILE *archivo){

	if(X.Re==0){
		if(X.Im==1 || X.Im==-1){
			fprintf(archivo,"%si", X.Im==1?" ":"-");
		}
		else{
			if(X.Im==0){
				fprintf(archivo,"0");
			}else{
				fprintf(archivo,"%di", X.Im);
			}
		}
	}else{
		fprintf(archivo,"%d",X.Re);
		if(X.Im != 0){
			if(X.Im==1 || X.Im==-1){
				fprintf(archivo,"%si", X.Im==1?"+":"- ");
			}else{
				fprintf(archivo,"%s%di", X.Im>0?"+":" ", X.Im);	
			}
		}
	}
		return;	
}

//Gaussianos Racionales

GR leerGR(FILE *archivo){
	GR Z;
	
	Z.Re = leerQG(archivo);
	Z.Im = leerQG(archivo);
	return Z;
}

Q leerQG(FILE *archivo){
	Q r;

	fscanf(archivo,"%d%d", &r.p,&r.q);
	while(r.q==0){
		fscanf(archivo,"%d",&r.q);
	}
	
	r=simplificaQ(r);
	return r;
}

GR sumaGR(GR X, GR Y){ 			
	GR Z;
  
	Z.Re = sumaQ(X.Re, Y.Re);
	Z.Im = sumaQ(X.Im, Y.Im);
	return Z;
}

GR restaGR(GR X, GR Y){
	GR Z;
  
	Z.Re = restaQ(X.Re, Y.Re); 
	Z.Im = restaQ(X.Im, Y.Im); 
	return Z;
}

GR prodGR(GR X, GR Y){			
	GR Z;
  
	Z.Re = restaQ(prodQ(X.Re, Y.Re), prodQ(X.Im, Y.Im)); 
	Z.Im = sumaQ(prodQ(X.Re, Y.Im), prodQ(X.Im, Y.Re)); 
	return Z;
}

GR divGR(GR X, GR Y){
	GR ret;
	
	ret.Re = divQ( sumaQ(prodQ(X.Re, Y.Re), prodQ(X.Im, Y.Im)), sumaQ(prodQ(Y.Re, Y.Re), prodQ(Y.Im,Y.Im)));
	ret.Im = divQ(restaQ(prodQ(X.Im, Y.Re), prodQ(X.Re, Y.Im)), sumaQ(prodQ(Y.Re, Y.Re), prodQ(Y.Im, Y.Im)));
	return  ret;
}

void escribeGR(GR X,FILE *archivo){
	Q unit, nunit;
	unit.p = 1;
	unit.q = 1;
	nunit.p = -1;
	nunit.q = 1;
	
	if(X.Re.p != 0){
	
		if(X.Im.p == 0.0){
			escribeQ(X.Re,archivo);
			return;
		}
		else if(X.Im.p == 1 && X.Im.q == 1){
			escribeQ(X.Re,archivo);
			fprintf(archivo,"+i");
			return;
		}
		else if(X.Im.p == -1 && X.Im.q == 1){
			escribeQ(X.Re,archivo);
			fprintf(archivo,"-i");
			return;
		}
		escribeQ(X.Re,archivo);
		fprintf(archivo,"%s", X.Im.p > 0?"+":"");
		escribeQ(X.Im,archivo);
		fprintf(archivo,"i");
		return;
	}
	
	if(X.Im.p == 0){
		fprintf(archivo,"0");
		return;
	}
	else if(X.Im.p == 1 && X.Im.q == 1){
		fprintf(archivo,"i");
		return;
	}
	else if(X.Im.p == -1 && X.Im.q == 1){
		fprintf(archivo,"-i");
		return;
	}
	escribeQ(X.Im,archivo);
	fprintf(archivo,"i");
	return;	
}

//Racionales

int mcd(int a, int b){                    
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

Q simplificaQ(Q a){                     
	int d;
	Q regreso;

	regreso = a;
	d = mcd (a.p, a.q);
	if(d>1){            
    	regreso.p /= d;         
    	regreso.q /= d;         
	}                    
	if(regreso.q < 0){       
		regreso.p *= -1;        
    	regreso.q *= -1;        
	}
	return regreso;
}

Q sumaQ(Q a, Q b){                
	Q r;           
	
	r.p = a.p*b.q + a.q*b.p;
	r.q = a.q*b.q;
	r=simplificaQ(r);
	return r;
}

void escribeQ(Q a,FILE *archivo){
	
	if(a.q == 0)
		fprintf(archivo,"No existe un valor para esto.\n");
	else{
		fprintf(archivo,"%d", a.p);
		if (a.q!= 1) fprintf(archivo,"/%d", a.q);
	}
}

Q creaQ(int num, int den){
	Q r = {num, den};
	
	r=simplificaQ(r);
	return r;
}

Q prodQ(Q a, Q b){
	Q r;
	
	r.p=a.p*b.p;
	r.q=a.q*b.q;
	r=simplificaQ(r);
	return r;
}

Q divQ(Q a, Q b){
	Q r;
	
	r.p=a.p*b.q;
	r.q=a.q*b.p;
	r=simplificaQ(r);
	return r;
}

Q restaQ(Q a, Q b){
	Q r;           

	r.p = a.p*b.q - a.q*b.p;
	r.q = a.q*b.q;
	r=simplificaQ(r);
	return r;
}

Q leerQ(FILE *archivo){
	Q r;

	fscanf(archivo,"%d%d", &r.p,&r.q);
	while(r.q==0){
		fscanf(archivo,"%d",&r.q);
	}
	
	r=simplificaQ(r);
	return r;
}

//Zp

zp sumazp(zp a, zp b){
	zp c;	
	c.p = a.p; 
	c.a = a.a + b.a;
	c.a%=c.p;
	
	return c;
}

zp restazp(zp a, zp b){
	zp c;	
	c.p = a.p; 
	c.a = a.a - b.a;
	c.a=(c.a%c.p + c.p)%c.p;
	
	return c;	
}

zp prodzp(zp a, zp b){
	zp c;	
	c.p = a.p; 
	c.a = a.a*b.a;
	c.a%=c.p;
	
	return c;
}

zp invzp(zp x){
	int s0, a, b, r, s_1, q, s;
	a = x.a;
	b = x.p;
	
	s0=0;
    s_1=1;
    while((r=a%b)!=0){
    q = a/b;
    a=b;
	b=r;
	s=s0;
	s0=s_1-q*s0;
	s_1=s;
	}
	x.a=(s0%x.p + x.p)%x.p;
	return x;
}

zp divzp(zp a, zp b){
	zp c;
	c=invzp(b);
	c=prodzp(c, a);
	return c;	
}

zp leerzp(int p,FILE *archivo){
	zp c;
	c.p=p;
	fscanf(archivo,"%d", &c.a);
	c.a=(c.a%c.p + c.p)%c.p;
	
	return c;
}

int escribezp(zp a,FILE *archivo){	
	fprintf(archivo,"%d", a.a);
	return 0;
}
zp neg(zp n) {
  zp c;
  int p;
  n.p = c.p;

  c.a = -n.a;
  return c;
}

//Cuaterniones

H leerH(FILE *archivo){
	H Z;
		
	fscanf(archivo,"%lg", &(Z.Re));
	fscanf(archivo,"%lg", &(Z.Imi));
	fscanf(archivo,"%lg", &(Z.Imj));
	fscanf(archivo,"%lg", &(Z.Imk));
	return Z;
}

H sumaH(H X, H Y){
	H Z;

	Z.Re =	X.Re + Y.Re;
	Z.Imi =	X.Imi + Y.Imi;
	Z.Imj = X.Imj + Y.Imj;
	Z.Imk = X.Imk + Y.Imk;
	return Z;	
}

H restaH(H X, H Y){
	H Z;

	Z.Re =	X.Re - Y.Re;
	Z.Imi =	X.Imi - Y.Imi;
	Z.Imj = X.Imj - Y.Imj;
	Z.Imk = X.Imk - Y.Imk;
	return Z;	
}

H prodH(H X, H Y){
  H ret={
    X.Re*Y.Re - X.Imi*Y.Imi - X.Imj*Y.Imj - X.Imk*Y.Imk,
    X.Re*Y.Imi + X.Imi*Y.Re + X.Imj*Y.Imk - X.Imk*Y.Imj,
    X.Re*Y.Imj - X.Imi*Y.Imk + X.Imj*Y.Re + X.Imk*Y.Imi,
    X.Re*Y.Imk + X.Imi*Y.Imj - X.Imj*Y.Imi + X.Imk*Y.Re
  };

  if (-EPSILON <= ret.Re && ret.Re <= EPSILON) ret.Re = 0.0;
  if (-EPSILON <= ret.Imi && ret.Imi <= EPSILON) ret.Imi = 0.0;
  if (-EPSILON <= ret.Imj && ret.Imj <= EPSILON) ret.Imj = 0.0;
  if (-EPSILON <= ret.Imk && ret.Imk <= EPSILON) ret.Imk = 0.0;

  return ret;
}

H divH(H X, H Y){
return prodH(X, invH(Y));
} 

H invH(H h){
  double norma2=h.Re*h.Re+h.Imi*h.Imi+h.Imj*h.Imj+h.Imk*h.Imk;
  H ret={h.Re, -h.Imi, -h.Imj, -h.Imk};

  if (norma2==0.0) return h;
  ret.Re/=norma2;
  ret.Imi/=norma2;
  ret.Imj/=norma2;
  ret.Imk/=norma2;

  if (-EPSILON <= ret.Re && ret.Re <= EPSILON) ret.Re = 0.0;
  if (-EPSILON <= ret.Imi && ret.Imi <= EPSILON) ret.Imi = 0.0;
  if (-EPSILON <= ret.Imj && ret.Imj <= EPSILON) ret.Imj = 0.0;
  if (-EPSILON <= ret.Imk && ret.Imk <= EPSILON) ret.Imk = 0.0;

  return ret;
}

int escAuxH(double r, char h, char s,FILE *archivo)
{
  if (r != 0.0) {
    if (r != 1.0 && r != -1.0) 
	  if(s) fprintf(archivo,"%+lg", r);
	  else fprintf(archivo,"%lg", r);
	else fprintf(archivo,"%s", s?(r>0.0?"+":"-"):(r<0.0?"-":""));
    fprintf(archivo,"%c", h);
  }
  return 0;
}

int escribeH(H Z,FILE *archivo)
{
  char s=0;
  if (Z.Re == 0.0 && Z.Imi == 0.0 && Z.Imj == 0.0 && Z.Imk == 0.0){
    fprintf(archivo,"0");
    return 0;
  }
  if (Z.Re != 0.0){fprintf(archivo,"%lg ", Z.Re); s=1;
  } 
  if (Z.Imi != 0.0){escAuxH(Z.Imi, 'i', s,archivo); s=1;
  } 
  if (Z.Imj != 0.0){escAuxH(Z.Imj, 'j', s,archivo); s=1;
  } 
  if (Z.Imk != 0.0){escAuxH(Z.Imk, 'k', s,archivo); s=1;
  } 
  return 0;
}

//Polinomios

Rx leeP(int p, enum tipoCoeficiente tipo,FILE *archivo) {
  Rx ret;
  int i;
  Coeficiente A;

  fscanf(archivo,"%d", &(ret.g));

  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i = 0; i <= ret.g; i++) {
    //printf("digite el coeficiente del monomio x^%d:", i);
    A = leecoef(p, tipo,archivo);
    ret.c[i] = A;
  }
  while(ret.g>=0 && dacero(ret.c[ret.g], tipo) == 0) ret.g--; 			
  
	if (ret.g<0){											
    	free(ret.c);
    	ret.c = NULL;
	}
  return ret;
}

int escP(Rx p, enum tipoCoeficiente tipo,FILE *archivo) {
  int i;
  
  if (tipo==0 ||tipo==1 || tipo==3 || tipo == 4 || tipo==5 ||tipo==2 ){
    if(p.g<0){											
		fprintf(archivo,"0");
		return 0;	
	}
	if(p.g == 0){											
		esccoef(p.c[0], tipo,archivo);
		return 0;
	}
	if (p.g>1){										
		if(dauno(p.c[p.g], tipo) == 1 || dauno(p.c[p.g], tipo) == -1){
			fprintf(archivo,"%sx^%d", dauno(p.c[p.g], tipo)>0?"":"-", p.g);
		}		
		else{
			if(regresauno(p.c[p.g], tipo)==1){
				esccoef(p.c[p.g], tipo,archivo);
				fprintf(archivo,"x^%d", p.g);
			}
			else{
				Parentesis(tipo, 0,archivo);
				esccoef(p.c[p.g], tipo,archivo);				
				Parentesis(tipo, 1,archivo);
				fprintf(archivo,"x^%d", p.g);
			}	
		}
	}
	for(i=p.g-1; i>1; i--){									
    	if (dacero(p.c[i], tipo) != 0){
    		if(dauno(p.c[i], tipo) == 1 || dauno(p.c[i], tipo) == -1){
    			fprintf(archivo,"%sx^%d", signo(p.c[i], tipo)>0?"+":"-", i); 
			}
			else{														
				if(regresauno(p.c[i], tipo) == 1){
					fprintf(archivo,"%s", signo(p.c[i], tipo) == 1.0?"+":"");	
					esccoef(p.c[i], tipo,archivo);
					fprintf(archivo,"x^%d", i);
				}
				else{
					fprintf(archivo,"+");											
					Parentesis(tipo, 0,archivo);
					esccoef(p.c[i], tipo,archivo);
					Parentesis(tipo, 1,archivo);
					fprintf(archivo,"x^%d", i);		
				}
			}
		}
	}
	if(p.g>1 && dacero(p.c[1], tipo) != 0){								
		if(dauno(p.c[1], tipo) == 1 || dauno(p.c[1], tipo) == -1){
			fprintf(archivo,"%sx ", signo(p.c[1], tipo)>0?"+":"-");
		}
		else{
			if(regresauno(p.c[1], tipo) == 1){
				fprintf(archivo,"%s", signo(p.c[1], tipo) == 1.0?"+":"");
				esccoef(p.c[1], tipo,archivo);
				fprintf(archivo,"x");
			}
			else{
				fprintf(archivo,"+");											
				Parentesis(tipo, 0,archivo);
				esccoef(p.c[1], tipo,archivo);
				Parentesis(tipo, 1,archivo);
				fprintf(archivo,"x");	
			}
		}
	}
	else if(p.g==1 && dacero(p.c[1], tipo) != 0){ 	
		if(dauno(p.c[1], tipo) == 1 || dauno(p.c[1], tipo) == -1){
			fprintf(archivo,"%sx", signo(p.c[1], tipo)>0?"":"-");
		}
		else{
			if(regresauno(p.c[1], tipo)==1){
				esccoef(p.c[1], tipo,archivo);
				fprintf(archivo,"x");
			}
			else{
				Parentesis(tipo, 0,archivo);
				esccoef(p.c[1], tipo,archivo);
				Parentesis(tipo, 1,archivo);
				fprintf(archivo,"x");
			}
		}
	}
	
	if(dacero(p.c[0], tipo) != 0){				
		if(dauno(p.c[0], tipo) == 1 || dauno(p.c[0], tipo) == -1){
			fprintf(archivo,"%s", signo(p.c[0], tipo)>0?"+1":"-1");
		}
		else{
			if(regresauno(p.c[0], tipo)==1){
				fprintf(archivo,"%s", signo(p.c[0], tipo) == 1.0?"+":"");	
				esccoef(p.c[0], tipo,archivo);
			}
			else{
				fprintf(archivo,"+");
				Parentesis(tipo, 0,archivo);
				esccoef(p.c[0], tipo,archivo);
				Parentesis(tipo, 1,archivo);
			}
		}
	}
  } 
  return 0;
}

Rx ceroP(int grad, enum tipoCoeficiente tipo, int p){
  Rx sum;
  int i;
  sum.g=grad;
  if ((sum.c = (Coeficiente *)malloc((sum.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    sum.g = -1;
    return sum;
  }
  for (i=0;i<=sum.g;i++){
    sum.c[i]=givecero(tipo, p);
  }
  return sum;
}

Rx copiaP(Rx a) {
  Rx ret;
  int i;

  ret.g = a.g;
  if (ret.g < 0) {
    ret.c = NULL;
    return ret;
  }
  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for (i = 0; i <= ret.g; i++)
    ret.c[i] = a.c[i];

  return ret;
}

Rx suma(Rx a, Rx b, enum tipoCoeficiente tipo) {
  void *fs[] = {sumazp, sumaQ, sumaG, sumaC, sumaGR, sumaH};
  Rx ret;
  int i, min;

  if (a.g < 0) {
    return copiaP(b);
  }
  if (b.g < 0) {
    return copiaP(a);
  }
  if (a.g < b.g) {
    min = a.g;
    ret.g = b.g;
  } else {
    min = b.g;
    ret.g = a.g;
  }
  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i = 0; i <= min; i++)
    ret.c[i] = opera(a.c[i], b.c[i], fs[tipo], tipo);
  if (a.g == min) {
    for (; i <= ret.g; i++)
      ret.c[i] = b.c[i];
  }
  if (b.g == min) {
    for (; i <= ret.g; i++)
      ret.c[i] = a.c[i];
  }

  while (ret.g >= 0 && dacero(ret.c[ret.g], tipo) == 0)
    ret.g--;
  if (ret.g < 0) {
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx copiaMenosP(Rx a) {
  Rx ret;
  int i, tipo;

  ret.g = a.g;
  if (ret.g < 0) {
    ret.c = NULL;
    return ret;
  }
  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i = 0; i <= ret.g; i++)
    ret.c[i] = negativo(a.c[i], tipo);

  return ret;
}

int liberaP(Rx *a) {
  if (a->c != NULL)
    free(a->c);
  a->g = -1;
  a->c = NULL;
  return 0;
}

Rx rest(Rx a, Rx b, enum tipoCoeficiente tipo) {
  void *fr[] = {restazp, restaQ, restaG, restaC, restaGR, restaH};
  Rx ret;
  int i, min;

  if (a.g < 0) {
    return copiaMenosP(b);
  }
  if (b.g < 0) {
    return copiaP(a);
  }
  if (a.g < b.g) {
    min = a.g;
    ret.g = b.g;
  } else {
    min = b.g;
    ret.g = a.g;
  }
  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i = 0; i <= min; i++)
    ret.c[i] = opera(a.c[i], b.c[i], fr[tipo], tipo);
  if (a.g == min) {
    for (; i <= ret.g; i++)
      ret.c[i] = negativo(b.c[i], tipo);
  }
  if (b.g == min) {
    for (; i <= ret.g; i++)
      ret.c[i] = a.c[i];
  }
  while (ret.g >= 0 && dacero(ret.c[ret.g], tipo) == 0.0)
    ret.g--;
  if (ret.g < 0) {
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx mult(Rx a, Rx b, enum tipoCoeficiente tipo, int p) {
  int i, j;
  Rx ret;
  void *fp[] = {prodzp, prodQ, prodG, prodC, prodGR, prodH};
  void *fs[] = {sumazp, sumaQ, sumaG, sumaC, sumaGR, sumaH};

  ret.g = a.g + b.g;
  if ((ret.c = (Coeficiente *)malloc((ret.g + 1) * sizeof(Coeficiente))) ==
      NULL) {
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  } 
  for (i = 0; i <= ret.g; i++) {
      ret.c[i] = givecero(tipo,p);
  }

  for (i = 0; i <= a.g; i++) {
    for (j = 0; j <= b.g; j++) {
       ret.c[i+j]=opera(ret.c[i+j], opera(a.c[i], b.c[j], fp[tipo], tipo), fs[tipo], tipo);
    }
  }
  while (ret.g >= 0 && dacero(ret.c[ret.g], tipo) == 0.0)
    ret.g--;
  if (ret.g < 0) {
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx multMonomio(Rx a, Coeficiente c, int e, int tipo, int p)
{
  int i;
  Rx ret;
  void *fp[] = {prodzp, prodQ, prodG, prodC, prodGR, prodH};

  ret.g=a.g+e;
  if((ret.c=(Coeficiente*)malloc((ret.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for (i=0; i<=ret.g; i++) ret.c[i]=givecero(tipo,p);
  for (i=e; i<=ret.g; i++) ret.c[i]=opera(a.c[i-e],c, fp[tipo], tipo);
  
  while(ret.g>=0 && dacero(ret.c[ret.g], tipo)==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

int esCero(Rx a)
{
  return a.g <0;
}

Rx divR(Rx a, Rx b, Rx *r,  int tipo, int p)
{
  Rx q, aux, a_aux;
  double coef;
  int grad, i;
  void *fd[] = {divzp, divQ, divG, divC, divGR, divH};

  a_aux= copiaP(a);
  a=a_aux;

  if (a.g<b.g){
    q.g=-1;
    q.c=NULL;
    *r = copiaP(a);

    return q;
  }

  q.g=a.g-b.g;
  if((q.c=(Coeficiente*)malloc((q.g+1)*sizeof(Coeficiente)))==NULL){
    printf("error al generar espacio.\n");
    q.g = -1;
    return q;
  }
  
  for (i=0; i<=q.g; i++) q.c[i]=givecero(tipo,p);
  do{
    grad=a.g-b.g;
    q.c[grad] =opera(a.c[a.g],b.c[b.g],fd[tipo], tipo);

    aux = multMonomio(b, q.c[grad], grad,tipo,p);

    a_aux = rest(a, aux, tipo);

    liberaP(&a);
    liberaP(&aux);
    a = a_aux;
  liberaP(r);
    *r=copiaP(a);
  }while(!esCero(*r) && (r->g>=b.g));

  return q;
}

int TipoCoeficiente(FILE *f, int Tipo){
	switch (Tipo){
		case 0:
			fprintf(f, "El polinomio tiene coeficientes del tipo ZP.\n");
			break;
		case 1:
			fprintf(f, "El polinomio tiene coeficientes del tipo racionales.\n");
			break;
		case 2:
			fprintf(f, "El polinomio tiene coeficientes del tipo gaussianos.\n");
			break;
		case 3:
			fprintf(f, "El polinomio tiene coeficientes del tipo complejos.\n");
			break;
		case 4:
			fprintf(f, "El polinomio tiene coeficientes del tipo gaussianos racionales.\n");
			break;
		case 5:
			fprintf(f, "El polinomio tiene coeficientes del tipo cuaterniones.\n");
			break;
	}
}