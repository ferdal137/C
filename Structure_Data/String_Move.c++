#include<stdio.h>
#include<string.h> /*para funcionalidad de manejo de cadenas de caracteres*/
#include<windows.h> /*para la funcion llamada Sleep que hace una pausa*/

using namespace std;

int main()
{
  int l, i, j;
  char texto[1024], cadena[1024];

  cout<<"antes de la llamada al banner...\nEscriba una cadena:";
  scanf("%[^\n]%*c", cadena);

  sprintf(texto, "%30sHola %s!!!", " ", cadena);
  cout<<"La cadena generada es: <<%s>>\n", texto;
  l = strlen(texto);
  for(j=0; j<1000; j++)
    for(i=0; i<l; i++){
      cout<<texto; 
      fflush(stdout); /*se encuentra en stdio.h, sirve para escribir lo que tenga el buffer a la salida estandar*/
      sprintf(texto, "%s%c", &(texto[1]), texto[0]);
      Sleep(100); /*el tiempo de espera se mide en milisegundos, asi 100 indica una decima de segundo*/
    }

 return 0;

}