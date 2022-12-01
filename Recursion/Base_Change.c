#include<stdio.h>
#include<stdlib.h>

void CB (int n, int b);

int main(int argc[], char *argc[]){
	
	int n, b;
    printf("Digite dos enteros");
    scanf("%d%d",&n,&b);
	CB(n,b);
	
	return 0;
}

void CB (int n, int b){
	int aux;
	
	if(n==0) return;
	CD(n/b,b);
	aux = n%b;
	if(aux<10) print("%d", aux);
	else printf("%c".'A'+aux-10);
	print("%d", aux);
}