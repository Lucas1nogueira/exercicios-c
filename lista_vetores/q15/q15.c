#include <stdio.h>

int main () {
  int tamanho;
  double soma=0, media=0;
  
  printf("Insira a quantidade de valores reais a serem lidos: ");
  scanf("%d", &tamanho);
  
  double valores[tamanho];
  
  for(int contador=0; contador<tamanho; contador++){
    printf("Valor %d: ", contador+1);
    scanf("%lf", &valores[contador]);
    soma=soma+valores[contador];
  }
  
  media=soma/tamanho;
  
  printf("\nA media aritmetica dos valores informados e: %.2f", media);
  
  return 0;
}
