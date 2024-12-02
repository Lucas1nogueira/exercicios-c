#include <stdio.h>

int numperfeitos (int menor, int maior);

int main (){
  int menor, maior;

  printf("Insira o intervalo para pesquisa dos perfeitos:\n");
  
  printf("Menor numero: ");
  scanf("%d", &menor);

  printf("Maior numero: ");
  scanf("%d", &maior);

  printf("Os perfeitos entre %d e %d sao:\n", menor,maior);

  numperfeitos(menor,maior);

  return 0;
}

int numperfeitos (int menor, int maior){
  int soma=0;

  for(int j=menor; j>0; j--){
    if(menor%j==0)
      soma=soma+j;
  }

  soma=soma-menor;

  if(soma==menor)
    printf("%d  ", menor);

  if(menor!=maior)
  numperfeitos(menor+1,maior);

  return 0;
}