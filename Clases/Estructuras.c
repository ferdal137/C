#include <stdio.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

int main() {
    // Declaración de una variable de estructura
    struct Persona persona1;

    // Asignación de valores a los miembros
    strcpy(persona1.nombre, "Juan Pérez");
    persona1.edad = 30;

    // Acceso y uso de los miembros
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d\n", persona1.edad);

    return 0;
}
