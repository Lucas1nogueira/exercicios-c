#include <stdio.h>

int main () {
  float salarios[10];
  int maior=0;
  
  printf("Insira 10 salarios:\n");
  
  for(int contador=0; contador<10; contador++){
    printf("Salario %d: ", contador+1);
    scanf("%f", &salarios[contador]);
  }
  
  for(int contador=0; contador<10; contador++){
    if(salarios[contador]>salarios[maior])
    maior=contador;
  }
  
  printf("\nO maior salario armazenado e: %.2f", salarios[maior]);
  
  return 0;
}
