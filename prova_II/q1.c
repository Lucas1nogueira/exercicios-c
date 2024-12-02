/*Faça um programa que leia 20 numeros tipo inteiro, armazenando-o em um vetor e calcular o cubo de cada elemento deste vetor, armazenando o resultado em outro vetor chamado vetor_cubo. Ao final imprima todos os elementos do primeiro vetor, os elementos do vetor de cubos e os elementos do vetor_cubo de forma invertida.*/

#include <stdio.h>

int main(void) {
  int vetor_orig[20];
  int vetor_cubo[20];

  printf("Insira 20 numeros no vetor:\n");

  for(int i=0; i<20; i++){
    printf("Vetor[%d]: ", i);
    scanf("%d", &vetor_orig[i]);
  }

  for(int i=0; i<20; i++){
    vetor_cubo[i]=vetor_orig[i]*vetor_orig[i]; 
  }

  printf("\n\nElementos no vetor original:\n");
  for(int i=0; i<20; i++){
    printf("Posicao %d: %d\n", i, vetor_orig[i]);
  }

  printf("\nElementos no vetor de cubos:\n");
  for(int i=0; i<20; i++){
    printf("Posicao %d: %d\n", i, vetor_cubo[i]);
  }

  printf("\nVetor de cubos invertido:\n");
  for(int i=19; i>=0; i--){
    printf("Posicao %d: %d\n", i, vetor_cubo[i]);
  }

  return 0;
}