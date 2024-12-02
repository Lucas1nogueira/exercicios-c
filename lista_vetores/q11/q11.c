#include <stdio.h>

int main () {
  int tamanho;
  
  printf("Insira o numero de elementos para o vetor: ");
  scanf("%d", &tamanho);
  
  int vetor[tamanho];
  
  printf("Insira %d elementos no vetor:\n", tamanho);
  
  for(int contador=0; contador<tamanho; contador++){
    printf("Elemento %d: ", contador);
    scanf("%d", &vetor[contador]);
  }
  
  printf("\n\nOs elementos pares sao:\n");
  
  for(int contador=0; contador<tamanho; contador++){
    if(vetor[contador]%2==0)
    printf("%d  ", vetor[contador]);
  }
  
  printf("\n\nOs elementos impares sao:\n");
  
  for(int contador=0; contador<tamanho; contador++){
    if(vetor[contador]%2!=0)
    printf("%d  ", vetor[contador]);
  }
  
  return 0;
}
