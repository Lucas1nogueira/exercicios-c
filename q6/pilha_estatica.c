#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct Pilha {
    int qtd;
    struct Dados num[MAX];
};

Pilha* cria_pilha () {
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct Pilha));
    if (pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_pilha (Pilha* pi) {
    free (pi);
}

int pilha_cheia (Pilha* pi) {
    if (pi == NULL) return -1;
    return (pi->qtd == MAX);
}

int insere_n_pilha (Pilha* pi, int n) {
    if (pi == NULL) return 0;
    if (pilha_cheia(pi)) return 0;
    pi->num[pi->qtd].x = 1;
    pi->qtd++;
    int num=1, aux=1;
    for (int i=1; i<n; i++) {
        pi->num[pi->qtd].x = num;
        pi->qtd++;
        num = num + aux;
        aux = num - aux;
        if (pilha_cheia(pi)) return 0;
    }
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL || pi->qtd == 0) return 0;
    pi->qtd--;
    return 1;
}

Pilha* inverte_pilha (Pilha* pi) {
    Pilha *pi_inv = cria_pilha();
    do {
        pi_inv->num[pi_inv->qtd].x = pi->num[pi->qtd-1].x;
        pi_inv->qtd++;
        if (pilha_cheia(pi_inv)) return 0;
        remove_pilha (pi);
    }while (pi->qtd != 0);
    return pi_inv;
}

int exibe_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    do {
        printf("\n%d", pi->num[pi->qtd-1].x);
        remove_pilha (pi);
    }while (pi->qtd != 0);
    return 1;
}