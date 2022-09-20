#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define leer(a) printf("escriba el valor de:#a");\
                 scanf("%lg,&a")
                 


int main(int argc, char *argv[]) {
	double a,b,c,x1,x2,dis;
	printf("este programa resuelve ecuaciones cuadraticas con coeficientes reales de la forma\n"
	       "ax^2+bx+c=0\n");
	       
	       leer(a); 
	       leer(b);
	       leer(c);
	       
	    if(a==0.0){
		      if(b==0.0){
		    	 if(c==0.0){
		    		printf("la ecuacion tiene infinidad de soluciones\n");
		    	 }else{
		    		printf("la ecuacion es inconsistente\n");
		    	   }
			}else{
				printf("la ecuacion es lineal\n");
				x1=-c/b;
				printf("la solucion de la ecuacion es:%lg\n",x1);
			}	
		}else{
			dis=b*b-4*a*c;
			if(dis<0.0){
				x1=-b/2.0*a;
				x2=sqrt(-dis)/2.0*a;
				printf("la ecuacion ingresada tiene raices complejas");
				if(x1!=0.0){
					printf("x1=%lg,x1");
					if(x2=1.0){
						printf("+i y x2=%lg-i\n",x1);
					}else{
						printf("+i%lg y x2=%lg-i%lg\n",x2,x1,x2);
					}
				}else{
					if(x2=1.0){
						printf("x1=i y x2=-i\n",x1);
					}else{
						printf("i%lg y x2=-i%lg\n",x2,x2);
					}
					
				}
			}else{
				if(dis=0){
					printf("tiene raiz doble\n");
					x1=-b/2.0*a;
					printf("x=%lg\n,x1");
				}else{
					printf("las raices son:\n");
					x1=(-b+sqrt(dis))/2.0*a;
					printf("x1=%lg y x2=%lg\n",x1,x2);
				}
			}
		}	
	       	 
	       
	return 0;
}