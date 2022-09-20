#include <stdio.h> //\n

#define Suma(n) n*(n+1)/2
#define S2(n) (n*(n+1)*(2*n+1))/6
#define S3(n) Suma(n) * Suma(n)
#define S3p(n) 2*(n*(n+1) * n*(n+1))
#define S3p2(n) 8*Suma(n)*Suma(n)

int main(){

    int n, s;

    printf("Este programa suma enteros. Ingrese el n-esimo término: \n");

    scanf("%d", &n);

    s = Suma(n);

    printf("Suma de los primeros %d numeros es: %d \n", n ,s);

    s = S2(n);

    printf("Suma de los cuadrados de los primeros %d numeros es: %d \n", n ,s);
    
    s = S3(n);

    printf("Suma de los cubos de los primeros %d numeros es: %d \n", n ,s);
    
    s = S3p(n);

    printf("Suma de los cubos de los primeros %d numeros pares es: %d \n", n ,s);
    
    s = S3p2(n);

    printf("Suma de los cubos de los primeros %d numeros pares es: %d \n", n ,s);

    return 0;
    

}