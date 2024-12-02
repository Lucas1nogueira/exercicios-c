#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "biblioteca.h"

int ler_qtd_emp(FILE *p_arquivo){
  int linha=0, quantidade=0, j=0, k=0, m=0, unidade=1;
  int *numerais;
  char retorno[50];

  while(fgets(retorno, 50, p_arquivo) != NULL)
    linha++;
  
  rewind(p_arquivo);
  
  if(linha<4)
    return 1;
  
  for(int i=0; i<(linha-7); i++)
    fgets(retorno, 50, p_arquivo);
  
  while(retorno[j] != ':')
    j++;
  
  j+=2;
  m = j;
  j++;
  
  while(retorno[j] != '\0'){
    j++;
    k++;
  }
  
  numerais = (int *) malloc((k+1)*sizeof(int));
  
  for(int l=0; l<k; l++){
    numerais[l] = (retorno[m]-48);
    m++;
  }
  
  while(k>=0){
    quantidade = quantidade + (numerais[k-1]*unidade);
    unidade = unidade*10;
    k--;
  }
  
  free(numerais);
  rewind(p_arquivo);
  
  return (quantidade+1);
}

void animacao(){
  printf("\n\033[3;36m>>  SISTEMA");
  printf("\n\t   DE GERENCIAMENTO");
  printf("\n\t\t\t  DE BIBLIOTECA  <<\n");
  printf("\033[0;37m\n");
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
  int h=0, i=0, dd=0, mm=0, aa=0;
  int dt_emprestimo=0, dt_entrega=0;
  printf("\n\nCodigo do emprestimo: %d (Gerado automaticamente)", info.emp.codigo);
  printf("\nInsira a data do emprestimo [dd/Mm/AAAA]: ");
  scanf("%s", info.emp.data_emp);
  do{
    if(info.emp.data_emp[h]<45 || info.emp.data_emp[h]>57){
      printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
      printf("\nRetornando ao menu...\n\n\033[0;37m");
      sleep(1);
      return;
    }
    h++;
  }while(info.emp.data_emp[h]!='\0');
  if(h!=10){
    printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
    printf("\nRetornando ao menu...\n\n\033[0;37m");
    sleep(1);
    return;
  }
  dd = dd+(info.emp.data_emp[i]-48)*10; i++;
  dd = dd+(info.emp.data_emp[i]-48); i+=2;
  mm = mm+(info.emp.data_emp[i]-48)*10; i++;
  mm = mm+(info.emp.data_emp[i]-48); i+=2;
  aa = aa+(info.emp.data_emp[i]-48)*1000; i++;
  aa = aa+(info.emp.data_emp[i]-48)*100; i++;
  aa = aa+(info.emp.data_emp[i]-48)*10; i++;
  aa = aa+(info.emp.data_emp[i]-48); i++;
  dt_emprestimo = dd+(mm*30)+(aa*365);
  printf("Insira a data de entrega [dd/Mm/AAAA]: ");
  scanf("%s", info.emp.data_ent);
  h=0, i=0, dd=0, mm=0, aa=0;
  do{
    if(info.emp.data_ent[h]<45 || info.emp.data_ent[h]>57){
      printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
      printf("\nRetornando ao menu...\n\n\033[0;37m");
      sleep(1);
      return;
    }
    h++;
  }while(info.emp.data_ent[h]!='\0');
  if(h!=10){
    printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
    printf("\nRetornando ao menu...\n\n\033[0;37m");
    sleep(1);
    return;
  }
  dd = dd+(info.emp.data_ent[i]-48)*10; i++;
  dd = dd+(info.emp.data_ent[i]-48); i+=2;
  mm = mm+(info.emp.data_ent[i]-48)*10; i++;
  mm = mm+(info.emp.data_ent[i]-48); i+=2;
  aa = aa+(info.emp.data_ent[i]-48)*1000; i++;
  aa = aa+(info.emp.data_ent[i]-48)*100; i++;
  aa = aa+(info.emp.data_ent[i]-48)*10; i++;
  aa = aa+(info.emp.data_ent[i]-48); i++;
  dt_entrega = dd+(mm*30)+(aa*365);
  if(dt_emprestimo > dt_entrega){
    printf("\n\n\033[0;31m(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
    printf("\nRetornando ao menu...\n\n\033[0;37m");
    sleep(1);
    return;
  }
  printf("Insira o codigo ISBN do livro: ");
  scanf("%s", info.liv.isbn);
  printf("Insira o titulo do livro: ");
  scanf(" %[^\n]", info.liv.nome_livro);
  printf("Insira o numero da matricula do aluno: ");
  scanf("%d", &info.aln.matricula);
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
  (*p_posicao)++;
  printf("\n\033[1;33m(!) Emprestimo realizado com sucesso.\033[0;37m");
  printf("\nVoltando ao menu...\n\n");
  sleep(1);
  rewind(p_arquivo);
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
      printf("\n\n\033[0;31m(!) Opcao invalida.\n");
      printf("Retornando ao menu...\n\n\033[0;37m");
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
      printf("\t\033[4;37m%s\n", busca);
      for(int i=0; i<6; i++){
        fgets(retorno, 50, p_arquivo);
        printf("\t%s", retorno);
      }
      printf("\033[0;37m\n\n");
    }
  }
  if(erro==1){
    printf("\n\n\033[0;31m(!) Emprestimo nao encontrado.\n\n\033[0;37m");
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
      for(int k=0; k<7; k++){
        fgets(retorno, 50, p_arquivo);
        printf("\t\033[4;37m%s", retorno);
      }
      printf("\033[0;37m\n");
      cont+=2;
    }
  }
  if(erro==1){
    printf("\n\n\033[0;31m(!) Emprestimo nao encontrado.\n\n\033[0;37m");
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
      for(int k=0; k<7; k++){
        fgets(retorno, 50, p_arquivo);
        printf("\t\033[4;37m%s", retorno);
      }
      printf("\033[0;37m\n");
    }
  }
  if(erro==1){
    printf("\n\n\033[0;31m(!) Emprestimo nao encontrado.\n\n\033[0;37m");
    sleep(1);
  }

  rewind(p_arquivo);
}

