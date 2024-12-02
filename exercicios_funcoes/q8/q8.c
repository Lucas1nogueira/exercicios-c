#include <stdio.h>

char parimpar (int num);

int main (){
  int numero;

  printf("Insira um numero: ");
  scanf("%d", &numero);

  parimpar(numero);

  return 0;
}

char parimpar (int num){
  if(num%2==0)
    printf("O numero digitado e PAR.");
  else
    printf("O numero digitado e IMPAR.");
  
  return 0;
}