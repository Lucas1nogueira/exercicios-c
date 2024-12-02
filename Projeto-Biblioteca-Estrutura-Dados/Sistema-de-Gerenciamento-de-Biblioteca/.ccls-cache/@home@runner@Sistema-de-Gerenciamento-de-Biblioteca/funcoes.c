#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "biblioteca.h"

int ler_qtd_emp(FILE *p_arquivo){
  int linha=0, quantidade=0;
  int j=0, k=0, m=0;
  char *numerais;
  char retorno[50];

  while(fgets(retorno, 50, p_arquivo) != NULL)
    linha++;
  
  rewind(p_arquivo);
  
  if(linha<=1)
    return 1;
  
  for(int i=0; i<(linha-7); i++)
    fgets(retorno, 50, p_arquivo);
  
  while(retorno[j] != ':')
    j++;
  
  j+=2;
  m = j; // m = posicao para o primeiro digito da informacao.
  j++;
  
  while(retorno[j] != '\0'){
    j++;
    k++; // k = quantidade de digitos da informacao.
  }
  
  numerais = (char *) malloc((k+1)*sizeof(char));
  
  for(int l=0; l<k; l++){
    numerais[l] = retorno[m]; // joga a informacao na string de numerais.
    m++;
  }
  
  quantidade = atoi(numerais);
  
  free(numerais);
  rewind(p_arquivo);
  
  return (quantidade+1);
}

void introducao(){
  azul_italico();
  printf("\n >> S I S T E M A");
  printf("\n\tD E    G E R E N C I A M E N T O");
  printf("\n\t\t\tD E    B I B L I O T E C A <<\n");
  saida_reset();
  sleep(1);
}

void exibir_menu(){
  printf("\n||||||||||||  MENU PRINCIPAL  |||||||||||||");
  printf("\n||                                       ||");
  printf("\n||  1) Realizar emprestimo.              ||");
  printf("\n||  2) Consultar emprestimo.             ||");
  printf("\n||  3) Listar emprestimos cadastrados.   ||");
  printf("\n||  4) Editar dados do emprestimo.       ||");
  printf("\n||  5) Excluir emprestimo.               ||");
  printf("\n||  6) Extra: listar livros.             ||");
  printf("\n||  0) Sair do programa.                 ||");
  printf("\n||                                       ||");
  printf("\n|||||||||||||||||||||||||||||||||||||||||||");
}

