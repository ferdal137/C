#include <stdio.h>

enum Mes { ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE };

int main() {
    enum Mes cumpleanos = JULIO;

    printf("Mi cumpleaños es en el mes %d\n", cumpleanos);

    return 0;
}
