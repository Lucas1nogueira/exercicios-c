#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini�o do tipo Fila
struct elemento{
    struct dados info;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Defini�o do N� Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct dados *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->info;
    return 1;
}

int insere_Fila(Fila* fi, struct dados al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->info = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while (no != NULL) {
        printf ("\nNome: %s", no->info.nome);
        printf ("\nNum. cartao SUS: %d", no->info.numero_sus);
        if (no->info.priori == 0)
            printf ("\nPrioridade: Verde");
        if (no->info.priori == 1)
            printf ("\nPrioridade: Amarelo");
        if (no->info.priori == 2)
            printf ("\nPrioridade: Vermelho");
        printf ("\n-------------------\n");
        no = no->prox;
    }
}

void delay (int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock ();
    while (clock () < start_time + milli_seconds);
}

int prior_aleat () {
    srand (time(NULL));
    int r = rand () % 3;
    return r;
}

void gerencia_socorro (Fila *fi_orig, Fila* fi_vd, Fila* fi_am, Fila* fi_ve) {
    if (fi_orig == NULL || fi_vd == NULL || fi_am == NULL || fi_ve == NULL)
        return;
    if (Fila_vazia (fi_orig))
        return;
    while (fi_orig->inicio != NULL) {
        if (fi_orig->inicio->info.priori == 0) {
            insere_Fila (fi_vd, fi_orig->inicio->info);
            remove_Fila (fi_orig);
        }
        if (fi_orig->inicio->info.priori == 1) {
            insere_Fila (fi_am, fi_orig->inicio->info);
            remove_Fila (fi_orig);
        }
        if (fi_orig->inicio->info.priori == 2) {
            insere_Fila (fi_ve, fi_orig->inicio->info);
            remove_Fila (fi_orig);
        }
    }
}

void atende_fila (Fila *fi) {
    if (fi == NULL || Fila_vazia (fi)) return;
    struct dados consulta;
    while (fi->inicio != NULL) {
        consulta = fi->inicio->info;
        printf ("\nPaciente chegou!");
        printf ("\nNome: %s", consulta.nome);
        printf ("\nCartao SUS: %d", consulta.numero_sus);
        if (consulta.priori == 0)
            printf ("\nPrioridade: Verde");
        if (consulta.priori == 1)
            printf ("\nPrioridade: Amarelo");
        if (consulta.priori == 2)
            printf ("\nPrioridade: Vermelho");
        remove_Fila (fi);
        printf ("\n");
        delay (500);
    }
    printf ("\n\n****************\n");
}