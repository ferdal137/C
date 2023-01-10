# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct gaussianosr{
    float re;
    float im;
}GAUSSR;

GAUSSR leerGR();
GAUSSR sumaGR(GAUSSR z, GAUSSR y);
GAUSSR restaGR(GAUSSR z, GAUSSR y);
GAUSSR prodGR(GAUSSR z, GAUSSR y);
float modGR(GAUSSR z);
void escribGR(GAUSSR z);

int main(int argc, char *argv){

    GAUSSR A, B, C;
    float k;

    A = leerGR();
    printf("El primer numero es: ");
    escribGR(A);
    
    B = leerGR();
    printf("El segundo numero es: ");
    escribGR(B);


    C = sumaGR(A, B);
    printf("La suma es: ");
    escribGR(C);
    
    C = restaGR(A, B);
    printf("La resta es: ");
    escribGR(C);

    C = prodGR(A, B);
    printf("El producto es: ");
    escribGR(C);

    k = modGR(A);
    printf("El modulo del primer gaussiano es: %f", k);

    k = modGR(B);
    printf("\nEl modulo del segundo gaussiano es: %f", k);



    return 0;

}


GAUSSR leerGR(){

    GAUSSR z;

    printf("Por leer un numero gaussiano.\nDigite la parte real:");
    scanf("%f", &(z.re));
    printf("Digite la parte imaginaria:");
    scanf("%f", &(z.im));


    return z;

}

void escribGR(GAUSSR z){
    
    printf("%f %+f i\n", z.re, z.im);
    
    
}

GAUSSR sumaGR(GAUSSR z, GAUSSR y){

    GAUSSR c;
    
    c.re = z.re + y.re;
    c.im = z.im + y.im;

    return c;

}


GAUSSR restaGR(GAUSSR z, GAUSSR y){
    
    GAUSSR c;
    
    c.re = z.re - y.re;
    c.im = z.im - y.im;

    return c;
    
}


GAUSSR prodGR(GAUSSR z, GAUSSR y){
    
    GAUSSR c;
    
    c.re = (z.re*y.re) - (z.im*y.im);
    c.im = (z.re*y.im) + (z.im*y.re);

    return c;
}

float modGR(GAUSSR z){

    float c;

    c = sqrt((z.re*z.re)+(z.im*z.im));

    return c;

}

GAUSSR divGR(GAUSSR a, GAUSSR b)
{                
  GAUSSR r, t, s;
  double m;           
  
  s.im=b.im;
  s.re=(0.0-b.re);
  t=productoC(a, s);
  
  if(m==0.0){
  	r.im=0.0;
  	r.re=0.0;
  	
  	return r;
  }
  
  m=b.im*b.im+b.re*b.re;
  r.im=t.im/m;
  r.re=t.re/m;

  return r;
}