#include <stdio.h>

int main () {
  int numero;

  printf("Insira o numero de elementos a serem armazenados no vetor: ");
  scanf("%d", &numero);

  int elemento[numero];
  int frequencia[numero];

  printf("\nInsira %d elementos na matriz:\n", numero);

  for(int contador=0; contador<numero; contador++) {
    printf("Elemento - %d: ", contador);
    scanf("%d", &elemento[contador]);
  }

  for(int contador=numero-1; contador>=0; contador--) {
    for(int contador2=numero-1; contador2>=0; contador2--) {
      if(elemento[contador]==elemento[contador2])
      frequencia[contador]+=1;
    }
  }

  printf("\nFrequencia de todos os elementos do vetor:\n\n");

  for(int contador=0; contador<numero; contador++) {
    printf("%d ocorre %d vez(es).\n", elemento[contador], frequencia[contador]);
  }

  return 0;
}
