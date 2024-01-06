#include <stdio.h>

// Definición del enumerador
enum Dias { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

int main() {
    // Declaración de una variable de tipo enumerador
    enum Dias hoy;

    hoy = VIERNES;

    if (hoy == VIERNES) {
        printf("¡Hoy es viernes!\n");
    }

    return 0;
}
