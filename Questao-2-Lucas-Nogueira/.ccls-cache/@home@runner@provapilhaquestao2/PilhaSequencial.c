#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaSequencial.h" //inclui os Protótipos

//Definição do tipo Pilha
struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *al = pi->dados[pi->qtd-1];
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i=pi->qtd-1; i >=0; i--){
        printf("Nome do site: %s\n",pi->dados[i].nome_site);
        printf("Link: %s\n",pi->dados[i].link);
        printf("-------------------------------\n");
    }
}

int insere_Pilha(Pilha* pi, struct aluno al) {
    if (pi == NULL)
        return 0;
    if (Pilha_cheia (pi))
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi) {
    if (pi == NULL)
        return 0;
    if (Pilha_vazia (pi))
        return 0;
    pi->qtd--;
    return 1;
}

Pilha* pesquisa_site_Pilha(Pilha* pi, char nome[]) {
    if (pi == NULL) {
        printf("\nErro ao ler pilha!");
        libera_Pilha (pi);
        exit(1);
    }
    if (Pilha_vazia (pi)) {
        printf("\nA pilha esta' vazia!");
        libera_Pilha (pi);
        exit(1);
    }
    Pilha* pi2 = cria_Pilha ();
    int i;
    char copia_nome[50];
    char copia_link[50];
    for (i = pi->qtd-1; i>=0; i--) {
        if(strcmp (pi->dados[i].nome_site, nome) == 0) {
            printf("\nSite encontrado! Link: %s\n\n", pi->dados[i].link);
            strcpy(copia_nome, pi->dados[i].nome_site);
            strcpy(copia_link, pi->dados[i].nome_site);
        }else{
            strcpy(pi2->dados[pi2->qtd].nome_site, pi->dados[i].nome_site);
            strcpy(pi2->dados[pi2->qtd].link, pi->dados[i].link);
            pi2->qtd++;
        }
    }
    strcpy(pi2->dados[pi2->qtd].nome_site, copia_nome);
    strcpy(pi2->dados[pi2->qtd].link, copia_link);
    pi2->qtd++;
    return pi2;
}