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
							   
							  
enBasePronombres DesidenciaSimpleAR = {"o       ","as      ","a       ","amos    ","an      ","an      ",
									   "é       ","aste    ","ó       ","amos    ","aron    ","aron    ",
									   "aré       ","arás      ","ará       ","aremos    ","aran      ","arán      ",
									   "aba       ","abas      ","aba       ","ábamos    ","aban      ","aban      ",
									   "aría      ","arías   ","antaría     ","ariamos    ","arian    ","arian    "};
									   
enBasePronombres DesidenciaSimpleER = {"o       ","es      ","e       ","emos    ","en      ","en      ",
									   "i        ","iste     ","ió       ","imos     ","ieron    ","ieron    ",
									   "eré       ","erás      ","erá       ","eremos    ","erán      ","erán      ",
									   "ía        ","ías       ","ía        ","íamos     ","ían       ","ían       ",
									   "ería      ","erías   ","ería     ","eríamos    ","erían    ","erían    "}; 
									   
enBasePronombres DesidenciaSimpleIR = {"o       ","es      ","e       ","imos    ","en      ","en      ",
									   "í        ","iste     ","ió       ","imos     ","ieron    ","ieron    ",
									   "iré       ","irás      ","irá       ","iremos    ","irán      ","irán      ",
									   "ía       ","ías      ","ía       ","íamos    ","ían      ","ían      ",
									   "iría      ","irías   ","iría     ","iríamos    ","irían    ","irían    "}; 
									   
enBasePronombres DesidenciaSubjAR =   {"e       ","es      ","e       ","emos    ","en      ","en      ",
									   "ara       ","aras      ","ara       ","áramos    ","aran      ","aran      ",
									   "are      ","ares   ","are    ","áremos    ","aren    ","aren    "}; 
									   
enBasePronombres DesidenciaSubjER =   {"a       ","as      ","a       ","amos    ","an      ","an      ",
									   "iera       ","ieras      ","iera       ","iéramos    ","ieran      ","ieran      ",
									   "iere      ","ieres   ","iere    ","iéremos    ","ieren    ","ieren    "};
									   
enBasePronombres DesidenciaSubjIR =   {"a       ","as      ","a       ","amos    ","an      ","an      ",
									   "iera       ","ieras      ","iera       ","iéramos    ","ieran      ","ieran      ",
									   "iere      ","ieres   ","iere    ","iéremos    ","ieren    ","ieren    "};							   

									  
enBasePronombres DesidenciaCompuesta = {"he    ","has   ","ha    ","hemos ","han   ","han   ",
									   "hube     ","hubiste  ","hubo     ","hubimos  ","hubieron ","hubieron ",
									   "habré    ","habrás   ","habrá    ","habremos ","habrán   ","habrán   ",
									   "había    ","habías   ","había    ","habíamos ","habían   ","habían   ",
									   "habría    ","habrías   ","habría    ","habríamos ","habrían   ","habrían   "};
									   
enBasePronombres DesidenciaCompuestaSubj = {"haya    ","hayas   ","haya    ","hayemos ","hayan   ","hayan   ",
									   "hubiera    ","hubieras   ","hubiera    ","hubieramos ","hubieran   ","hubieran   ",
									   "hubiere    ","hubieres   ","hubiere    ","hubiéremos ","hubieren   ","hubieren   "};

enBasePronombres Oler = {"huelo       ","hueles      ","huele       ","olemos      ","huelen      ","huelen      ",
						"olí        ","oliste     ","olío       ","olimos     ","olieron    ","olieron    ",
					   "oleré       ","olerás      ","olerá       ","oleremos    ","olerán      ","olerán      ",
					   "olía       ","olías      ","olía       ","olíamos    ","olían      ","olían      ",
					   "olería      ","olerías   ","olería     ","oleríamos    ","olerian    ","olerian    "}; 
					   
enBasePronombres OlerSubj =   {"huela        ","huelas       ","huela        ","olamos       ","huelan       ","huelan       ",
							   "oliera        ","olieras       ","oliera        ","oliéramos     ","olieran       ","olieran       ",
							   "oliere      ","olieres   ","olieres    ","oliéremos    ","olieren    ","olieren    "};   
					   
enBasePronombres Caber = {"quepo         ","cabes         ","cabe          ","cabemos       ","caben         ","caben         ",
						"cupe         ","cupiste      ","cupo         ","cupimos      ","cupieron     ","cupieron     ",
					   "cabré         ","cabrás        ","cabrá         ","cabremos      ","cabrán        ","cabrán        ",
					   "cabia        ","cabias       ","cabia        ","cabiamos     ","cabian       ","cabian       ",
					   "cabría      ","cabrías   ","cabría     ","cabriamos    ","cabrían    ","cabrían    "}; 
					   
