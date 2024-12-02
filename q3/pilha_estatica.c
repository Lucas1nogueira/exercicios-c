#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_estatica.h"

struct Pilha {
    int qtd;
    struct Dados palavra[MAX];
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

int insere_pilha (Pilha* pi, char string[]) {
    if (pi == NULL) return 0;
    if (pilha_cheia(pi)) return 0;
    int tam = strlen(string);
    for (int i=0; i<tam; i++) {
        pi->palavra[pi->qtd].x = string[i];
        pi->qtd++;
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
    Pilha *pi3 = cria_pilha();
    do {
        pi3->palavra[pi3->qtd].x = pi->palavra[pi->qtd-1].x;
        pi3->qtd++;
        if (pilha_cheia(pi3)) return 0;
        remove_pilha (pi);
    }while (pi->qtd != 0);
    return pi3;
}

int comp_pilhas (Pilha* pi, Pilha* pi2) {
    while (pi->qtd != 0 || pi2->qtd != 0) {
        if (pi->palavra[pi->qtd-1].x == pi2->palavra[pi2->qtd-1].x) {
            remove_pilha (pi);
            remove_pilha (pi2);
        }else return 0;
    }
    return 1;
}