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
                             
//Verbos Irregulares: servir, oler, caber, aislar, errar, soñar, soltar   https://conjugador.reverso.net/conjugacion-rules-modelo-espanol/modelo-soltar.html
                        
//char *ModoSubjuntivo
							  
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an     ","an      ",
									   "é       ","aste    ","ó       ","amos    ","aron    ","aron   ",
									   "aré      ","arás   ","ará    ","aremos    ","aran    ","arán    ",
									   "aba      ","abas   ","aba     ","ábamos    ","aban    ","aban    ",
									   "aría      ","arías   ","antaría     ","ariamos    ","arian    ","arian    "};
									   
enBasePronombres DesidenciaSubjAR =   {"e       ","es      ","e       ","emos    ","en     ","en      ",
									   "ara      ","aras   ","ara    ","áramos    ","aran    ","aran    ",
									   "are      ","ares   ","are    ","áremos    ","aren    ","aren    "}; 									   

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
									  
enBasePronombres DesidenciaCompuesta = {"he ","has ","ha ","hemos ","han ","han ",
									   "hube ","hubiste ","hubo ","hubimos ","hubieron ","hubieron ",
									   "habré ","habrás ","habrá ","habremos ","habrán ","habrán ",
									   "había ","habías ","había ","habíamos ","habían ","habían ",
									   "habría ","habrías ","habría ","habríamos ","habrían ","habrían "};
									   
enBasePronombres DesidenciaCompuestaSubj = {"haya ","hayas ","haya ","hayemos ","hayan ","hayan ",
									   "hubiera ","hubieras ","hubiera ","hubieramos ","hubieran ","hubieran ",
									   "hubiere ","hubieres ","hubiere ","hubiéremos ","hubieren ","hubieren "};

enBasePronombres Oler = {"huelo      ","hueles      ","huele       ","oelmos    ","huelen     ","huelen      ",
						"olí      ","oliste   ","olío     ","olimos    ","olieron    ","olieron    ",
					   "oleré      ","olerás   ","olerá    ","oleremos    ","olerán    ","olerán    ",
					   "olía       ","olías    ","olía       ","olíamos    ","olían    ","olían   ",
					   "olería      ","olerías   ","olería     ","oleríamos    ","olerian    ","olerian    "};                                                                       

enBasePronombres Pronombres = {"yo", "tú", "él", "nosotros", "ustedes", "ellos"};                                                                             

int conjugacionRegularAR(FILE *archivo, char raizVerbo[]);
int conjugacionRegularER(FILE *archivo, char raizVerbo[]);
int conjugacionRegularIR(FILE *archivo, char raizVerbo[]);
int conjugacionCompuesta(FILE *archivo, char raizVerbo[], char ter_comp[]);
int conjugacionCompuestaSubj(FILE *archivo, char raizVerbo[], char ter_comp[]);
int conjugacionSubjuntivaAR(FILE *archivo, char raizVerbo[]);
int conjugacionIrregular(FILE *archivo, char raizVerbo[]);                                                                     

int main(int argc, char *argv[])
{                               
  FILE *miArchivo;              
  char buffer[128], ter, ter_comp[3] = "ado", v[5] = "oler";             
  int lbuffer, i;                  
  char *x[] = {"oler",  "s", 0};
  char *s;
	
  setlocale(LC_ALL,"");
	
  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Escriba un verbo regular o un verbo irregular de la siguiente lista: ");
  printf("\n- oler");
  printf("\n");
  scanf("%s", buffer);
  s = buffer;
  
	while(x[i]) {
		
        if(strcmp(x[i], s) == 0) {
        	
        	printf("Por conjugar verbo\n");
        	
			if (strcmp(s,"oler")==0){
				conjugacionIrregular(miArchivo, s);
			}else if(s=="s"){
				printf("funciona");
			}
			    	
            break;
            
        }else{
    	
	  	lbuffer = strlen(buffer);
	  ter = buffer[lbuffer-2];
	                               
	  buffer[lbuffer-2]= '\0';    
	
	  printf("Por conjugar verbo\n");
	  	
	  	switch(ter){
	        case 'a':
	            conjugacionRegularAR(miArchivo, buffer);
	            conjugacionCompuesta(miArchivo,buffer,ter_comp);
	            conjugacionSubjuntivaAR(miArchivo, buffer);
	            conjugacionCompuestaSubj(miArchivo,buffer,ter_comp);
	            break;
	
	        case 'e':
	            conjugacionRegularER(miArchivo, buffer);
	            conjugacionCompuesta(miArchivo,buffer,"ido");
	            break;
	
	        case 'i':
	            conjugacionRegularIR(miArchivo, buffer);
	            conjugacionCompuesta(miArchivo,buffer,"ido");
	            break;
	
	    }
	    
	  	printf("\n");
  	
  }
        i++;
    }
    
  
  	
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

int conjugacionSubjuntivaAR(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=2;tiempo++)
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
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSubjAR[tiempo]); 
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

int conjugacionCompuesta(FILE *archivo, char raizVerbo[],  char ter_comp[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=4;tiempo++)   {
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
	  		fprintf(archivo, "%8s %s%s%s        ", Pronombres[persona], 
    		        DesidenciaCompuesta[tiempo], raizVerbo, ter_comp);
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionCompuestaSubj(FILE *archivo, char raizVerbo[],  char ter_comp[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=2;tiempo++)   {
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
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s%s        ", Pronombres[persona], 
    		        DesidenciaCompuestaSubj[tiempo], raizVerbo, ter_comp);
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionIrregular(FILE *archivo, char raizVerbo[])                                                                           
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
	  		fprintf(archivo, "%8s %s", Pronombres[persona], 
    		        Oler[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}