void listar_emprestimos(FILE *p_arquivo){
  char retorno[50];
  int erro=1;

  rewind(p_arquivo);

  printf("\033[4;37m");
  printf("\n\nLISTA DE EMPRESTIMOS CADASTRADOS:\n");
  printf("\033[0;33m\n");
  
  while(fgets(retorno, 50, p_arquivo) != NULL){
    printf("\t%s", retorno);
    erro--;
  }
  
  if(erro==1){
    printf("\n\033[0;31m(!) Nenhum emprestimo cadastrado.\n\n\033[0;37m");
    sleep(1);
  }

  rewind(p_arquivo);

  printf("\033[0;37m");
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
    printf("\n\n\033[0;31m(!) Emprestimo nao encontrado.\n\033[0;37m\n");
    rewind(p_arquivo);
    fclose(p_arquivo);
    p_arquivo = fopen("dados.txt", "a+");
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
        int h=0, i=0, n=0, dd=0, mm=0, aa=0;
        int dt_ent=0, dt_emp=0;
        do{
          if(inserir[h]<45 || inserir[h]>57){
            printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
            printf("\nRetornando ao menu...\n\n\033[0;37m");
            rewind(p_arquivo);
            rewind(p_arquivo_copia);
            fclose(p_arquivo);
            fclose(p_arquivo_copia);
            remove("copia.txt");
            sleep(1);
            return;
          }
          h++;
        }while(inserir[h]!='\0');
        if(h!=10){
          printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
          printf("\nRetornando ao menu...\n\n\033[0;37m");
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }
        rewind(p_arquivo);
        for(int j=0; j<(cont+cont2); j++)
          fgets(retorno, 50, p_arquivo);
        while(fgetc(p_arquivo)!=58);
        fgetc(p_arquivo);
        for(i=0; i<10; i++)
          data_aux[i] = fgetc(p_arquivo);
        i++;
        data_aux[i]='\0';
        dd = dd+(data_aux[n]-48)*10; n++;
        dd = dd+(data_aux[n]-48); n+=2;
        mm = mm+(data_aux[n]-48)*10; n++;
        mm = mm+(data_aux[n]-48); n+=2;
        aa = aa+(data_aux[n]-48)*1000; n++;
        aa = aa+(data_aux[n]-48)*100; n++;
        aa = aa+(data_aux[n]-48)*10; n++;
        aa = aa+(data_aux[n]-48); n++;
        dt_ent = dd+(mm*30)+(aa*365);
        n=0, dd=0, mm=0, aa=0;
        dd = dd+(inserir[n]-48)*10; n++;
        dd = dd+(inserir[n]-48); n+=2;
        mm = mm+(inserir[n]-48)*10; n++;
        mm = mm+(inserir[n]-48); n+=2;
        aa = aa+(inserir[n]-48)*1000; n++;
        aa = aa+(inserir[n]-48)*100; n++;
        aa = aa+(inserir[n]-48)*10; n++;
        aa = aa+(inserir[n]-48); n++;
        dt_emp = dd+(mm*30)+(aa*365);
        if(dt_emp > dt_ent){
          printf("\n\n\033[0;31m(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
          printf("\nRetornando ao menu...\n\n\033[0;37m");
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
        int h=0, i=0, n=0, dd=0, mm=0, aa=0;
        int dt_ent=0, dt_emp=0;
        do{
          if(inserir[h]<45 || inserir[h]>57){
            printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
            printf("\nRetornando ao menu...\n\n\033[0;37m");
            rewind(p_arquivo);
            rewind(p_arquivo_copia);
            fclose(p_arquivo);
            fclose(p_arquivo_copia);
            remove("copia.txt");
            sleep(1);
            return;
          }
          h++;
        }while(inserir[h]!='\0');
        if(h!=10){
          printf("\n\n\033[0;31m(!) Erro: as datas devem estar no formato dd/Mm/AAAA, ex: 01/01/2000.");
          printf("\nRetornando ao menu...\n\n\033[0;37m");
          rewind(p_arquivo);
          rewind(p_arquivo_copia);
          fclose(p_arquivo);
          fclose(p_arquivo_copia);
          remove("copia.txt");
          sleep(1);
          return;
        }
        rewind(p_arquivo);
        for(int j=0; j<(cont+cont2-2); j++)
          fgets(retorno, 50, p_arquivo);
        while(fgetc(p_arquivo)!=58);
        fgetc(p_arquivo);
        for(i=0; i<10; i++)
          data_aux[i] = fgetc(p_arquivo);
        i++;
        data_aux[i]='\0';
        dd = dd+(data_aux[n]-48)*10; n++;
        dd = dd+(data_aux[n]-48); n+=2;
        mm = mm+(data_aux[n]-48)*10; n++;
        mm = mm+(data_aux[n]-48); n+=2;
        aa = aa+(data_aux[n]-48)*1000; n++;
        aa = aa+(data_aux[n]-48)*100; n++;
        aa = aa+(data_aux[n]-48)*10; n++;
        aa = aa+(data_aux[n]-48); n++;
        dt_emp = dd+(mm*30)+(aa*365);
        n=0, dd=0, mm=0, aa=0;
        dd = dd+(inserir[n]-48)*10; n++;
        dd = dd+(inserir[n]-48); n+=2;
        mm = mm+(inserir[n]-48)*10; n++;
        mm = mm+(inserir[n]-48); n+=2;
        aa = aa+(inserir[n]-48)*1000; n++;
        aa = aa+(inserir[n]-48)*100; n++;
        aa = aa+(inserir[n]-48)*10; n++;
        aa = aa+(inserir[n]-48); n++;
        dt_ent = dd+(mm*30)+(aa*365);
        if(dt_emp > dt_ent){
          printf("\n\n\033[0;31m(!) Erro: a data de emprestimo nao pode ser maior do que a data de entrega.");
          printf("\nRetornando ao menu...\n\n\033[0;37m");
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
      printf("\n\033[0;33m(!) Informacao alterada com sucesso!\033[0;37m\n");
      break;
    }
  }

  rewind(p_arquivo);
  rewind(p_arquivo_copia);
  fclose(p_arquivo);
  fclose(p_arquivo_copia);
  remove("dados.txt");
  rename("copia.txt", "dados.txt");

  sleep(1);
  
  printf("\n\n");
}

void excluir_emprestimo(FILE *p_arquivo){
  int codigo, cont=0;
  char busca[50];
  char retorno[50];
  char copia[50];
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
    printf("\n\n\033[0;31m(!) Emprestimo nao encontrado.\n\033[0;37m\n");
    rewind(p_arquivo);
    fclose(p_arquivo);
    sleep(1);
    return;
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
  
  printf("\n\033[0;33m(!) Emprestimo excluido com sucesso.\033[0;37m");

  rewind(p_arquivo);
  rewind(p_arquivo_copia);
  fclose(p_arquivo);
  fclose(p_arquivo_copia);
  remove("dados.txt");
  rename("copia.txt", "dados.txt");
  
  sleep(1);
  printf("\n\n");

  rewind(p_arquivo);
}

void livros(FILE *p_arquivo){
  int cont=0, erro=1;
  char busca[] = {"Titulo do livro: "};
  char retorno[50];
  
  printf("\033[4;37m");
  printf("\n\nLIVROS CADASTRADOS:\n\n");
  printf("\033[0;33m");

  while(fgets(retorno, 50, p_arquivo) != NULL){
    if(strstr(retorno, busca) != NULL){
      printf("\t\033[1;33m%s", retorno);
      erro--;
    }
  }
  
  printf("\033[0;37m\n");
  
  if(erro==1){
    printf("\033[0;31m(!) Nenhum livro cadastrado.\n\n\033[0;37m");
    sleep(1);
  }

  rewind(p_arquivo);
}