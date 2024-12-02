#include <stdio.h>

int main () {
  int elemento[10] = {};
  int num_substituir, posicao_substituir, reserva, fim=0;
  
  printf("Insira ate 10 elementos para vetor em ordem crescente:\n");
  
  for(int contador=0; contador<10; contador++){
    printf("\nElemento %d: ", contador);
    int numero;
    scanf("%d", &numero);
    if(numero==-1) break;
    elemento[contador] = numero;
    fim++;
  }
  
  printf("\nInsira o novo valor que voce quer colocar na matriz: ");
  scanf("%d", &num_substituir);
  printf("\nInsira a posicao em que este novo numero substituira: ");
  scanf("%d", &posicao_substituir);
  
  for(int contador1=0; contador1<fim; contador1++){
    for(int contador2=0; contador2<fim; contador2++){
      if(elemento[contador1]<elemento[contador2]){
        reserva = elemento[contador1];
        elemento[contador1] = elemento[contador2];
        elemento[contador2] = reserva;
      }
    }
  }
  
  printf("\n\nLista com valores antigos em ordem crescente:\n");
  
  for(int contador=0; contador<fim; contador++){
  printf("%d  ", elemento[contador]);
  }
  
  elemento[posicao_substituir] = num_substituir;
  
  printf("\n\nLista com novo valor inserido:\n");
  
  for(int contador=0; contador<fim; contador++){
    printf("%d  ", elemento[contador]);
  }
  
  return 0;
}
