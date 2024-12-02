#include <stdio.h>

int quadrado (int num);

int main (){
  int numero;

  printf("Digite um inteiro: ");
  scanf("%d", &numero);

  printf("O quadrado de %d e igual a: ", numero);

  printf("%d", quadrado(numero));

  return 0;
}

int quadrado (int num){
  return (num*num);
}