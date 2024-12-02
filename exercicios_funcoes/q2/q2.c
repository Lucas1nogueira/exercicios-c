#include <stdio.h>

int perfeito (int num);

int main (){
  int numero, resultado;

  printf("Insira um numero natural: ");
  scanf("%d", &numero);

  resultado=perfeito(numero);

  printf("%d", resultado);

  return 0;
}

int perfeito (int num){
  int soma=0;

  for(int i=num; i>0; i--){
    if(num%i==0)
      soma=soma+i;
  }

  soma=soma-num;

  if(soma==num)
    return(1);
  else
    return(0);
}