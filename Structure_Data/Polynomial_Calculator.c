#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct _P_{
	int n;
	double c[MAX];
}P;

int main(){
	
	P A, B, C;
	double x, y;
	printf("\nEste programa es calculadora de polinomios");
	printf("\nEscribe el grado del primer polinomio");
	scanf("%d",&A.n);
	for(i=A.n;i>=0;i--){
		printf("\nDigite el coeficiente del polinomio");
		scanf("%d",&A.c[i]);
	}
	printf("\nEscribe el grado del segundo polinomio");
	scanf("%d",&B.n);
	for(i=A;i>=0;i--){
		printf("\nDigite el coeficiente del polinomio");
		scanf("%d",&B.c[i]);
	}
	if(A.n>=B.n){
		C.n = A.n;
		min = B.n;
	}else{
		C.n = B.n;
		min = A.n;
	}
	for(i=0;i<=min;i++) C.c[i]=B.c[i]+A.c[i];
	if(min==B.n)for(;i<=C.n;i++) C.c[i]=A.c[i];
	if(min==A.n)for(;i<=C.n;i++) C.c[i]=B.c[i];
	while(C.n>=0&&C.c[C.n]==0.0) C.n--;
	printf("\nLa suma es: \nt");
	if(C.c[C.n]==1.0||C.c[C.n]==-1.0) printf("%cx^%d",C.c[C.n]==1.0?"":"-",C.n);
	else printf("%lgx^%d",C.c[C.n],C.n);
	for(i=C.n-1;i>1;i--){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx^%d",C.c[i]==1.0?"+":"-",i);
		else printf("%lgx^%d",C.c[i],i);
	}
	if(C.c[i]!=0.0){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx",C.c[i]c==1.0?"+":"-");
		else printf("%+lgx",C.c[i]);
		C.c[0]==0?printf("%+lg",C.c[0]);
	}
	
	//Resta
	
	for(i=0;i<=min;i++) C.c[i]=B.c[i]-A.c[i];
	if(min==B.n)for(;i<=C.n;i++) C.c[i]=A.c[i];
	if(min==A.n)for(;i<=C.n;i++) C.c[i]=B.c[i];
	while(C.n>=0&&C.c[C.n]==0.0) C.n--;
	printf("\nLa resta es: \nt");
	if(C.c[C.n]==1.0||C.c[C.n]==-1.0) printf("%cx^%d",C.c[C.n]==1.0?"":"-",C.n);
	else printf("%lgx^%d",C.c[C.n],C.n);
	for(i=C.n-1;i>1;i--){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx^%d",C.c[i]==1.0?"+":"-",i);
		else printf("%lgx^%d",C.c[i],i);
	}
	if(C.c[i]!=0.0){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx",C.c[i]c==1.0?"+":"-");
		else printf("%+lgx",C.c[i]);
		C.c[0]==0.0?0:printf("%+lg",C.c[0]);
	}
	
	
	//Multiplicación
	for(i=Max;i>=0;i--) C.c[i]=0.0;
	C.n = A.n + B.n;
	for(i=0;i<=A.n,i++){
		for(j=0;j<=B.n;j++){
			C.c[i+j]+=A.c[i]*B.c[j];
		}
	}
	printf("\nLa multiplicacion es: \nt");
	if(C.c[C.n]==1.0||C.c[C.n]==-1.0) printf("%cx^%d",C.c[C.n]==1.0?"":"-",C.n);
	else printf("%lgx^%d",C.c[C.n],C.n);
	for(i=C.n-1;i>1;i--){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx^%d",C.c[i]==1.0?"+":"-",i);
		else printf("%lgx^%d",C.c[i],i);
	}
	if(C.c[i]!=0.0){
		if(C.c[i]==1.0||C.c[i]==-1.0) printf("%cx",C.c[i]c==1.0?"+":"-");
		else printf("%+lgx",C.c[i]);
		C.c[0]==0.0?0:printf("%+lg",C.c[0]);
	}
	
	//Derivada
	printf("\nLa derivada es: \nt");
	C.n = A.n-1;
	for(i=C.n;i>=0;i--) C.c[i]=(i+1)*A.c[i+1];
	while(C.n>0&&C.c[C.n==0.0]) C.n--;
	
	//Integral
	
	
	//Evaluacion
	printf("Escribe un numero: ");
	scanf("%lg",&x);
	for(i=A.n;i>0;i--) y = (y+A.c[i])*x;
	y+=A.c[0];
	
	
	return 0;
}