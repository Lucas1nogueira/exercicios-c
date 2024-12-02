/*Programa de calculadora cientifica utilizando vetores*/

#include <stdio.h>

int main(void) {
  float numeros[10] = {};
  char operacoes[10] = {};
  float resultado=0;
  int tamanho=0;

  printf("\t:::CALCULADORA CIENTIFICA:::");
  
  printf("\n\nInsira um valor seguido de enter. Logo depois digite um sinal de operacao ('+' ou '-'), seguido de enter e o(s) proximo(s) valores, sempre inserido enter apos o digito, inserindo o sinal de operacao '=' para exibir o resultado final.");

  printf("\n- Nao insira espacos entre os digitos!");
  printf("\n- Este programa suporta calculos de ate 10 numeros.");
  printf("\n- Nao esqueca do sinal '=' ao terminar.\n\n");

  printf("Insira seu calculo:\n");

  for(int i=0; i<10; i++){
    scanf("%f", &numeros[i]); getchar();
    scanf("%c", &operacoes[i]); getchar();
    tamanho++;
    if(operacoes[i]=='=')
      i=9;
  }

  resultado=numeros[0];

  for(int i=0; i<tamanho; i++){
    if(operacoes[i]=='+')
      resultado=resultado+numeros[i+1];
    else{
      if(operacoes[i]=='-')
      resultado=resultado-numeros[i+1];
    }
  }

  printf("%.4f", resultado);

  return 0;
}