#include <stdio.h>

int primo (int num);

int main (){
  int numero;

  printf("Digite um numero positivo: ");
  scanf("%d", &numero);

  primo(numero);

  return 0;
}

int primo (int num){
  int j=0;

  for(int i=num; i>0; i--){
    if(num%i==0)
      j++;
  }

  if(j==2)
    printf("O numero %d e primo.", num);
  else
    printf("O numero %d nao e primo.", num);

  return 0;
}