void realizar_emprestimo(FILE *p_arquivo, int *p_posicao){
  Dados info;
  info.emp.codigo = (*p_posicao);
  int dt_emprestimo=0, dt_entrega=0;
  
  printf("\n\nCodigo do emprestimo: %d (Gerado automaticamente)", info.emp.codigo);
  printf("\nInsira a data do emprestimo [dd/Mm/AAAA]: ");
  scanf("%s", info.emp.data_emp);
  
  if(verifica_data(info.emp.data_emp) == 0)
    return;
  
  dt_emprestimo = verifica_data(info.emp.data_emp);
  
  printf("Insira a data de entrega [dd/Mm/AAAA]: ");
  scanf("%s", info.emp.data_ent);

  if(verifica_data(info.emp.data_ent) == 0)
    return;

  dt_entrega = verifica_data(info.emp.data_ent);
  
  if(dt_emprestimo > dt_entrega){
    vermelho_italico();
    printf("\n\n(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
    saida_reset();
    printf("\nRetornando ao menu...\n\n");
    sleep(1);
    return;
  }
  
  printf("Insira o codigo ISBN do livro: ");
  scanf("%s", info.liv.isbn);

  if(verifica_cod_livro(p_arquivo, info.liv.isbn) == 0)
    return;
  
  printf("Insira o titulo do livro: ");
  scanf(" %[^\n]", info.liv.nome_livro);
  
  printf("Insira o numero da matricula do aluno: ");
  scanf("%d", &info.aln.matricula);

  if(verifica_mat_aluno(p_arquivo, info.aln.matricula) == 0)
    return;
  
  printf("Insira o nome do aluno: ");
  scanf(" %[^\n]", info.aln.nome_aluno);
  
  fprintf(p_arquivo, "#####");
  fprintf(p_arquivo, "\nCodigo de emprestimo: %d", info.emp.codigo);
  fprintf(p_arquivo, "\nData do emprestimo: %s", info.emp.data_emp);
  fprintf(p_arquivo, "\nData de entrega: %s", info.emp.data_ent);
  fprintf(p_arquivo, "\nCodigo ISBN: %s", info.liv.isbn);
  fprintf(p_arquivo, "\nTitulo do livro: %s", info.liv.nome_livro);
  fprintf(p_arquivo, "\nNumero da matricula do aluno: %d", info.aln.matricula);
  fprintf(p_arquivo, "\nNome do aluno: %s\n\n", info.aln.nome_aluno);

  amarelo_negrito();
  printf("\n(!) Emprestimo realizado com sucesso.");
  saida_reset();
  printf("\n\nVoltando ao menu...\n\n");
  
  rewind(p_arquivo);
  sleep(1);
}

void menu_consulta(FILE *p_arquivo){
  int op;
  
  printf("\n");
  printf("\n|||||||||||||||  CONSULTAS  |||||||||||||||");
  printf("\n||                                       ||");
  printf("\n||  1) Consulta por codigo.              ||");
  printf("\n||  2) Consulta por titulo.              ||");
  printf("\n||  3) Consulta por nome do aluno.       ||");
  printf("\n||                                       ||");
  printf("\n|||||||||||||||||||||||||||||||||||||||||||");

  printf("\n\n\nInsira a opcao desejada: ");
  scanf("%d", &op);
  
  switch(op){
    case 1:
      consulta_codigo(p_arquivo);
      break;
    case 2:
      consulta_titulo(p_arquivo);
      break;
    case 3:
      consulta_nome_aluno(p_arquivo);
      break;
    default:
      vermelho_italico();
      printf("\n\n(!) Opcao invalida.\n");
      saida_reset();
      printf("Retornando ao menu...\n\n");
      sleep(1);
      break;
  }
}

void consulta_codigo(FILE *p_arquivo){
  int codigo, erro=1;
  char busca[50];
  char retorno[50];

  printf("\nInsira o codigo a ser pesquisado: ");
  scanf("%d", &codigo);

  sprintf(busca, "Codigo de emprestimo: %d", codigo);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    if(strcmp(busca, retorno) == -10){
      erro--;
      printf("\n\nDADOS ENCONTRADOS: \n\n");
      sublinhado();
      printf("\t%s\n", busca);
      for(int i=0; i<6; i++){
        fgets(retorno, 50, p_arquivo);
        printf("\t%s", retorno);
      }
      saida_reset();
      printf("\n\n");
    }
  }
  if(erro==1){
    vermelho_italico();
    printf("\n\n(!) Emprestimo nao encontrado.\n\n");
    saida_reset();
    sleep(1);
  }

  rewind(p_arquivo);
}

void consulta_titulo(FILE *p_arquivo){
  int cont=0, erro=1;
  char titulo[30];
  char busca[50];
  char retorno[50];
  
  printf("\nInsira o titulo a ser pesquisado: ");
  scanf(" %[^\n]", titulo);

  sprintf(busca, "Titulo do livro: %s", titulo);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10){
      erro--;
      printf("\n\nENCONTRADO NA LINHA %d: \n\n", cont);
      rewind(p_arquivo);
      for(int i=0; i<(cont-5); i++)
        fgets(retorno, 50, p_arquivo);
      sublinhado();
      for(int k=0; k<7; k++){
        fgets(retorno, 50, p_arquivo);
        printf("\t%s", retorno);
      }
      saida_reset();
      printf("\n");
      cont+=2;
    }
  }
  if(erro==1){
    vermelho_italico();
    printf("\n\n(!) Emprestimo nao encontrado.\n\n");
    saida_reset();
    sleep(1);
  }

  rewind(p_arquivo);
}

void consulta_nome_aluno(FILE *p_arquivo){
  int cont=0, erro=1;
  char nome_aln[30];
  char busca[50];
  char retorno[50];
  
  printf("\nInsira o nome do aluno a ser pesquisado: ");
  scanf(" %[^\n]", nome_aln);

  sprintf(busca, "Nome do aluno: %s", nome_aln);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10){
      erro--;
      printf("\n\nENCONTRADO NA LINHA %d: \n\n", cont);
      rewind(p_arquivo);
      for(int i=0; i<(cont-7); i++)
        fgets(retorno, 50, p_arquivo);
      sublinhado();
      for(int k=0; k<7; k++){
        fgets(retorno, 50, p_arquivo);
        printf("\t%s", retorno);
      }
      saida_reset();
      printf("\n");
    }
  }
  if(erro==1){
    vermelho_italico();
    printf("\n\n(!) Emprestimo nao encontrado.\n\n");
    saida_reset();
    sleep(1);
  }

  rewind(p_arquivo);
}

