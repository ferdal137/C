#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	printf("Gracias a locale.h puedo poner palabras acentuadas como... México :')");
	return 0;
}