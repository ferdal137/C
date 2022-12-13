/*
ar  er  ir 

16 tiempos

*/

#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples};                                                             

#define LONGMAX 128

typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

char *ModoIndicativoSimple[]={"Presente", "Pret'erito", "Futuro",
                             "Copret'erito", "Postpret'erito"};  
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an     ","an      ",
									   "e       ","aste    ","o       ","amos    ","aron    ","aron   ",
									   "are      ","aras   ","ara     ","aremos    ","aran    ","aran    "};                                                                             

enBasePronombres Pronombres = {"yo", "t'u", "'el", "nosotros", "ustedes", "ellos"};                                                                             

int conjugacionRegular(FILE *archivo, char raizVerboAR[]);                                                                          

int main(int argc, char *argv[])
{                               
  FILE *miArchivo;              
  char buffer[128];             
  int lbuffer;                  

  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Escriba un verbo regular terminado en ar (ADVERTENCIA: No atender "
         "a esta instrucci'on ocasionar'a un resultado inesperado :-) ):");  

  scanf("%s", buffer);
  lbuffer = strlen(buffer);

                                        
  buffer[lbuffer-2]= '\0';                  

  printf("Por conjugar verbo\n");
  conjugacionRegular(miArchivo, buffer);
  printf("Verbo Conjugado\n");                    

  fclose(miArchivo);

  printf("FIN\n");

  return 0;
}          

int conjugacionRegular(FILE *archivo, char raizVerboAR[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerboAR)+2;

  for(tiempo=0;tiempo<=1;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/3;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/3;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerboAR, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");

  return 0;  
}