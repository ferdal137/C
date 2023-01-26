#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>G

typedef struct direccion{
	char calle[25], colonia[25], ciudad[25], estado[25];
	int cp; 
}Direc;

typedef struct _entradaDirectorio_{
	char nombre[20], apellidoPaterno[20], apellidoMaterno[20], solt;
	
	unsigned short lada;
	unsigned int telFijo, telCel;
	
	float peso;
	double num;
	Direc dire;
	int *puntero;
	
}EntradaDirectorio;

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info);
int obtenEntrada(FILE *directorio, EntradaDirectorio *info);

EntradaDirectorio EscanEnt(void);
int ImprimirNombres(FILE *directorio);

void ImprimirContacto(FILE *directorio, int e);
void InsertContacto(FILE *directorio, int e, int n);
void BorrarContacto(FILE *directorio, int e, int n);
void ModifContacto(FILE *directorio, int e, int n);
void ModifDato(FILE *directorio, int e, int n, int dato);

int main(int argc, char *argv[]){
	
	FILE *archivoBinario;
	int i,j,n,k;
	int opcion, posicion, dato;

	EntradaDirectorio entrada;
	
	n = 4;
	
	printf("\nBIENVENIDO AL DIRECTORIO\n");
	printf("\nLos datos guardados en el directorio son los siguientes:\n\n");
	archivoBinario = fopen("directorio.bin", "ab+");


	if (archivoBinario == NULL){
		int errAuxiliar;
		errAuxiliar = errno;
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", errAuxiliar, strerror(errAuxiliar));
		return 0;
	}

	i=ImprimirNombres(archivoBinario);
	do{
		printf("\nMENU\n");
		printf("\nElija una opcion\n");
		printf("\n1-Insertar contacto\n");
		printf("\n2-Modificar contacto\n");
		printf("\n3-Modificar una Entrada de un Contacto\n");
		printf("\n4-Ver contacto\n");
		printf("\n5-Borrar contacto\n");
		printf("\n6-Borrar todo el Directorio\n");
		printf("\n7-Mostrar toda la agenda\n");
		printf("\n8-Salir del Programa\n\n");
		scanf("%d", &opcion);
		switch(opcion){
			
			case 1:
				printf("Digite la posicion en la que desea guardar el nuevo contacto:  ");
				scanf("%d", &posicion);
				InsertContacto(archivoBinario, posicion, i);
				printf("Los Datos del Nuevo Contacto son:\n");
				ImprimirContacto(archivoBinario, posicion);
				i++;
				n++;
				break;
				
			case 2:
				printf("Los datos contactos son:\n");
				ImprimirNombres(archivoBinario);
				printf("\n");
				printf("Escriba el numero de Contacto que Desea Modificar:  ");
				scanf("%d", &posicion);
				ModifContacto(archivoBinario, posicion, i);
				printf("El Contacto se ha Modificado:\n");
				ImprimirContacto(archivoBinario, posicion);
				break;
				
			case 3:
				printf("Los datos contactos son:\n");
				ImprimirNombres(archivoBinario);
				printf("\n");
				printf("Numero de Contacto que Desea Modificar: ");
				scanf("%d", &posicion);
				printf("Eliga el dato del contacto que desea modificar: ");
				printf("\n1-Nombre");
				printf("\n2-Apellido Paterno");
				printf("\n3-Apellido Materno");
				printf("\n4-Lada");
				printf("\n5-Telefono Fijo");
				printf("\n6-Celular");
				printf("\n7-Calle");
				printf("\n8-Colonia");
				printf("\n9-Codigo Postal");
				printf("\n10-Ciudad");
				printf("\n11-Estado");
				printf("\n12-Peso");
				printf("\n13-Estado civil");
				printf("\n14.Numero decimal favorito\n");
				scanf("%d", &dato);
				ModifDato(archivoBinario, posicion, i, dato);
				printf("\nEl contacto se ha sido modificado:\n");
				//ImprimirContacto(archivoBinario, posicion);
				break;
			
			case 4:
				printf("Los datos contactos son:\n");
				ImprimirNombres(archivoBinario);
				printf("\n");
				printf("\nEscriba el numero de contacto que desea ver:  ");
				scanf("%d", &posicion);
				ImprimirContacto(archivoBinario, posicion);
				break;
				
			case 5:
				printf("Los datos contactos son:\n");
				ImprimirNombres(archivoBinario);
				printf("\n");
				printf("Escriba el numero de contacto que desea borrar:  ");
				scanf("%d", &posicion);
				BorrarContacto(archivoBinario, posicion, i);
				i--;
				break;
				
			case 6:
				fclose(archivoBinario);
				archivoBinario = fopen("directorio.bin", "wb+");
				i=0;
				break;
				
			case 7:
				for(k=1;k<(n+1);k++){
					ImprimirContacto(archivoBinario, k);
				}
				break;
				
		}
	}while(opcion!=8);
	printf("\nFIN\n.");
	fclose(archivoBinario);	
	return 0;
}

