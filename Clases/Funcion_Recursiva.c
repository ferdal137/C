#include <stdio.h>

// Función recursiva para calcular el factorial
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5;
    printf("El factorial de %d es %d\n", num, factorial(num));
    return 0;
}
