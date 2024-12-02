#include <stdio.h>

int main () {
  float salarios[5];
  
  printf("Insira 5 salarios:\n");
  
  for(int contador=0; contador<5; contador++){
    printf("Salario %d: ", contador+1);
    scanf("%f", &salarios[contador]);
    if(salarios[contador]<1000.00)
    salarios[contador]=salarios[contador]*1.10;
  }
  
  printf("\nLista de salarios atualizada:");
  
  for(int contador=0; contador<5; contador++){
    printf("\nSalario %d: R$ %.2f", contador+1, salarios[contador]);
  }
  
  return 0;
}
