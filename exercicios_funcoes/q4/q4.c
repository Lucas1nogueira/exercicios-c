#include <stdio.h>

float pesoideal(char sexo, float altura);

int main (){
  char sexo;
  float altura;

  printf("Insira a opcao referente ao seu sexo:\n");
  printf("M - Masculino\n");
  printf("F - Feminino\n");

  scanf("%c", &sexo);

  printf("\nInsira agora sua altura: ");
  scanf("%f", &altura);

  printf("\nSeu peso ideal e de: %.2f", pesoideal(sexo,altura));

  return 0;
}

float pesoideal(char sexo, float altura){
  float p_ideal=0;

  if(sexo=='M'){
    p_ideal=(72.7*altura)-58.0;
  }else
    p_ideal=(62.1*altura)-44.7;

  return(p_ideal);
}