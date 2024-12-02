#include <stdio.h>

int main () {
  int matriz[3][3]={};
  int soma=0;

  printf("Insira os elementos da matriz 3x3:\n");

  for(int linha=0; linha<3; linha++){
    for(int coluna=0; coluna<3; coluna++){
      printf("\nLin. [%d], Col. [%d]: ", linha, coluna);
      scanf("%d", &matriz[linha][coluna]);
      soma = soma + matriz[linha][coluna];
    }
  }

  printf("\n\nMatriz:\n");
  printf("\tC1\tC2\tC3\n");

  for(int linha=0; linha<3; linha++){
    printf("L%d", linha);
    for(int coluna=0; coluna<3; coluna++){
    printf("\t%d", matriz[linha][coluna]); 
    }
    printf("\n");
  }

  printf("\n\nSoma dos elementos da matriz: ");
  printf("%d", soma);

  return 0;  
}
