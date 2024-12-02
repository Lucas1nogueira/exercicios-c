#include <stdio.h>

int main () {
  int vetor[20];
  int pesquisa, falso=0;
  
  printf("Insira 20 elementos no vetor:\n");
  
  for(int contador=0; contador<20; contador++){
    printf("Elemento %d: ", contador);
    scanf("%d", &vetor[contador]);
  }
  
  printf("\n\nInforme o valor a ser pesquisado: ");
  scanf("%d", &pesquisa);
  
  for(int contador=0; contador<20; contador++){
    if(vetor[contador]==pesquisa){
      printf("\nValor %d encontrado na posicao: %d", pesquisa, contador);
      falso++;
    }
  }
  
  if(falso==0)
  printf("\n\nO valor procurado nao foi encontrado.");
  
  return 0;
}
    
