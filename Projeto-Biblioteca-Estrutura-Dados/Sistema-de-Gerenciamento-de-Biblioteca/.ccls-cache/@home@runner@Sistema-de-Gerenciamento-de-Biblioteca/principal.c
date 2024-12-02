#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "biblioteca.h"

int main(void) {
  FILE *p_arquivo;
  
  int opcao = 1, qtd_emp=0;

  p_arquivo = fopen("dados.txt", "a+");

  if(p_arquivo==NULL){
    printf("\n(!) Erro: Falha na abertura do arquivo.");
    exit(1);
  }

  introducao();
  
  while(opcao != 0){
    exibir_menu();

    printf("\n\n\nDigite uma opcao: ");
    scanf("%d", &opcao);
    
    switch(opcao){
      case 1:
        qtd_emp = ler_qtd_emp(p_arquivo);
        realizar_emprestimo(p_arquivo, &qtd_emp);
        break;
      case 2:
        menu_consulta(p_arquivo);
        break;
      case 3:
        listar_emprestimos(p_arquivo);
        break;
      case 4:
        editar_dados_emprestimo(p_arquivo);
        p_arquivo = fopen("dados.txt", "a+");
        break;
      case 5:
        excluir_emprestimo(p_arquivo);
        p_arquivo = fopen("dados.txt", "a+");
        break;
      case 6:
        livros(p_arquivo);
        break;
      case 0:
        sair(p_arquivo);
        break;
      default:
        printf("\n\nOpcao invalida. Retornando ao menu...\n\n\n");
        sleep(2);
        break;
    }
  }
  
  return 0;
}