int obtenEntrada(FILE *directorio, EntradaDirectorio *info){
	int ret;
	ret = fread(info, 1, sizeof(EntradaDirectorio), directorio);
	if (ret<sizeof(info)){
		int unError = errno;
		if (ret == 0) return -2;
		printf("\nError al leer informacion en el directorio (%d, %d, %s)\n", ret, unError, strerror(unError));
		return -1;
	}
	return 0;
}

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info){
	long pos;
	int ret;
	pos = ftell(directorio);
	ret = fseek(directorio, 0L, SEEK_END);
	if (ret < 0){
		printf("Error al ir al final del archivo\n");
		return -1;
	}
	ret=fwrite(&info, 1, sizeof(info), directorio);
	if (ret<sizeof(info)){
		printf("Error al escribir la informacion en el directorio\n");
		return -2;
	}
	ret = fseek(directorio, pos, SEEK_SET);
	return 0;
}

EntradaDirectorio EscanEnt(void){
	EntradaDirectorio entrada;
	
	printf("Introduzca los datos para el nuevo elemento del directorio:\n\n");
	printf("Nombre: ");
	scanf("%*c%[^\n]s", entrada.nombre);   
	printf("\n\nApellido Paterno: ");
	scanf("%*c%[^\n]s", entrada.apellidoPaterno);
	printf("\n\nApellido Materno: ");
	scanf("%*c%[^\n]s", entrada.apellidoMaterno);
	printf("\n\nLada: ");
	scanf("%u", &(entrada.lada));                    
	printf("\n\nTel Fijo: ");
	scanf("%u", &(entrada.telFijo));             
	printf("\n\nCel: ");
	scanf("%u", &(entrada.telCel));
	printf("\nDatos de la Direccion.\n\n");
	printf("Calle: ");
	scanf("%*c%[^\n]s", &entrada.dire.calle);
	printf("\n\nColonia: ");
	scanf("%*c%[^\n]s", &entrada.dire.colonia);
	printf("\n\nCodigo postal: ");
	scanf("%d", &entrada.dire.cp);
	printf("\n\nCiudad: ");
	scanf("%*c%[^\n]s", &entrada.dire.ciudad);
	printf("\n\nEstado: ");
	scanf("%*c%[^\n]s", &entrada.dire.estado);
	printf("\n\nPeso en kg: ");
	scanf("%f", &entrada.peso);
	printf("\n\nEstado Civil. Soltero(S)/Casado(C): ");
	scanf(" %c", &entrada.solt);
	printf("\n\nNumero decimal favorito: ");
	scanf("%lg", &entrada.num);
	printf("\n\n");
	return entrada;
}

