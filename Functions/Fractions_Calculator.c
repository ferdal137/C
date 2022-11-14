#include <stdio.h>    /funciones de entrada y salida est'andar/
#include <stdlib.h>   /funciones de la biblioteca est'andar/   

typedef struct Q{
  int p, q;        
}Q;                

int mcd(int a, int b);
Q sumaQ(Q a, Q b);    
Q restaQ(Q a, Q b);  
Q prodQ(Q a, Q b);  
Q divQ(Q a, Q b);  
Q simplificaQ(Q a);
Q leerQ(void);
void escribeQ(Q a);    
Q creaQ(int num, int den); 

int main(int argc, char *argv[])
{                               
  Q x, y, r;                    

  x = leerQ();                     
  y = leerQ();                   
  escribeQ(x);                         
  printf(" y ");                       
  escribeQ(y);                         
  printf("\n");                        
  r = sumaQ(x, y);                     
  printf("La suma es: \n");              
  escribeQ(r);
  r = restaQ(x, y);                     
  printf("\nLa resta es: \n");              
  escribeQ(r); 
  r = prodQ(x, y);                     
  printf("\nLa multiplicacion es: \n");              
  escribeQ(r); 
  r = divQ(x, y);                     
  printf("\nLa division es: \n");              
  escribeQ(r);            
  printf("\nFIN DEL PROGRAMA\n");      

  return 0;
}          

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