void listar_emprestimos(FILE *p_arquivo){
  char retorno[50];
  int erro=1;

  rewind(p_arquivo);

  sublinhado();
  printf("\n\nLISTA DE EMPRESTIMOS CADASTRADOS:\n\n");
  saida_reset();
  
  while(fgets(retorno, 50, p_arquivo) != NULL){
    amarelo_negrito();
    printf("\t%s", retorno);
    erro--;
  }

  saida_reset();
  
  if(erro==1){
    vermelho_italico();
    printf("\n(!) Nenhum emprestimo cadastrado.\n\n");
    saida_reset();
    sleep(1);
  }

  rewind(p_arquivo);
}

void editar_dados_emprestimo(FILE *p_arquivo){
  int codigo, cont=0, cont2=0;
  char busca[50];
  char retorno[50];
  char inserir[30];
  char copia[30];
  char op;

  fclose(p_arquivo);

  p_arquivo = fopen("dados.txt", "r+");

  printf("\nInsira um codigo de emprestimo: ");
  scanf("%d", &codigo);

  sprintf(busca, "Codigo de emprestimo: %d", codigo);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10){
      break;
    }
  }

  if(strcmp(busca, retorno) != -10){
    vermelho_italico();
    printf("\n\n(!) Emprestimo nao encontrado.\n\n");
    saida_reset();
    rewind(p_arquivo);
    fclose(p_arquivo);
    sleep(1);
    return;
  }
    
  printf("\n\nEDITANDO DADOS: \n");

  FILE *p_arquivo_copia = fopen("copia.txt", "w");

  for(int i=0; i<6; i++){
    fgets(retorno, 50, p_arquivo);
    cont2++;
    printf("\n%s", retorno);
    printf("Alterar? [S/N] -> ");
    scanf(" %c", &op);
    
    if(op == 'S' || op == 's'){
      int k=0, l=0;
      
      do{
        if(retorno[k] != ':'){
          copia[l] = retorno[k];
          l++;
        }
        k++;
      }while(retorno[k] != ':');
      
      copia[l] = '\0';
      
      printf("\nLINHA %d", cont+cont2);
      printf("\n* Insira a nova informacao: ");
      scanf(" %[^\n]", inserir);
      
      if(cont2==1){
        char data_aux[12];
        int i=0;
        int dt_emp=0, dt_ent=0;

        if(verifica_data(inserir) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }
        
        dt_emp = verifica_data(inserir);
        
        rewind(p_arquivo);
        
        for(int j=0; j<(cont+cont2); j++)
          fgets(retorno, 50, p_arquivo);
        
        while(fgetc(p_arquivo)!=58); //codigo ASCII para dois pontos.
        
        fgetc(p_arquivo); //pega somente um caracter.
        
        for(i=0; i<10; i++)
          data_aux[i] = fgetc(p_arquivo);
        
        i++;
        data_aux[i]='\0';
        
        if(verifica_data(data_aux) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }

        dt_ent = verifica_data(data_aux);
        
        if(dt_emp > dt_ent){
          vermelho_italico();
          printf("\n\n(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
          saida_reset();
          printf("\nRetornando ao menu...\n\n");
          
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          
          sleep(1);
          return;
        } 
      }
      
      if(cont2==2){
        char data_aux[12];
        int i=0;
        int dt_emp=0, dt_ent=0;
        
        if(verifica_data(inserir) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }

        dt_ent = verifica_data(inserir);
        
        rewind(p_arquivo);
        
        for(int j=0; j<(cont+cont2-2); j++)
          fgets(retorno, 50, p_arquivo);
        
        while(fgetc(p_arquivo)!=58);
        fgetc(p_arquivo);
        
        for(i=0; i<10; i++)
          data_aux[i] = fgetc(p_arquivo);
        
        i++;
        data_aux[i]='\0';
        
        if(verifica_data(data_aux) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }

        dt_emp = verifica_data(data_aux);
        
        if(dt_emp > dt_ent){
          vermelho_italico();
          printf("\n\n(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
          saida_reset();
          printf("\nRetornando ao menu...\n\n");
          
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          
          sleep(1);
          return;
        }
      }

      if(cont2==3){
        rewind(p_arquivo);
        
        if(verifica_cod_livro(p_arquivo, inserir) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }
      }

      if(cont2==5){
        int num = atoi(inserir);
        rewind(p_arquivo);

        if(verifica_mat_aluno(p_arquivo, num) == 0){
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }
      }
      
      rewind(p_arquivo);
      
      for(int j=0; j<(cont+cont2-1); j++){
        fgets(retorno, 50, p_arquivo);
        fputs(retorno, p_arquivo_copia);
      }
      
      cont--;
      
      fprintf(p_arquivo_copia, "%s: %s\n", copia, inserir);
      fgets(retorno, 50, p_arquivo);
      
      while(fgets(retorno, 50, p_arquivo) != NULL){
        fputs(retorno, p_arquivo_copia);
      }
      
      amarelo_negrito();
      printf("\n(!) Informacao alterada com sucesso!\n");
      saida_reset();
      
      break;
    }
  }

  if(op != 'S' && op != 's'){
    amarelo_negrito();
    printf("\n(!) Nenhum dado foi alterado!\n");
    saida_reset();
    rewind(p_arquivo);
    fclose(p_arquivo_copia);
    remove("copia.txt");
    printf("\n\n");
    sleep(1);
    return;
  }
  
  rewind(p_arquivo);
  rewind(p_arquivo_copia);
  fclose(p_arquivo);
  fclose(p_arquivo_copia);
  remove("dados.txt");
  rename("copia.txt", "dados.txt");

  printf("\n\n");
  sleep(1);
}

void excluir_emprestimo(FILE *p_arquivo){
  int codigo, cont=0;
  char busca[50];
  char retorno[50];
  char copia[50];
  char op;
  
  fclose(p_arquivo);
  p_arquivo = fopen("dados.txt", "r+");

  printf("\nInsira um codigo de emprestimo: ");
  scanf("%d", &codigo);

  sprintf(busca, "Codigo de emprestimo: %d", codigo);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10)
      break;
  }

  if(strcmp(busca, retorno) != -10){
    vermelho_italico();
    printf("\n\n(!) Emprestimo nao encontrado.\n\n");
    saida_reset();
    rewind(p_arquivo);
    fclose(p_arquivo);
    sleep(1);
    return;
  }

  printf("\n\nPor favor, confira as informacoes a seguir:\n\n");
  sublinhado();
  printf("\t%s\n", busca);
  for(int i=0; i<6; i++){
    fgets(retorno, 50, p_arquivo);
    printf("\t%s", retorno);
  }
  saida_reset();

  printf("\n\n(!) Deseja realmente excluir este emprestimo? [S/n]");
  printf("\n\t-> ");
  scanf(" %c", &op);
  if(op == 'N' || op == 'n'){
    printf("\nRetornando ao menu principal...\n\n");
    rewind(p_arquivo);
    fclose(p_arquivo);
    sleep(1);
    return;
  }else{
    if(op != 'S' && op != 's'){
      printf("\nOpcao invalida.");
      printf("\nRetornando ao menu principal...\n\n");
      rewind(p_arquivo);
      fclose(p_arquivo);
      sleep(1);
      return;
    }
  }

  printf("\n\nExcluindo dados...");

  rewind(p_arquivo);

  FILE *p_arquivo_copia = fopen("copia.txt", "w");

  for(int i=0; i<(cont-2); i++){
    fgets(copia, 50, p_arquivo);
    fputs(copia, p_arquivo_copia);
  }

  for(int j=0; j<9; j++)
    fgets(copia, 50, p_arquivo);

  cont=(cont-2)+9;
  
  while(fgets(copia, 50, p_arquivo))
    fputs(copia, p_arquivo_copia);

  amarelo_negrito();
  printf("\n\n(!) Emprestimo excluido com sucesso.");
  saida_reset();

  rewind(p_arquivo);
  rewind(p_arquivo_copia);
  fclose(p_arquivo);
  fclose(p_arquivo_copia);
  remove("dados.txt");
  rename("copia.txt", "dados.txt");
  
  sleep(1);
  printf("\n\n");
}