int ImprimirNombres(FILE *directorio){
	int i, ret;
	EntradaDirectorio entrada;
	ret = fseek(directorio, 0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	for(i=0;!feof(directorio);i++){
		if (obtenEntrada(directorio, &entrada)<0) break;
		printf("%d.-%s %s %s\n\n", i+1, entrada.nombre, entrada.apellidoPaterno, entrada.apellidoMaterno);
	}
	if(i==0){
		printf("\nNo se tienen datos almacenados en el directorio\n");
	}
	return i;
}


void ImprimirContacto(FILE *directorio, int e){
	int i, ret;
	EntradaDirectorio entrada;
	ret = fseek(directorio, sizeof(EntradaDirectorio)*(e-1), SEEK_SET);
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	
	obtenEntrada(directorio, &entrada);
	printf("\nLos datos guardados son los siguientes\n");
	printf("\nNombre: %s %s %s\n",entrada.nombre, entrada.apellidoPaterno, entrada.apellidoMaterno);
	printf("\nTelefono fijo: ");
	printf("(%u) %u\n", entrada.lada, entrada.telFijo);
	printf("\nTelefono celular: ");
	printf("(%u) %u\n", entrada.lada, entrada.telCel);
	printf("\nDireccion: \n");
	printf("Calle: %s \n", entrada.dire.calle);
	printf("Colonia: %s \n", entrada.dire.colonia);
	printf("CP: %d\n", entrada.dire.cp);
	printf("Ciudad: %s\n", entrada.dire.ciudad);
	printf("Estado: %s\n\n", entrada.dire.estado);
	printf("Peso: %f kg\n\n", entrada.peso); 
	printf("Estado Civil: %c\n\n", entrada.solt); 
	printf("Numero decimal favorito: %lg\n", entrada.num);
	
}

void InsertContacto(FILE *directorio, int e, int n){	
	e--;
	EntradaDirectorio *aux;
	int i, ret;
	
	ret = fseek(directorio, 0L, SEEK_SET);
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	} aux=(EntradaDirectorio*)malloc((n+1)*(sizeof(EntradaDirectorio)));
	
	for(i=0;i<e;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	} aux[e]=EscanEnt();
	
	for(i=e+1;i<n+1;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	} ret = fseek(directorio, 0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	
	fclose(directorio);
	directorio = fopen("directorio.bin", "wb+");
	
	if (directorio == NULL){
		int errAuxiliar;
		errAuxiliar = errno;
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", errAuxiliar, strerror(errAuxiliar));
	} ret = fseek(directorio, 0L, SEEK_SET);
	
	for(i=0;i<n+1;i++){
		agregaEntradaAlFinal(directorio, aux[i]);
	}
}

void BorrarContacto(FILE *directorio, int e, int n){
	e--;
	EntradaDirectorio *aux, entrada;
	int i, ret;
	ret = fseek(directorio, 0L, SEEK_SET);
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	aux=(EntradaDirectorio*)malloc((n-1)*(sizeof(EntradaDirectorio)));
	for(i=0;i<e;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	}
	obtenEntrada(directorio, &entrada);
	for(i=e;i<n-1;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	}
	ret = fseek(directorio, 0L, SEEK_SET);
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	fclose(directorio);
	directorio = fopen("directorio.bin", "wb+");
	fclose(directorio);
	directorio = fopen("directorio.bin", "ab+");
	
	if (directorio == NULL){
		int errAuxiliar;
		errAuxiliar = errno;
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", errAuxiliar, strerror(errAuxiliar));
	}
	ret = fseek(directorio, 0L, SEEK_SET);
	for(i=0;i<n-1;i++){
		agregaEntradaAlFinal(directorio, aux[i]);
	}
}

void ModifContacto(FILE *directorio, int e, int n){
	
	e--;
	EntradaDirectorio *aux, entrada;
	int i, ret;
	ret = fseek(directorio, 0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	} aux=(EntradaDirectorio*)malloc((n)*(sizeof(EntradaDirectorio)));
	
	for(i=0;i<e;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	}
	obtenEntrada(directorio, &entrada);
	aux[e]=EscanEnt();
	
	for(i=e+1;i<n;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	} ret = fseek(directorio, 0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	fclose(directorio);
	directorio = fopen("directorio.bin", "wb+");
	fclose(directorio);
	directorio = fopen("directorio.bin", "ab+");
	
	if (directorio == NULL){
		int errAuxiliar;
		errAuxiliar = errno;
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", errAuxiliar, strerror(errAuxiliar));
	} ret = fseek(directorio, 0L, SEEK_SET);
	
	for(i=0;i<n;i++){
		agregaEntradaAlFinal(directorio, aux[i]);
	}
}

void ModifDato(FILE *directorio, int e, int n, int dato){
	e--;
	EntradaDirectorio *aux, entrada;
	int i, ret;
	ret = fseek(directorio, 0L, SEEK_SET);
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	
	aux=(EntradaDirectorio*)malloc((n)*(sizeof(EntradaDirectorio)));
	for(i=0;i<n;i++){
		if(obtenEntrada(directorio, &aux[i])<0) break;
	}
	
	switch(dato){
		case 1:
			printf("Nombre:");
			scanf("%*c%[^\n]s", &aux[e].nombre);   
			break;
			
		case 2:
			printf("Apellido paterno:");
			scanf("%*c%[^\n]s", &aux[e].apellidoPaterno);
			break;
			
		case 3:
			printf("Apellido materno:");
			scanf("%*c%[^\n]s", &aux[e].apellidoMaterno);
			break;
			
		case 4:
			printf("Lada:");
			scanf("%u", &(aux[e].lada));                    
			break;
			
		case 5:
			printf("Tel fijo:");
			scanf("%u", &(aux[e].telFijo));             
			break;
			
		case 6:
			printf("Cel:");
			scanf("%u", &(aux[e].telCel));
			break;
			
		case 7:
			printf("Calle:");
			scanf("%*c%[^\n]s", &aux[e].dire.calle);
			break;
			
		case 8:
			printf("Colonia:");
			scanf("%*c%[^\n]s", &aux[e].dire.colonia);
			break;
			
		case 9:
			printf("Codigo postal:");
			scanf("%d", &aux[e].dire.cp);
			break;
		
		case 10:
			printf("Ciudad:");
			scanf("%*c%[^\n]s", &aux[e].dire.ciudad);
			break;
		
		case 11:
			printf("Estado:");
			scanf("%*c%[^\n]s", &aux[e].dire.estado);
			break;
		
		case 12:
			printf("Peso en kg:");
			scanf("%f", &aux[e].peso);
			break;
			
		case 13:
			printf("Caracter Estado Civil:");
			scanf(" %c", &aux[e].solt);
			break;
			
		case 14:
			printf("Numero decimal favorito:");
			scanf("%lg", &aux[e].num);
			break;
	}
	
	ret = fseek(directorio, 0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo\n");
	}
	fclose(directorio);
	directorio = fopen("directorio.bin", "wb+");
	fclose(directorio);
	directorio = fopen("directorio.bin", "ab+");
	
	if (directorio == NULL){
		int errAuxiliar;
		errAuxiliar = errno;
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", errAuxiliar, strerror(errAuxiliar));
	} ret = fseek(directorio, 0L, SEEK_SET);
	
	for(i=0;i<n;i++){
		agregaEntradaAlFinal(directorio, aux[i]);
	}
}