enBasePronombres CaberSubj =   {"quepa         ","quepas        ","quepa         ","quepamos      ","quepan        ","quepan        ",
							   "cupiera        ","cupieras       ","cupiera        ","cupiéramos     ","cupieran       ","cupieran       ",
							   "cupiere     ","cupieres   ","cupiere    ","cupiéremos    ","cupieren    ","cupieren    "};
					   
enBasePronombres Errar = {"yerro         ","yerras        ","yerra         ","erramos       ","yerran        ","yerran        ",
						"erré         ","erraste      ","erró         ","erramos      ","erraron      ","erraron      ",
					   "erráre        ","errarás       ","errará        ","erraremos     ","errarán       ","errarán       ",
					   "erraba       ","errabas     ","erraba       ","errábamos    ","erraban      ","erraban      ",
					   "erraría     ","errarías  ","erraría    ","erraríamos   ","errarían   ","errarían   "}; 
					   
enBasePronombres ErrarSubj =   {"yerre          ","yerres         ","yerre          ","erramos        ","yerren         ","yerren         ",
							   "errara          ","erraras         ","errara          ","erráramos       ","erraran         ","erraran         ",
							   "errare     ","errares   ","errare    ","erráremos    ","erraren    ","erraren    "};  
					   
enBasePronombres Soltar = {"suelto       ","sueltas      ","suelta       ","soltamos     ","sueltan      ","sueltan      ",
						"solté      ","soltaste   ","soltó      ","soltamos   ","soltaron   ","soltaron   ",
					   "soltaré      ","soltarás     ","soltará      ","soltaremos   ","soltarán     ","soltarán     ",
					   "soltaba    ","soltabas   ","soltaba    ","soltabamos  ","soltaban    ","soltaban    ",
					   "soltaría    ","soltarías ","soltaría    ","soltaríamos  ","soltarían  ","soltarían  "}; 
					   
enBasePronombres SoltarSubj =   {"suelte       ","sueltes      ","suelte       ","soltemos     ","suelten      ","suelten      ",
							   "soltara       ","soltaras      ","soltara       ","soltaramos    ","soltaran      ","soltaran      ",
							   "soltare     ","soltares   ","soltare    ","soltáremos    ","soltaren    ","soltaren    "};   
							   
enBasePronombres Sonar = {"sueño        ","sueñas       ","sueña        ","soñamos      ","sueñan       ","sueñan       ",
						"soñé        ","soñaste     ","soñó        ","soñamos     ","soñaron     ","soñaron     ",
					   "soñaré       ","soñarás      ","soñará       ","soñaremos    ","soñarán      ","soñarán      ",
					   "soñaba       ","soñabas      ","soñaba       ","soñabamos    ","soñaban      ","soñaban      ",
					   "soñaría    ","soñarías ","soñaría    ","soñaríamos  ","soñarían  ","soñarían  "}; 
					   
enBasePronombres SonarSubj =   {"sueñe        ","sueñes       ","sueñe        ","soñemos      ","sueñen       ","sueñen       ",
							   "soñara        ","soñaras       ","soñara        ","soñaramos     ","soñaran       ","soñaran       ",
							   "soñare     ","soñares   ","soñare    ","soñáremos    ","soñaren    ","soñaren    "}; 

enBasePronombres Servir = {"sirvo        ","sirves       ","sirve        ","servimos     ","sirven       ","sirven       ",
						"serví        ","serviste     ","sirvió       ","servimos     ","sirvieron    ","sirvieron    ",
					   "serviré      ","serviras     ","servira      ","serviremos   ","serviran     ","serviran     ",
					   "servía      ","servías     ","servía      ","servíamos   ","servían     ","servían     ",
					   "serviría    ","servirías ","serviría     ","serviriamos  ","servirían  ","servirían  "}; 
					   
enBasePronombres ServirSubj =   {"sirva        ","sirvas       ","sirva        ","sirvamos     ","sirvan       ","sirvan       ",
							   "sirviera       ","sirvieras      ","sirviera       ","sirvieramos    ","sirvieran      ","sirveran       ",
							   "sirviere     ","sirvieres   ","sirviere     ","sirvierémos  ","sirvieren   ","sirveren   "};  
					
