#include <stdio.h>
#include <stdlib.h>

typedef struct _ZP_{
	int a, p;
}Zp;

Zp sumaZp(Zp a, Zp b);
Zp restaZp(Zp a, Zp b);
Zp prodZp(Zp a, Zp b);
Zp inverZp(Zp x);
Zp divZp(Zp a, Zp b);
Zp LeerZp(int p);
int escZp(Zp a);

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