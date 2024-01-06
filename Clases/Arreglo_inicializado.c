#include <stdio.h>

int main() {
    // Declaración e inicialización de un arreglo
    int valores[] = {5, 10, 15, 20, 25};

    // Acceder e imprimir todos los elementos
    for(int i = 0; i < 5; i++) {
        printf("valores[%d] = %d\n", i, valores[i]);
    }

    return 0;
}
