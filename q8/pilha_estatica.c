#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct Pilha {
    int qtd;
    struct Dados numeros[MAX];
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

int insere_pilha (Pilha* pi, int num) {
    if (pi == NULL) return 0;
    if (pilha_cheia(pi)) return 0;
    pi->numeros[pi->qtd].x = num;
    pi->qtd++;
    if (pilha_cheia(pi)) return 0;
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL || pi->qtd == 0) return 0;
    pi->qtd--;
    return 1;
}

int conta_pares (Pilha* pi, int* pares) {
    if (pi == NULL || pi->qtd == 0)
        return 0;
    do {
        if ((pi->numeros[pi->qtd-1].x) % 2 == 0)
            (*pares)++;
        remove_pilha (pi);
    }while (pi->qtd != 0);
    return 1;
}