int verifica_data(char string[]){
  int h=0, i=0, dd=0, mm=0, aa=0;
  int dt_em_dias=0;
  do{
    if(string[h]<45 || string[h]>57){
      vermelho_italico();
      printf("\n\n(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
      saida_reset();
      printf("\nRetornando ao menu...");
      sleep(1);
      return 0;
    }
    h++;
  }while(string[h]!='\0');
  if(h!=10){
    vermelho_italico();
    printf("\n\n(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
    saida_reset();
    printf("\nRetornando ao menu...\n\n");
    sleep(1);
    return 0;
  }
  dd = dd+(string[i]-48)*10; i++;
  dd = dd+(string[i]-48); i+=2;
  mm = mm+(string[i]-48)*10; i++;
  mm = mm+(string[i]-48); i+=2;
  aa = aa+(string[i]-48)*1000; i++;
  aa = aa+(string[i]-48)*100; i++;
  aa = aa+(string[i]-48)*10; i++;
  aa = aa+(string[i]-48); i++;
  dt_em_dias = dd+(mm*30)+(aa*365);

  return dt_em_dias;
}

int verifica_cod_livro(FILE *p_arquivo, char string[]){
  int cont=0;
  int tam_str = strlen(string);
  char busca[50];
  char retorno[50];

  if(tam_str != 13){
    vermelho_italico();
    printf("\n\n(!) Erro: o codigo ISBN deve ter 13 digitos!\n\n");
    saida_reset();
    printf("Retornando ao menu...\n\n");
    rewind(p_arquivo);
    sleep(1);
    return 0;
  }

  for(int i=0; i<tam_str; i++){
    if(string[i] < 48 || string[i] > 57){
      vermelho_italico();
      printf("\n\n(!) Erro: o codigo ISBN deve conter somente numeros!\n\n");
      saida_reset();
      printf("Retornando ao menu...\n\n");
      rewind(p_arquivo);
      sleep(1);
      return 0;
    }
  }
  
  sprintf(busca, "Codigo ISBN: %s", string);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10){
      vermelho_italico();
      printf("\n\n(!) Erro: codigo ISBN ja cadastrado!\n\n");
      saida_reset();
      printf("Retornando ao menu...\n\n");
      rewind(p_arquivo);
      sleep(1);
      return 0;
    }
  }

  rewind(p_arquivo);
  return 1;
}