enBasePronombres Aislar = {"aislo        ","aislas       ","aisla        ","aislamos     ","aislan       ","aislan       ",
						"aislé       ","aislaste    ","aislo       ","aislamos    ","aislaron    ","aislaron    ",
					   "aislaré      ","aislarás     ","aislará      ","aislaremos   ","aislaran     ","aislaran     ",
					   "aislaba       ","aislabas      ","aislaba       ","aislábamos    ","aislaban      ","aislaban      ",
					   "aislaría    ","aislarías ","aislarías     ","aislaríamos  ","aislarían  ","aislarían  "}; 
					   
enBasePronombres AislarSubj =   {"aisle        ","aisles       ","aisle        ","aislemos     ","aislemos     ","aislemos     ",
							   "aislara      ","aislaras     ","aislaras     ","aislaramos   ","aislaran     ","aislaran     ",
							   "aislare     ","aislares   ","aislare    ","aislaremos  ","aislaren   ","aislaren   "};                                                                

enBasePronombres Pronombres = {"yo", "tú", "él", "nosotros", "ustedes", "ellos"};                                                                             

int conjugacionRegularAR(FILE *archivo, char raizVerbo[]);
int conjugacionRegularER(FILE *archivo, char raizVerbo[]);
int conjugacionRegularIR(FILE *archivo, char raizVerbo[]);
int conjugacionCompuesta(FILE *archivo, char raizVerbo[], char ter_comp[]);
int conjugacionCompuestaSubj(FILE *archivo, char raizVerbo[], char ter_comp[]);
int conjugacionSubjuntivaAR(FILE *archivo, char raizVerbo[]);
int conjugacionSubjuntivaER(FILE *archivo, char raizVerbo[]);
int conjugacionSubjuntivaIR(FILE *archivo, char raizVerbo[]);

int conjugacionCompuestaIrregular(FILE *archivo, char raizVerbo[], char ter_comp[]);
int conjugacionCompuestaSubjIrregular(FILE *archivo, char raizVerbo[], char ter_comp[]);

int conjugacionSOler(FILE *archivo, char raizVerbo[]);
int conjugacionOler(FILE *archivo, char raizVerbo[]);                                                                     

int conjugacionSCaber(FILE *archivo, char raizVerbo[]);
int conjugacionCaber(FILE *archivo, char raizVerbo[]);

int conjugacionSErrar(FILE *archivo, char raizVerbo[]);
int conjugacionErrar(FILE *archivo, char raizVerbo[]);

int conjugacionSOSonar(FILE *archivo, char raizVerbo[]);
int conjugacionSonar(FILE *archivo, char raizVerbo[]);

int conjugacionSServir(FILE *archivo, char raizVerbo[]);
int conjugacionServir(FILE *archivo, char raizVerbo[]);

int conjugacionSAislar(FILE *archivo, char raizVerbo[]);
int conjugacionAislar(FILE *archivo, char raizVerbo[]);

int conjugacionSSoltar(FILE *archivo, char raizVerbo[]);
int conjugacionSoltar(FILE *archivo, char raizVerbo[]);


