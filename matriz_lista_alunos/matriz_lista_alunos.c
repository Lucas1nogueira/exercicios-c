#include <stdio.h>

int main () {
  int linhas;
  char nome[30];
  
  printf("Insira o numero de alunos: ");
  scanf("%d", &linhas);
  getchar();
  
  char alunos[linhas][30];
  
  for(int contador=0; contador<linhas; contador++){
    int contador2=0;
    printf("\nInsira o nome do aluno %d: ", contador);
    scanf("%[^\n]", nome);
    getchar();
    while(nome[contador2]!='\0'){
      alunos[contador][contador2]=nome[contador2];
      contador2++;
    }
  }
  
  for(int contador=0; contador<linhas; contador++){
    printf("\nAluno %d: %s", contador, alunos[contador]);
  }
  
  return 0;
}
