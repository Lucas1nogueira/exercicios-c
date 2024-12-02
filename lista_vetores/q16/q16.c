#include <stdio.h>

int main () {
  int vet1[5];
  int vet2[5];
  
  printf("Insira 5 valores inteiros no vetor 1:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Valor %d: ", contador+1);
    scanf("%d", &vet1[contador]);
  }
  
  printf("\nInsira 5 valores inteiros no vetor 2:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Valor %d: ", contador+1);
    scanf("%d", &vet2[contador]);
  }
  
  printf("\n\n--- Resultados ---\n");
  
  printf("\nCalculos de soma:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Valor %d em vetor 1 e vetor 2 -> %d + %d = %d\n",
    contador+1, vet1[contador], vet2[contador],
    vet1[contador]+vet2[contador]);
  }
  
  printf("\nCalculos de diferenca:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Valor %d em vetor 1 e vetor 2 -> %d - %d = %d\n",
    contador+1, vet1[contador], vet2[contador],
    vet1[contador]-vet2[contador]);
  }
  
  printf("\nCalculos de produto:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Valor %d em vetor 1 e vetor 2 -> %d * %d = %d\n",
    contador+1, vet1[contador], vet2[contador],
    vet1[contador]*vet2[contador]);
  }
  
  printf("\nCalculos de divisao:\n");
  
  for(int contador=0; contador<5; contador++){
    float valor1=0, valor2=0;
    valor1=vet1[contador];
    valor2=vet2[contador];
    printf("Valor %d em vetor 1 e vetor 2 -> %d / %d = %.2f\n",
    contador+1, vet1[contador], vet2[contador],
    valor1/valor2);
  }
  
  return 0;
}
