#include <stdio.h>   
#include <stdlib.h>   
#include <math.h>

#include "sturml.h"

Rx leeP(FILE *f){
	Rx ret;
	int i;
	fscanf(f,"%d", &(ret.g));
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for(i=ret.g; i>=0; i--){
    	fscanf(f,"%lg", &(ret.c[i]));
	}
    while(ret.g>=0 && ret.c[ret.g]==0.0){
		ret.g--;
	}
	if(ret.g<0){
    	free(ret.c);
    	ret.c = NULL;
	}
  	return ret;
}
void escP(Rx a){
	int i;
	printf("   ");
	if(a.g>1){
		if((a.c[a.g]==1.0)||(a.c[a.g]==-1.0)){
			(a.c[a.g]==1.0)?(printf("x^%d", a.g)):(printf("-x^%d", a.g));
		}else{
			printf("%lgx^%d", a.c[a.g], a.g);
		}
		for(i=(a.g-1); i>1; i--){
			if(a.c[i]!=0.0){
				if((a.c[i]==1.0)||(a.c[i]==-1.0)){
					(a.c[i]==1.0)?(printf(" +x^%d", i)):(printf(" -x^%d", i));
				}else{
					printf(" %+lgx^%d", a.c[i], i);
				}
			}
		}
		if(a.c[1]!=0.0){
			if((a.c[1]==1.0)||(a.c[1]==-1.0)){
				(a.c[i]==1.0)?(printf(" +x")):(printf(" -x"));
			}else{
				printf(" %+lgx", a.c[1]);
			}
		}
		if(a.c[0]!=0.0){
			printf(" %+lg", a.c[0]);
		}
	}else if(a.g==1){
		if(a.c[1]!=0.0){
			if((a.c[1]==1.0)||(a.c[1]==-1.0)){
				(a.c[a.g]==1.0)?(printf("x")):(printf("-x"));
			}else{
				printf("%lgx", a.c[1]);
			}
		}
		if(a.c[0]!=0.0){
			printf(" %+lg", a.c[0]);
		}
	}else if(a.g==0){
		printf("%lg", a.c[0]);
	}else if(a.g<0){
		printf("0");
	}
}
double cota(Rx a){
	int i;
	double M;
	M=sqrt(a.c[0]*a.c[0]);
	for(i=1;i<=a.g-1;i++){
		if(sqrt(a.c[i-1]*a.c[i-1])<=sqrt(a.c[i]*a.c[i])){
			M=sqrt(a.c[i]*a.c[i]);
		}
	}
	M=(M/sqrt(a.c[a.g]*a.c[a.g]))+1.0;
	return M;
}
double potencia(double c, int n){
	double xn;
	int i;
	xn=c;
	if(n==1) xn=c;
	else{
		for(i=2;i<=n;i++){
			xn=xn*c;
		}
	}
	return xn;
}
double EvaluaP(Rx a, double c){
	int i;
	double ac;
	ac=a.c[0];
	for(i=1;i<=a.g;i++){
		ac+=a.c[i]*potencia(c,i);
	}
	if(ac<0.000000000001 && -0.000000000001<ac){
		ac=0.0;
	}
	return ac;
}
Rx derivada(Rx a){
	int i;
	Rx b;
	if(esCero(a)) b=a;
	else{
		b.g=(a.g)-1;
		if((b.c=(double*)malloc((b.g+1)*sizeof(double)))==NULL){
    		printf("Error al generar espacio.\n");
    		b.g = -1;
    		return b;
		}
		for(i=0;i<=b.g;i++){
			b.c[i]=(i+1.0)*a.c[i+1];
		}
	}
	return b;
}
Rx ResiduoSimple(Rx a, Rx b){
	Rx q,s={c:NULL, g:-1},r={c:NULL, g:-1};
	int i;
	q=divR(a,b,&r);
	s=rest(a,mult(b,q));
	for(i=0;i<=s.g;i++){
		if(s.c[i]<1e-10 && -1e-10<s.c[i]){
			s.c[i]=0.0;
		}
	}
	while(s.g>=0 && s.c[s.g]==0.0){
		s.g--;
	}
	liberaP(&r);
	return s;
}
Rx MCD(Rx a, Rx b){
	Rx s,p=a,q=b;
	int g,i;
	s=ResiduoSimple(p,q);
	g=s.g;
	if(g==-1){
		if(q.g!=-1){
			for(i=0;i<=q.g;i++){
				q.c[i]=q.c[i]/q.c[q.g];
			}
		}
	return copiaP(b);
	}else{
		while(g!=-1){
			p=q;
			q=s;
			s=ResiduoSimple(p,q);
			for(i=0;i<=s.g;i++){
				if(s.c[i]<1e-8 && -1e-8<s.c[i]){
					s.c[i]=0.0;
				}
			}
			while(s.g>=0 && s.c[s.g]==0.0){
				s.g--;
			}
			g=s.g;
 		}
	}
	if(q.g!=-1){
		for(i=0;i<=q.g;i++){
			q.c[i]=q.c[i]/q.c[q.g];
		}
	}
	return copiaP(q);
}
Rx suma(Rx a, Rx b){
	Rx ret;
	int i, min;
	if(a.g<0){
    	return copiaP(b);
	}
	if(b.g<0){
		return copiaP(a);
	}
	if(a.g<b.g){
    	min=a.g;
    	ret.g=b.g;
	}else{
    	min = b.g;
    	ret.g = a.g;
	}
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for(i=0; i<=min; i++){
		ret.c[i]=a.c[i]+b.c[i];
	}
	if(a.g==min){
    	for(i=min+1; i<=ret.g; i++){
			ret.c[i]=b.c[i];
		}
	}
	if(b.g==min){
    	for(i=min+1; i<=ret.g; i++){
			ret.c[i]=a.c[i];
		}
	}
	while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  	if(ret.g<0){
    	free(ret.c);
		ret.c = NULL;
	}
	return ret;
}
Rx rest(Rx a, Rx b){
	Rx ret;
	int i, min;
	if(a.g<0){
    	return copiaMenosP(b);
	}
	if(b.g<0){
		return copiaP(a);
	}
	if(a.g<b.g){
    	min = a.g;
    	ret.g = b.g;
	}else{
		min = b.g;
    	ret.g = a.g;
	}
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for(i=0; i<=min; i++){
		ret.c[i]=a.c[i]-b.c[i];
	}
	if(a.g==min){
		for (i=min+1; i<=ret.g; i++){
			ret.c[i]=-b.c[i];
		}
	}
	if(b.g==min){
		for(i=min+1; i<=ret.g; i++){
			ret.c[i]=a.c[i];
		}
	}
	while(ret.g>=0 && ret.c[ret.g]==0.0){
		ret.g--;
	}
	if(ret.g<0){
    	free(ret.c);
    	ret.c = NULL;
  	}
  	return ret;
}
Rx mult(Rx a, Rx b){
	int i, j;
	Rx ret;
	ret.g=a.g+b.g;
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
  	for(i=0; i<=ret.g; i++){
	  	ret.c[i]=0.0;
	}
	for(i=0; i<=a.g; i++){
	    for(j=0; j<=b.g; j++){
	    	ret.c[i+j]+=a.c[i]*b.c[j];
		}
	}
	return ret;
}
Rx multMonomio(Rx a, double c, int e){
	int i;
	Rx ret;
	ret.g=a.g+e;
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for (i=0; i<=ret.g; i++){
		ret.c[i]=0.0;
	}
	for (i=e; i<=ret.g; i++){
		ret.c[i]=a.c[i-e]*c;
	}
	return ret;
}
int esCero(Rx a){
  return a.g <0;
}
Rx divR(Rx a, Rx b, Rx *r){
	Rx q, aux, a_aux;
	double coef;
	int grad, i,j,k;
	a_aux= copiaP(a);
	a=a_aux;
	if(a.g<b.g){
		q.g=-1;
    	q.c=NULL;
    	*r=copiaP(a);
    	return q;
	}
	q.g=a.g-b.g;
	if((q.c=(double*)malloc((q.g+1)*sizeof(double)))==NULL){
		printf("Error al generar espacio.\n");
    	q.g = -1;
    	return q;
	}
	for(i=0; i<=q.g; i++){
		q.c[i]=0.0;
	}
	do{
		grad=a.g-b.g;
		q.c[grad] = a.c[a.g]/b.c[b.g];
    	aux = multMonomio(b, q.c[grad], grad);
		a_aux = rest(a, aux);
    	liberaP(&a);
    	liberaP(&aux);
    	a=a_aux;    
		for(k=0;k<=a.g;k++){
			if(a.c[k]<1e-8 && -1e-8<a.c[k]){
				a.c[k]=0.0;
			}
		}
		while(a.g>=0 && a.c[a.g]==0.0){
			a.g--;
		}
  		liberaP(r);
    	*r=copiaP(a);
	}while(!esCero(*r) && (r->g>=b.g));
	return q;
}
Rx copiaP(Rx a){
	Rx ret;
	int i;
	ret.g = a.g;
	if (ret.g<0){
    	ret.c=NULL;
    	return ret;
	}
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for(i=0; i<=ret.g; i++){
		ret.c[i]=a.c[i];
	}
	return ret;
}
Rx copiaMenosP(Rx a){
	Rx ret;
	int i;
	ret.g=a.g;
	if(ret.g<0){
		ret.c=NULL;
    	return ret;
	}
	if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    	printf("Error al generar espacio.\n");
    	ret.g = -1;
    	return ret;
	}
	for(i=0; i<=ret.g; i++){
		ret.c[i]=-a.c[i];
	}
	return ret;
}
int  liberaP(Rx *a) {
	if(a->c!=NULL){
		free(a->c);
	}
	a->g=-1;
	a->c=NULL;
	return 0;	
}

