#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Implementation of the locale library to can show accents in the console 

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	printf("Gracias a locale.h puedo poner palabras acentuadas como... México :')");
	return 0;
}