#include<stdio.h>
#include<stdlib.h>

#define GRADMAX 20

typedef struct _Rx_{
  int g;
  double c[GRADMAX+1];
}Rx;

Rx leeP();
int escP(Rx p);
Rx suma(Rx a, Rx b);
Rx rest(Rx a, Rx b);
Rx mult(Rx a, Rx b);
Rx multMonomio(Rx a, double c, int e);
Rx divR(Rx a, Rx b);
int esCero(Rx a);

int main(int argc, char *argv[])
{
  Rx a, b, q;
  printf("Este programa realiza la suma, resta, producto y division de polinomios");
  printf("Por leer los polinomios.\n");
  a=leeP();
  b=leeP();
  printf("Los polinomios son:\na = ");
  escP(a);
  printf("\nb = ");
  escP(b);
  printf("\nSuma:\n");
  q=suma(a, b);
  escP(q);
  printf("\nResta:\n");
  q=rest(a, b);
  escP(q);
  printf("\nProducto:\n");
  q=mult(a, b);
  escP(q);
  if(esCero(b)){
  	printf("No se puede hacer la division");
  }
  printf("\nCociente:\n");
  q=divR(a, b);
  escP(q);
  printf("\n\nFin del programa\n");

  return 0;
}


Rx leeP()
{
  Rx ret;
  int i;

  printf("digite el grado:");
  scanf("%d", &(ret.g));
  for (i=0; i<=ret.g; i++){
    printf("digite el coeficiente del monomio x^%d:", i);
    scanf("%lf", &(ret.c[i]));
  }
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;

  return ret;
}

int escP(Rx p)
{
  int i;

  if(p.g<0){
    printf(" 0");
    return 0;
  }

  if(p.g>=2) if(p.c[p.g]==1.0||p.c[p.g]==-1) printf("%sx^%d",p.c[p.g]<0.0?"-":"",p.g);
  	else printf("%+lg x^%d ", p.c[p.g], p.g);
  for(i=p.g-1; i>1; i--)
    if (p.c[i]!=0.0) 
		if(p.c[p.g]==1.0||p.c[p.g]==-1) printf("%sx^%d", p.c[i]<0.0?"-":"+", i);
		else printf("%+lg x^%d ", p.c[i],i);
  if(p.g==1) if(p.c[1]==1.0||p.c[1]==-1) printf("%sx", p.c[1]<0.0?"-":"");
  	else printf("%lg x ", p.c [1]);
  else if (p.g>=1 && p.c[1]!=0.0 ) if(p.c[1]==1.0||p.c[1]==-1) printf("%sx", p.c[1]<0.0?"-":"+"); 
  	else printf("%+lg x ", p.c[1]);
  if (p.g==0) printf("%lg", p.c[0]);
   else if (p.c[0]!=0.0) printf("%+lg ", p.c[0]);

  return 0;
}

Rx suma(Rx a, Rx b)
{
  Rx ret;
  int i,min;
  if(a.g<b.g){
  	min = a.g;
  	ret.g = b.g;
  } else{
  	min = b.g;
  	ret.g = a.g;	
  }
  
  for(i=0;i<min;i++) ret.c[i]=a.c[i]+b.c[i];
  if(a.g<b.g) for(;i<=ret.g;i++) ret.c[i]=b.c[i];
  else for(;i<=ret.g;i++) ret.c[i]=a.c[i];
 
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  return ret;
}

Rx rest(Rx a, Rx b)
{
  Rx ret;
  int i;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g = a.g<b.g?b.g:a.g;
  for (i=0; i<=ret.g; i++) ret.c[i]=a.c[i]-b.c[i];
  /* En la resta, el minuendo y el sustraendo podrian haber 
   * tenido el mismo grado, lo que podria implicar que el 
   * grado del polinomio diferencia fuera menor que el del minuendo
   * y el del sustraendo.
   */
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  return ret;
}

Rx mult(Rx a, Rx b)
{
  int i, j;
  Rx ret;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g=a.g+b.g;
  for (i=0; i<=a.g; i++)
    for(j=0; j<=b.g; j++)
      ret.c[i+j]+=a.c[i]+b.c[j];

  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;

  return ret;
}

Rx multMonomio(Rx a, double c, int e)
{
  int i;
  Rx ret;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g=a.g+e;
  for (i=e; i<=ret.g; i++) ret.c[i]=a.c[i-e]*c;

  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;

  return ret;
}

int esCero(Rx a)
{
  return a.g <0;
}


Rx divR(Rx a, Rx b)
{
  Rx q, aux, r;
  int grad, i;

  for (i=0; i<=GRADMAX; i++) q.c[i]=0.0;
  if (a.g<b.g){
    q.g=-1;

    return q;
  }

  q.g=a.g-b.g;
  do{
    grad=a.g-b.g;
    q.c[grad] = a.c[a.g]/b.c[b.g];
    aux = multMonomio(b, q.c[grad], grad);
    a = rest(a, aux);
    r=a;
  }while(!esCero(r) && (a.g>=b.g));


  return q;
}