Inter separa(Rx p){
	int i,j,k,c,t;
	double del,M;
	Inter J={c:NULL, t:-1};
	Rx q;
	Orillas ex={e:NULL, k:-1};
	liberaInter(&J);
	q=copiaP(p);
	M=cota(q);
	t=XD(-M,M,q);
	J.t=2*t;
	if((J.c=(double*)malloc((J.t+1)*sizeof(double)))==NULL){
    printf("Error al generar espacio.\n");
    	J.t=-1;
		return J;
	}
	if(t==0){
		liberaInter(&J); 
		return J;
	}else{
		c=0;
		for(i=t;c<t;i++){
			c=0;
			del=2.0*M/(1.0*i);
			liberaOrillas(&ex);
			ex.k=1000;
			if((ex.e=(double*)malloc((ex.k+1)*sizeof(double)))==NULL){
				printf("Error al generar espacio.\n");
	    		ex.k = -1;
	    		return J;
			}
			ex.e[0]=-M;
			liberaInter(&J);
			J.t=2*t;
			if((J.c=(double*)malloc((J.t+1)*sizeof(double)))==NULL){
				printf("Error al generar espacio.\n");
    			J.t = -1;
    			return J;
			}
			for(j=1;j<=i;j++){
				ex.e[0]=-M;
				ex.e[j]=ex.e[0]+(j*del);
				if(XD(ex.e[j-1],ex.e[j],q)==1){
					c++;
					J.c[c-1]=ex.e[j-1];
					J.c[c+t-1]=ex.e[j];
				}
			}
		}
	}
	return J;
}

