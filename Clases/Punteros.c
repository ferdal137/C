#include <stdio.h>

int main() {
    int var = 20;    // Declaración de una variable entera
    int *ptr;        // Declaración de un puntero a entero

    ptr = &var;      // Asignación de la dirección de 'var' a 'ptr'

    printf("Valor de var: %d\n", var);
    printf("Dirección de var: %p\n", &var);
    printf("Dirección almacenada en ptr: %p\n", ptr);
    printf("Valor al que apunta ptr: %d\n", *ptr);

    return 0;
}
