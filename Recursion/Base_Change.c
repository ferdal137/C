#include<stdio.h>
#include<stdlib.h>

void CB (int n, int b);

int main(int argc[], char *argc[]){
	
	
	
	
	return 0;
}

void CB (int n, int b){
	int aux;
	
	if(n==0) return;
	CD(n/b,b);
	aux = n%b;
	if(aux<10) print("%d", aux);
	else printf();
	print("%d", aux);
}