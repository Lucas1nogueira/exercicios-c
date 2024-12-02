#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_din.h"

struct Elemento {
    struct Dados num;
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

int insere_pilha (Pilha* pi, int num) {
    if (pi == NULL) return 0;
    Elm* no = (Elm*) malloc(sizeof(Elm));
    if (no == NULL) return 0;
    no->num.x = num;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    if (pi != NULL) {
        Elm *no = *pi;
        *pi = no->prox;
        free(no);
    }
    return 1;
}

Pilha* organiza_pilha (Pilha* pi, int qtd) {
    Pilha *pi_org = cria_pilha ();
    int *vet_aux = (int*) malloc(qtd*sizeof(int));
    if (vet_aux == NULL) return 0;
    int aux;
    for (int i=0; i<qtd; i++) {
        vet_aux[i] = (*pi)->num.x;
        remove_pilha (pi);
    }
    for (int i=0; i<qtd; i++) {
        for (int j=0; j<qtd; j++) {
            if (vet_aux[i] < vet_aux[j]) {
                aux = vet_aux[i];
                vet_aux[i] = vet_aux[j];
                vet_aux[j] = aux;
            }
        }
    }
    for (int i=0; i<qtd; i++)
        insere_pilha (pi_org, vet_aux[i]);
    return pi_org;
}

Pilha* inverte_pilha (Pilha* pi) {
    Pilha *pi_inv = cria_pilha();
    do {
        Elm* no1 = (Elm*) malloc(sizeof(Elm));
        if (no1 == NULL) return 0;
        no1->num.x = (*pi)->num.x;
        no1->prox = (*pi_inv);
        *pi_inv = no1;
        Elm *no2 = *pi;
        *pi = no2->prox;
        free (no2);
    }while ((*pi) != NULL);
    return pi_inv;
}

int exibe_pilha (Pilha *pi) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;
    do {
        printf("\n%d", (*pi)->num.x);
        remove_pilha (pi);
    }while ((*pi) != NULL);
    return 1;
}