#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int codigo;
  char data_emp[12];
  char data_ent[12];
}Emprestimo;

typedef struct{
  char isbn[15];
  char nome_livro[30];
}Livro;

typedef struct{
  int matricula;
  char nome_aluno[30];
}Aluno;

typedef struct{
  Emprestimo emp;
  Livro liv;
  Aluno aln;
}Dados;

int ler_qtd_emp(FILE *p_arquivo);
void animacao();
void exibir_menu();
void realizar_emprestimo(FILE *p_arquivo, int *p_posicao);
void menu_consulta(FILE *p_arquivo);
void consulta_codigo(FILE *p_arquivo);
void consulta_titulo(FILE *p_arquivo);
void consulta_nome_aluno(FILE *p_arquivo);
void listar_emprestimos(FILE *p_arquivo);
void editar_dados_emprestimo(FILE *p_arquivo);
void excluir_emprestimo(FILE *p_arquivo);
void livros(FILE *p_arquivo);