#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

#define TRUE 1
#define FALSE 0

typedef struct _entradaDirectorio_{
  char nombre[32], apellidoPaterno[32], apellidoMaterno[32];
  unsigned short lada;                                      
  unsigned int telFijo, telCel;                             
  char anotacion[64];
  //Agregar más datos  direccion,                                        
}EntradaDirectorio;                                         

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info);
int obtenEntrada(FILE *directorio, EntradaDirectorio *info);  
int MostrarContactos(FILE *directorio);
int EditarCampoContacto(FILE *directorio, int c, int cont, int tc);  

int main(int argc, char *argv[])
{                               
  FILE *archivoBinario;         
  int i, opcion;                        
  EntradaDirectorio entrada; 
  char repetir = TRUE;  

  printf("Ejemplo de archivos binarios. Uso de un directorio ...\n");

  archivoBinario = fopen("directorio.bin", "ab+");

  if (archivoBinario == NULL){
    int errAuxiliar;          
    errAuxiliar = errno;      
    fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
errAuxiliar, strerror(errAuxiliar));                                            
    return 0;                                                                   
  }                                                                             

	do {
        system("cls");
        
        // Texto del menú
        printf("\n\nMenu de Opciones\n");
        printf("1. Insertar contacto\n");
        printf("2. Modificar un contacto\n");
        printf("3. Modificar una entrada del contacto\n");
        printf("4. Agregar contacto\n");
        printf("5. Borrar contacto\n");
        printf("6. Borrar todo el directorio\n");
        printf("0. SALIR\n");
        
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                printf("Instrucciones de la opcion 1\n");
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                printf("Instrucciones de la opcion 2\n");
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                printf("Instrucciones de la opcion 3\n");
                system("pause>nul"); // Pausa            
                break;
                
            case 4:
                printf("Instrucciones de la opcion 4\n");
                system("pause>nul"); // Pausa                
                break;
            
            case 0:
            	repetir = FALSE;
            	break;
        }        
    } while (repetir);

  for (i=0; !feof(archivoBinario); i++){
    if (obtenEntrada(archivoBinario, &entrada)<0) break;
    printf("\n\n\tnombre: %s %s %s",                    
           entrada.nombre, entrada.apellidoPaterno, entrada.apellidoMaterno);
    printf("\n\ttelefono fijo: ");                                           
    if (entrada.telFijo!=0) printf("(%u) %u", entrada.lada, entrada.telFijo);
    else printf("sin numero telefonico");                                    
    printf("\n\ttelefono celular: ");                                        
    if (entrada.telCel!=0) printf("(%u) %u", entrada.lada, entrada.telCel);  
    else printf("sin numero de telefonia celular");                          
  }                                                                          
  if (i==0) printf("\nDirectorio vacio.\n");                                 
  else printf("\n%d entradas en el directorio.\n", i);                       

  printf("Por agregar un elemento al directorio:\n");
  printf("nombre: "); scanf("%s", entrada.nombre);   
  printf("apellido paterno: "); scanf("%s", entrada.apellidoPaterno);
  printf("apellido materno: "); scanf("%s", entrada.apellidoMaterno);
  printf("lada: "); scanf("%u", &(entrada.lada));                    
  printf("tel fijo: "); scanf("%u", &(entrada.telFijo));             
  printf("cel: "); scanf("%u", &(entrada.telCel));                   

  agregaEntradaAlFinal(archivoBinario, entrada);

  fclose(archivoBinario);
  
  printf("FIN\n");

  return 0;
}

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info)
{
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

int obtenEntrada(FILE *directorio, EntradaDirectorio *info)
{
  int ret;

  ret = fread(info, 1, sizeof(EntradaDirectorio), directorio);
  if (ret<sizeof(info)){
    int unError = errno;
    if (ret == 0) return -2;
    printf("\nError al leer informacion en el directorio (%d, %d, %s)\n",
           ret, unError, strerror(unError));
    return -1;
  }

  return 0;
}

int MostrarContactos(FILE *directorio){
	EntradaDirectorio entrada;
	int i,ret;
	ret = fseek(directorio,0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo");
		return -1;
	}
	
	for(i=0; !feof(directorio);i++){
		if(obtenEntrada(directorio, &entrada)<0) break;
		printf("\n\n\tnombre: %s %s %s",
				entrada.nombre,entrada.apellidoPaterno,entrada.apellidoMaterno);
		ret = fseek(directorio,0L, SEEK_SET);
		
	}
	
	if(ret<0){
		printf("Error al ir al inicio del archivo");
		return -1;
	}
	
	return i;
}

int EditarCampoContacto(FILE *directorio, int c, int cont, int tc){
	EntradaDirectorio *entrada;
	int i, ret;
	
	ret = fseek(directorio,0L, SEEK_SET);
	
	if(ret<0){
		printf("Error al ir al inicio del archivo");
		return -1;
	}
	
	entrada = (EntradaDirectorio*)malloc(tc*sizeof(EntradaDirectorio));
	for(i=0; !feof(directorio);i++){
		if(obtenEntrada(directorio,&entrada[i])<0) break;}
	
	fclose(directorio);
	directorio = fopen("directorio.bin","wb+");
	
	if (directorio == NULL){
    int errAuxiliar;          
    errAuxiliar = errno;      
    fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
errAuxiliar, strerror(errAuxiliar));                                            
    return 0;                                                                   
  }   
	
	// Aqui iba un switch
	return 0;
}

