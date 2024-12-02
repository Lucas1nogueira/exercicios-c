#include <stdio.h>

int main () {
  int tamanho, pesquisa;
  
  printf("Insira o tamanho da matriz: ");
  scanf("%d", &tamanho);
  
  int elemento[tamanho];
  
  printf("Insira o(s) %d elemento(s) na matriz:\n", tamanho);
  
  for(int contador=0; contador<tamanho; contador++){
    printf("\nElemento %d: ", contador);
    scanf("%d", &elemento[contador]);
  }
  
  printf("\n\nInsira o elemento a ser pesquisado nesta matriz: ");
  scanf("%d", &pesquisa);
  
  for(int contador=0; contador<tamanho; contador++){
    if(elemento[contador]==pesquisa)
    printf("O elemento desejado esta na posicao [%d] do vetor.", contador);
  }
  
  return 0;
}
