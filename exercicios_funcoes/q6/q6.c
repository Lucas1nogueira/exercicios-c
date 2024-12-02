#include <stdio.h>

int divisores (int num);

int main (){
  int numero;

  printf("Insira um numero inteiro e positivo: ");
  scanf("%d", &numero);

  printf("O numero de divisores deste numero e de: ");

  printf("%d", divisores(numero));
}

int divisores (int num){
  int n_divisores=0;

  for(int i=num; i>0; i--){
    if(num%i==0)
      n_divisores++;
  }

  return (n_divisores);
}