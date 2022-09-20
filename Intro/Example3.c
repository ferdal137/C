#include <stdio.h>

int main(int argc, char *argv[])
{
  int a, inva;

  printf("escriba un entero:");
  scanf("%d", &a);

  a = ((a%5)+5)%5;
  inva = a==2?3:a==3?2:a==4?4:a;

  printf("el inverso modulo 5 de %d es %d\n", a, inva);


  return 0;
}