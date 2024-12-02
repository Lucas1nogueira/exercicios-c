#include <stdio.h>

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

void introducao();

void exibir_menu();

void realizar_emprestimo(FILE *p_arquivo, int *p_posicao);

void menu_consulta(FILE *p_arquivo);

void consulta_codigo(FILE *p_arquivo);

void consulta_titulo(FILE *p_arquivo);

void consulta_nome_aluno(FILE *p_arquivo);

void listar_emprestimos(FILE *p_arquivo);

void editar_dados_emprestimo(FILE *p_arquivo);

void excluir_emprestimo(FILE *p_arquivo);

int verifica_data(char string[]);

int verifica_cod_livro(FILE *p_arquivo, char string[]);

int verifica_mat_aluno(FILE *p_arquivo, int matricula);

void livros(FILE *p_arquivo);

void sair(FILE *p_arquivo);

void azul_italico();

void italico();

void vermelho_italico();

void amarelo_negrito();

void sublinhado();

void saida_reset();