int main(int argc, char *argv[])
{                               
  FILE *miArchivo;              
  char buffer[128], ter, ter_comp[3] = "ado", v[5] = "oler";             
  int lbuffer, i;                
	
  setlocale(LC_ALL,"");
	
  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }                                                                    
  printf("Escriba un verbo regular o un verbo irregular de la siguiente lista: ");
  printf("\n- oler");
  printf("\n- caber");
  printf("\n- errar");
  printf("\n- soltar");
  printf("\n- soñar (escribir sonar)");
  printf("\n- servir");
  printf("\n- aislar");
  printf("\n");
  printf("\n");
  scanf("%s", buffer);
  

		     	
		if (strcmp(buffer,"caber")==0){
			conjugacionCaber(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"cabido");
			conjugacionSCaber(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"cabido");
			printf("\n");
		}else if(strcmp(buffer,"oler")==0){
			conjugacionOler(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"olido");
			conjugacionSOler(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"olido");
			printf("\n");
			printf("Percibir los olores. \n");
			printf("\n");
		}else if(strcmp(buffer,"errar")==0){
			conjugacionErrar(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"errado");
			conjugacionSErrar(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"errado");
			printf("\n");
			printf("No acertar algo. \n");
			printf("\n");
		}else if(strcmp(buffer,"sonar")==0){
			conjugacionSonar(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"soñado");
			conjugacionSSonar(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"soñado");
			printf("\n");
			printf("Representarse en la fantasía imágenes o sucesos mientras se duerme \n");
			printf("\n");
		}else if(strcmp(buffer,"servir")==0){
			conjugacionServir(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"servido");
			conjugacionSServir(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"servido");
			printf("\n");
			printf("Estar al servicio de alguien. \n");
			printf("\n");
		}else if(strcmp(buffer,"aislar")==0){
			conjugacionAislar(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"aislado");
			conjugacionSAislar(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"aislado");
			printf("\n");
			printf("Dejar algo solo y separado de otras cosas. \n");
			printf("\n");
		}else if(strcmp(buffer,"soltar")==0){
			conjugacionSoltar(miArchivo, buffer);
			conjugacionCompuestaIrregular(miArchivo,buffer,"soltado");
			conjugacionSSoltar(miArchivo, buffer);
			conjugacionCompuestaSubjIrregular(miArchivo,buffer,"soltado");
			printf("\n");
			printf("Desatar o desceñir. \n");
			printf("\n");
		}else{
    	
	  	lbuffer = strlen(buffer);
	  ter = buffer[lbuffer-2];
	                               
	  buffer[lbuffer-2]= '\0';    
	
	  //printf("Por conjugar verbo\n");
	  	
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
	            conjugacionSubjuntivaER(miArchivo, buffer);
	            conjugacionCompuestaSubj(miArchivo,buffer,"ido");
	            break;
	
	        case 'i':
	            conjugacionRegularIR(miArchivo, buffer);
	            conjugacionCompuesta(miArchivo,buffer,"ido");
	            conjugacionSubjuntivaIR(miArchivo, buffer);
	            conjugacionCompuestaSubj(miArchivo,buffer,"ido");
	            break;
	
	    }
  	
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
		sprintf(formato, "%%%ds%%s%%%ds ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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
		sprintf(formato, "%%%ds%%s%%%ds ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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


int conjugacionSubjuntivaER(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSubjER[tiempo]); 
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
		sprintf(formato, "%%%ds%%s%%%ds ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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


int conjugacionSubjuntivaIR(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSubjIR[tiempo]); 
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
		sprintf(formato, "%%%ds%%s%%%ds       ", centrado, centrado+2);
	    fprintf(archivo, formato, "     Ante", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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
		sprintf(formato, "%%%ds%%s%%%ds            ", centrado, centrado+2);
	    fprintf(archivo, formato, "     Ante", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
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

int conjugacionCompuestaIrregular(FILE *archivo, char raizVerbo[],  char ter_comp[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=4;tiempo++)   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds       ", centrado, centrado+2);
	    fprintf(archivo, formato, "    Ante", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s        ", Pronombres[persona], 
    		        DesidenciaCompuesta[tiempo], ter_comp);
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionCompuestaSubjIrregular(FILE *archivo, char raizVerbo[],  char ter_comp[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

  for(tiempo=0;tiempo<=2;tiempo++)   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds          ", centrado, centrado+2);
	    fprintf(archivo, formato, "     Ante", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s        ", Pronombres[persona], 
    		        DesidenciaCompuestaSubj[tiempo], ter_comp);
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionSOler(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Oler[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionOler(FILE *archivo, char raizVerbo[])                                                                           
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
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Oler[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSCaber(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], CaberSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionCaber(FILE *archivo, char raizVerbo[])                                                                           
{                                               
                       
 					            
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

   fprintf(archivo,"Dicho de una persona o de una cosa: Poder contenerse dentro de algo. \n");
   fprintf(archivo, "\n"); 

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Caber[tiempo]); 
        fprintf(archivo, "\n");
   }                 
                                            
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSErrar(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], ErrarSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionErrar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

	fprintf(archivo,"Cometer un error o equivocarse en cierta cosa. \n");
    fprintf(archivo, "\n"); 

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Errar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSSoltar(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], SoltarSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSoltar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

	fprintf(archivo,"Hacer que algo o alguien deje de estar asido, atado o retenido. \n");
    fprintf(archivo, "\n"); 


  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Soltar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSSonar(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], SonarSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionSonar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

	fprintf(archivo,"Representarse en la fantasía imágenes o sucesos mientras se duerme. \n");
    fprintf(archivo, "\n"); 

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Sonar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionSServir(FILE *archivo, char raizVerbo[])                                                                           
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
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], ServirSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionServir(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

	fprintf(archivo,"Ser [un utensilio] a propósito para el fin que se expresa. \n");
    fprintf(archivo, "\n"); 

  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Servir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}

int conjugacionSAislar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+2;

	fprintf(archivo,"Hacer que una persona o una cosa quede sola, separada de otras. \n");
    fprintf(archivo, "\n"); 

  for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds  ", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], AislarSubj[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}


int conjugacionAislar(FILE *archivo, char raizVerbo[])                                                                           
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
	  fprintf(archivo,"\n\n");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s", Pronombres[persona], Aislar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           
  fprintf(archivo, "\n");

  return 0;  
}