#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_din.h"

struct Elemento {
    struct Dados letra;
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

int tamanho_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    int cont = 0;
    Elm* no = *pi;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_vazia (Pilha* pi) {
    if (pi == NULL) return 1;
    if (*pi == NULL) return 1;
    return 0;
}

int insere_pilha (Pilha* pi, char string[]) {
    if (pi == NULL) return 0;
    int tam = strlen(string);
    for (int i=0; i<tam; i++) {
        Elm* no = (Elm*) malloc(sizeof(Elm));
        if (no == NULL) return 0;
        no->letra.x = string[i];
        no->prox = (*pi);
        *pi = no;
    }
    return 1;
}

Pilha* inverte_pilha (Pilha* pi) {
    Pilha *pi3 = cria_pilha();
    do {
        Elm* no1 = (Elm*) malloc(sizeof(Elm));
        if (no1 == NULL) return 0;
        no1->letra.x = (*pi)->letra.x;
        no1->prox = (*pi3);
        *pi3 = no1;
        Elm *no2 = *pi;
        *pi = no2->prox;
        free (no2);
    }while ((*pi) != NULL);
    return pi3;
}

int comp_pilhas (Pilha* pi, Pilha* pi2) {
    do {
        if ((*pi)->letra.x == (*pi2)->letra.x) {
            Elm *no = *pi;
            Elm *no2 = *pi2;
            *pi = no->prox;
            free (no);
            *pi2 = no2->prox;
            free (no2);
        }else return 0;
    }while ((*pi) != NULL || (*pi2 != NULL));
    return 1;
}