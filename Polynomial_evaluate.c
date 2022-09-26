#include <stdio.h>
#include <stdlib.h>

#define LEER ( x , i ) printf ( " Escriba el coeficiente de x ^ % d : " , i ) ; scanf ( " % lg " , & x )

int main ( int argc , char * argv [ ] ) {
    
    int i , n ;
    double a , x = 0.0 , c ;
    printf( " Este programa evalua polinomios . \ n " ) ;
    printf( " Escriba el grado del polinomio : \ n " ) ;
    scanf( " % d " , & n ) ;
    printf( " Escriba el numero en el que se va a evaluar el polinomio : \ n " ) ;
    scanf( " % lg " , & a ) ;
    for ( i = n ; i > 0 ; i -- ) {
        LEER ( c , i ) ;
        x = ( x + c ) * a ;
    }
        LEER ( c , i ) ;
        X + = C ;
    printf( " El resultado es : % lg " , x ) ;

    return 0 ;
    
    }