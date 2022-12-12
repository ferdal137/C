#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

typedef struct _entradaDirectorio_{
  char nombre[32], apellidoPaterno[32], apellidoMaterno[32];
  unsigned short lada;                                      
  unsigned int telFijo, telCel;                             
  char anotacion[64];                                       
}EntradaDirectorio;                                         

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info);
int obtenEntrada(FILE *directorio, EntradaDirectorio *info);       

int main(int argc, char *argv[])
{                               
  FILE *archivoBinario;         
  int i;                        
  EntradaDirectorio entrada;    

  printf("Ejemplo de archivos binarios. Uso de un directorio ...\n");

  archivoBinario = fopen("directorio.bin", "ab+");

  if (archivoBinario == NULL){
    int errAuxiliar;          
    errAuxiliar = errno;      
    fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
errAuxiliar, strerror(errAuxiliar));                                            
    return 0;                                                                   
  }                                                                             

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