int verifica_mat_aluno(FILE *p_arquivo, int matricula){
  int cont=0;
  char busca[50];
  char retorno[50];
  
  sprintf(busca, "Numero da matricula do aluno: %d", matricula);

  while(fgets(retorno, 50, p_arquivo) != NULL){
    cont++;
    if(strcmp(busca, retorno) == -10){
      vermelho_italico();
      printf("\n\n(!) Erro: este aluno ja possui um emprestimo cadastrado!\n\n");
      saida_reset();
      printf("Retornando ao menu...\n\n");
      rewind(p_arquivo);
      sleep(1);
      return 0;
    }
  }

  rewind(p_arquivo);
  return 1;
}

void livros(FILE *p_arquivo){
  int cont=0, erro=1;
  char busca[] = {"Titulo do livro: "};
  char retorno[50];
  
  sublinhado();
  printf("\n\nLIVROS CADASTRADOS:\n\n");
  saida_reset();

  while(fgets(retorno, 50, p_arquivo) != NULL){
    if(strstr(retorno, busca) != NULL){
      amarelo_negrito();
      printf("\t%s", retorno);
      erro--;
    }
  }

  saida_reset();
  printf("\n");
  
  if(erro==1){
    vermelho_italico();
    printf("(!) Nenhum livro cadastrado.\n\n");
    saida_reset();
    sleep(1);
  }

  rewind(p_arquivo);
}

void sair(FILE *p_arquivo){
  amarelo_negrito();
  printf("\n\nSaindo do programa...\n");
  fclose(p_arquivo);
}

void azul_italico(){
  printf("\x1b[3;34m");
}

void italico(){
  printf("\x1b[3;37m");
}

void vermelho_italico(){
  printf("\x1b[3;31m");
}

void amarelo_negrito(){
  printf("\x1b[1;33m");
}

void sublinhado(){
  printf("\x1b[4;37m");
}

void saida_reset(){
  printf("\x1b[0m");
}