/*Faça um programa que leia dois vetores de 10 posições e calcule outro vetor contendo, nas posicoes impares os valores do primeiro e nas posicoes pares os valores do segundo.*/

#include <stdio.h>

int main(void) {
  int vet1[10];
  int vet2[10];
  int vet3[20];

  printf("Insira 10 numeros para o vetor 1:\n");
  for(int i=0; i<10; i++){
    printf("Primeiro vetor[%d]: ", i);
    scanf("%d", &vet1[i]);
  }

  printf("\nInsira 10 numeros para vetor 2:\n");
  for(int i=0; i<10; i++){
    printf("Segundo vetor[%d]: ", i);
    scanf("%d", &vet2[i]);
  }

  for(int i=1; i<=10; i++){
    if(i%2!=0)
      vet3[i-1]=vet1[i-1];
    else
      vet3[i-1]=vet2[i-1];
  }

  printf("\nResultado do terceiro vetor:\n");
  for(int i=0; i<10; i++){
    printf("Terceiro vetor[%d]: %d\n", i, vet3[i]);
  }

  return 0;
}