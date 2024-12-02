#include <stdio.h>

int main () {
  int idade=0;
  int quantidade_superior_50anos_inferior_60kgs=0;
  int quantidade_inferior_150cm=0;
  int olho_azul=0, ruivos_sem_olho_azul=0;
  float peso=0, altura=0;
  int soma_menor_150cm=0;
  float media_menor_150cm=0;
  float percentagem_olhos_azuis=0;
  char olho, cabelo;

  for(int contador=1; contador<=2; contador++) {
    printf("\nInsira a idade da pessoa: ");
    scanf("%d", &idade);

    printf("\nInsira agora o peso: ");
    scanf("%f", &peso);

    if(idade>50 && peso<60)
    quantidade_superior_50anos_inferior_60kgs++;

    printf("\nInsira a altura em metros com ponto: ");
    scanf("%f", &altura);

    if(altura < 1.50)
    quantidade_inferior_150cm++;
    soma_menor_150cm = soma_menor_150cm + idade;

    printf("\nEscolha a cor dos olhos:");
    printf("\nA-azul.\nP-preto.\nV-verde.\nC-castanho.\n");
    scanf("%c", &olho);
    if(olho=='A')
    ++olho_azul;
    getchar();

    printf("\nEscolha a cor do cabelo:");
    printf("\nP-preto.\nC-castanho.\nL-louro.\nR-ruivo.\n");
    scanf("%c", &cabelo);
    if(olho!='A' && cabelo=='R')
    ruivos_sem_olho_azul+=1.0;
    getchar();
  }

  printf("\n\nQuantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos: ");
  printf("%d", quantidade_superior_50anos_inferior_60kgs);

  media_menor_150cm = (soma_menor_150cm / quantidade_inferior_150cm);
  printf("\nMedia das idades das pessoas com altura inferior a 1.50: ");
  printf("%.2f", media_menor_150cm);

  percentagem_olhos_azuis = (olho_azul/2.00);
  printf("\nPercentagem de pessoas com olhos azuis: ");
  printf("%.2f", percentagem_olhos_azuis*100.00);

  printf("\nA quantidade de pessoas ruivas sem olhos azuis: ");
  printf("%d", ruivos_sem_olho_azul);

  return 0;
}
