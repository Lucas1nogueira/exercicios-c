#include <stdio.h>

int idade (int anos, int meses, int dias);

int main (){
  int calculo=0, anos, meses, dias;

  printf("Insira a sua idade:\n");

  printf("Anos:");
  scanf("%d", &anos);

  printf("Meses:");
  scanf("%d", &meses);

  printf("Dias:");
  scanf("%d", &dias);

  calculo=idade(anos,meses,dias);

  printf("Sua idade corresponde a %d dias.", calculo);

  return 0;
}

int idade (int anos, int meses, int dias){
  int calculo=0;

  calculo=(anos*365)+(meses*30)+(dias);

  return (calculo);
}