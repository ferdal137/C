#include <stdio.h>

// Definición de la unión
union Datos {
    int entero;
    float flotante;
    char caracter;
};

int main() {
    // Declaración de una variable de unión
    union Datos dato;

    // Asignación y uso del miembro 'entero'
    dato.entero = 10;
    printf("Dato entero: %d\n", dato.entero);

    // Asignación y uso del miembro 'flotante'
    dato.flotante = 5.25;
    printf("Dato flotante: %f\n", dato.flotante);

    // Nota: al modificar 'flotante', el valor de 'entero' se sobrescribe

    return 0;
}
