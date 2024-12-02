#include <stdio.h>
#include <stdlib.h>
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

int insere_pilha (Pilha* pi, char letra) {
    if (pi == NULL) return 0;
    Elm* no = (Elm*) malloc(sizeof(Elm));
    if (no == NULL) return 0;
    no->letra.x = letra;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int exibe_topo_pilha (Pilha* pi, char* letra) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;
    *letra = (*pi)->letra.x;
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;
    Elm* no = *pi;
    *pi = no->prox;
    free (no);
    return 1;
}