int variaciones(double a, Rx p){
	int v,i,j,k;
	Rx q;
	q=copiaP(p);
	PoliSturm StPa;
	StPa=sistemaSturm(q);
	if(q.g==0 || q.g==-1){
		v=0;
	}else{
		v=0;
		for(j=1;j<=StPa.h;j++) if(EvaluaP(StPa.p[j],a)==0.0){
		liberaP(&StPa.p[j]);
		StPa.p[j]=StPa.p[j-1];} 
		for(i=1;i<=StPa.h;i++){
			for(k=0;k<=StPa.p[i].g;k++){
				if(StPa.p[i].c[k]<0.000000001 && -0.000000001<StPa.p[i].c[k]){
					StPa.p[i].c[k]=0.0;
				}
			}
			if(0.0<=EvaluaP(StPa.p[i],a)*EvaluaP(StPa.p[i-1],a)){
				v=v;
			}else{
				v++;
			}
		}
	}
	liberaP(&q);
	return v;
}
PoliSturm sistemaSturm(Rx a){
	int i,j;
	PoliSturm StPa={p:NULL, h:-1};
	StPa.h=a.g;
	if((StPa.p=(Rx*)malloc((StPa.h+1)*sizeof(Rx)))==NULL){
    	printf("Error al generar espacio.\n");
    	StPa.h = -1;
    	return StPa;
	}
	StPa.p[0]=a;
	StPa.p[1]=derivada(a);
	for(i=2;i<=StPa.h;i++){
		StPa.p[i]=copiaMenosP(ResiduoSimple(StPa.p[i-2],StPa.p[i-1])); 
		for(j=0;j<=StPa.p[i].g;j++){
			if(StPa.p[i].c[j]<0.00000001 && -0.00000001<StPa.p[i].c[j]){
				StPa.p[i].c[j]=0.0;
			}
		}
		while(StPa.p[i].g>=0 && StPa.p[i].c[StPa.p[i].g]==0.0){
			StPa.p[i].g--;	
		}
	}
	return StPa;
	liberaPoliSturm(&StPa);
}
int escribeSturm(Rx a){
	int i;
	PoliSturm Ssa;
	Ssa=sistemaSturm(a);
	for(i=0;i<=Ssa.h;i++){
		printf("\n\t\t");
		escP(Ssa.p[i]);
		printf("\n\t\t");
	}
	return 0;
}
void liberaPoliSturm(PoliSturm *a) {
	if(a->p!=NULL){
		free(a->p);
	}
	a->h=-1;
	a->p=NULL;
}
void  liberaInter(Inter *a) {
	if(a->c!=NULL){
		free(a->c);
	}
	a->t=1000;
	a->c=NULL;
}
void  liberaOrillas(Orillas *a) {
	if(a->e!=NULL){
		free(a->e);
	}
	a->k=1000;
	a->e=NULL;	
}
void  escribeSepa(FILE *f, Inter J){
	int i,t=J.t/2;
	if(t!=1){
		fprintf(f, "\nEl polinomio cuenta con %d raices reales: ", t);
	}else{
		fprintf(f, "\nEl polinomio cuenta con una raiz real: ");
	}
	for(i=0;i<t;i++){
		fprintf(f,"\n\t(%lg, %lg)",J.c[i],J.c[i+t]);
	}
}
void escribeD(FILE *f, Inter J){
	int i,t=J.t/2;
	fprintf(f, "%d", t);
	for(i=0;i<t;i++){
		fprintf(f,"\n%lg %lg",J.c[i],J.c[i+t]);
	}
}
void escArchP(FILE *f, Rx a){
	int i;
	fprintf(f, "   ");
	if(a.g>1){
		if((a.c[a.g]==1.0)||(a.c[a.g]==-1.0)){
			(a.c[a.g]==1.0)?(fprintf(f, "x^%d", a.g)):(fprintf(f, "-x^%d", a.g));
		}else{
			fprintf(f, "%lgx^%d", a.c[a.g], a.g);
		}
		for(i=(a.g-1); i>1; i--){
			if(a.c[i]!=0.0){
				if((a.c[i]==1.0)||(a.c[i]==-1.0)){
					(a.c[i]==1.0)?(fprintf(f, " +x^%d", i)):(fprintf(f, " -x^%d", i));
				}else{
					fprintf(f, " %+lgx^%d", a.c[i], i);
				}
			}
		}
		if(a.c[1]!=0.0){
			if((a.c[1]==1.0)||(a.c[1]==-1.0)){
				(a.c[i]==1.0)?(fprintf(f, " +x")):(fprintf(f, " -x"));
			}else{
				fprintf(f, " %+lgx", a.c[1]);
			}
		}
		if(a.c[0]!=0.0){
			fprintf(f, " %+lg", a.c[0]);
		}
	}else if(a.g==1){
		if(a.c[1]!=0.0){
			if((a.c[1]==1.0)||(a.c[1]==-1.0)){
				(a.c[a.g]==1.0)?(fprintf(f, "x")):(fprintf(f, "-x"));
			}else{
				fprintf(f, "%lgx", a.c[1]);
			}
		}
		if(a.c[0]!=0.0){
			fprintf(f, " %+lg", a.c[0]);
		}
	}else if(a.g==0){
		fprintf(f, "%lg", a.c[0]);
	}else if(a.g<0){
		fprintf(f, "0");
	}
}
void Sturm(FILE *ent, FILE *sal, FILE *SalDos){
	Rx a, b, d,s, r={c:NULL, g:-1};
	PoliSturm StPa;
	Inter B={c:NULL, t:-1};
	int i;
	a=leeP(ent);
	fprintf(sal, "f(x)=");
	escArchP(sal, a);
	printf("\nHas elegido el polinomio:\n\tf(x)=");
	escP(a);
	if(a.g>0){
		b=derivada(a);
		d=divR(a,MCD(a,b),&r);
		if(XD(-cota(d),cota(d),d)==0){
			fprintf(sal,"\nEl polinomio no tiene raices reales");
		}else{
			B=separa(d);
			escribeSepa(sal, B);
		}
		liberaP(&b);
		liberaP(&d);
		liberaP(&r);
	}else if(a.g==0){
		fprintf(sal, "\nEl polinomio no cuenta con raices");
	}else if(a.g<0){
		fprintf(sal, "\nLas raices del polinomio son todos los numeros reales");
	}
	escribeD(SalDos, B);
	liberaInter(&B);
	printf("\n\nSe han escrito los datos\n\n\n\t\t\t\tFIN DE LA TRANSMISION ...\n");
	printf("\nBuena referencia a Los chicos del barrio");
	liberaP(&a);
}

int XD(double a, double b, Rx p){
	int w;
	w=variaciones(a,p)-variaciones(b,p);
	if(EvaluaP(p,b)==0){
		w--;
	}
	return w;
}