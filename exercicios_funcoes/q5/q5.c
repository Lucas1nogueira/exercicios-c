#include <stdio.h>

int fatorial(int num);

int main (){
  int numero;

  printf("Insira um numero inteiro: ");
  scanf("%d", &numero);

  printf("%d", fatorial(numero));

  return 0;
}

int fatorial(int num){
  if(num==0)
    return 1;
  else
    return num*fatorial(num-1);
}