#include <stdio.h>       
#include <stdlib.h>    
#include <string.h>  
#include <locale.h> 

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples};                                                             

#define LONGMAX 128

typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

char *ModoIndicativoSimple[]={"Presente", "Pretérito", "Futuro",
                             "Copretérito", "Postpretérito"}; 
                        
//char *ModoSubjuntivo
							  
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an     ","an      ",
									   "é       ","aste    ","ó       ","amos    ","aron    ","aron   ",
									   "aré      ","arás   ","ará    ","aremos    ","aran    ","arán    ",
									   "aba      ","abas   ","aba     ","ábamos    ","aban    ","aban    ",
									   "aría      ","arías   ","antaría     ","ariamos    ","arian    ","arian    "};   

enBasePronombres DesidenciaSimpleER = {"o       ","es      ","e       ","emos    ","en     ","en      ",
									   "i       ","iste    ","ió       ","imos    ","ieron    ","ieron   ",
									   "eré      ","erás   ","erá     ","eremos    ","erán    ","erán    ",
									   "ía      ","ías    ","ía        ","íamos    ","ían    ","ían    ",
									   "ería      ","erías   ","ería     ","eríamos    ","erían    ","erían    "}; 

enBasePronombres DesidenciaSimpleIR = {"o       ","es      ","e       ","imos    ","en     ","en      ",
									   "í       ","iste    ","ió       ","imos    ","ieron    ","ieron   ",
									   "iré      ","irás   ","irá     ","iremos    ","irán    ","irán    ",
									   "ía      ","ías    ","ía        ","íamos    ","ían    ","ían    ",
									   "iría      ","irías   ","iría     ","iríamos    ","irían    ","irían    "};                                                                          

enBasePronombres Pronombres = {"yo", "tú", "él", "nosotros", "ustedes", "ellos"};                                                                             

int conjugacionRegular(FILE *archivo, char raizVerbo[]);                                                                          

int main(int argc, char *argv[])
{                               
  FILE *miArchivo;              
  char buffer[128], ter;             
  int lbuffer;                  
	
  setlocale(LC_ALL,"");
	
  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Escriba un verbo regular: ");
  scanf("%s", buffer);
  lbuffer = strlen(buffer);
  //ter = buffer[1]; // + buffer[lbuffer];
  ter = buffer[lbuffer-2];
                               
  buffer[lbuffer-2]= '\0';    

  printf("Por conjugar verbo\n");
  	
  	switch(ter){
        case 'a':
            conjugacionRegularAR(miArchivo, buffer);
            break;

        case 'e':
            conjugacionRegularER(miArchivo, buffer);
            break;

        case 'i':
            conjugacionRegularIR(miArchivo, buffer);
            break;

    }
  	printf("\n");
  	
  //conjugacionRegular(miArchivo, buffer);
  printf("Verbo Conjugado\n");                    

  fclose(miArchivo);

  printf("FIN\n");

  return 0;
}          

int conjugacionRegularAR(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionRegularER(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionRegularIR(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}