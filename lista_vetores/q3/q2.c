#include <stdio.h>

int main () {
  int elemento[10] = {};
  int reserva;
  
  printf("Insira 10 elementos no vetor:\n");
  
  for(int contador=0; contador<10; contador++){
    printf("\nElemento %d: ", contador);
    scanf("%d", &elemento[contador]);
  }
  
  for(int contador1=0; contador1<10; contador1++){
    for(int contador2=0; contador2<10; contador2++){
      if(elemento[contador1]<elemento[contador2]){
        reserva = elemento[contador1];
        elemento[contador1] = elemento[contador2];
        elemento[contador2] = reserva;
      }
    }
  }
  
  printf("\n\nElementos em ordem crescente:\n");
  
  for(int contador=0; contador<10; contador++){
    printf("%d  ", elemento[contador]);
  }
  
  return 0;
}
