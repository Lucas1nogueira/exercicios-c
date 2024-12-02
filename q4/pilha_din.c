#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_din.h"

struct Elemento {
    struct Dados Exp_mat;
    struct Elemento *prox;
};

typedef struct Elemento Elm;

Pilha* cria_pilha () {
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if (pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_pilha (Pilha* pi) {
    if (pi != NULL) {
        Elm* no;
        while ((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int insere_pilha (Pilha* pi, char string[]) {
    if (pi == NULL) return 0;
    int tam = strlen(string);
    for (int i=0; i<tam; i++) {
        Elm* no = (Elm*) malloc(sizeof(Elm));
        if (no == NULL) return 0;
        no->Exp_mat.x = string[i];
        no->prox = (*pi);
        *pi = no;
    }
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    if (pi != NULL) {
        Elm *no = *pi;
        *pi = no->prox;
        free (no);
    }
    return 1;
}

Pilha* inverte_pilha (Pilha* pi) {
    Pilha *pi3 = cria_pilha();
    do {
        Elm* no1 = (Elm*) malloc(sizeof(Elm));
        if (no1 == NULL) return 0;
        no1->Exp_mat.x = (*pi)->Exp_mat.x;
        no1->prox = (*pi3);
        *pi3 = no1;
        Elm *no2 = *pi;
        *pi = no2->prox;
        free (no2);
    }while ((*pi) != NULL);
    return pi3;
}

int verifica_expressao (Pilha* pi){
    int parent_aberto=0;
    int parent_fechado=0;
    do {
        if ((*pi)->Exp_mat.x == '(') {
            parent_aberto++;
        }
        if ((*pi)->Exp_mat.x == ')') {
            parent_fechado++;
            if (parent_fechado == parent_aberto+1) return 0;
        }
        remove_pilha (pi);
    }while ((*pi) != NULL);
    if (parent_aberto == parent_fechado)
        return 1;
    else
        return 0;
}