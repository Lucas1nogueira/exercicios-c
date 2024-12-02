#include <stdio.h>

int main(void) {
  int valor;
  int conta_negativos=0;
  int qtd_entradas=0;

  while(qtd_entradas < 5){//repete enquanto qtd_entradas for menor que 5
    printf("Digite um valor..: ");
    scanf("%d", &valor);
    if(valor <0)
      conta_negativos = conta_negativos+1;//contando o numero de negativos

    qtd_entradas++;
  }

  printf("Você informou %d numeros negativos\n", conta_negativos);
  return 0;
}
