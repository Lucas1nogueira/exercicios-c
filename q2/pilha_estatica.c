#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_estatica.h"

struct Pilha {
    int qtd;
    struct Dados texto[MAX];
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

int ins_imp_pilha_inversa (Pilha* pi, char string[]) {
    if (pi == NULL) return 0;
    if (pilha_cheia(pi)) return 0;
    int tam = strlen(string);
    for (int i=0; i<tam; i++) {
        if (string[i] == ' ' || i == tam-1) {
            impressao_parcial (pi);
            printf(" ");
            libera_pilha (pi);
            pi = cria_pilha ();
        }else {
            pi->texto[pi->qtd].x = string[i];
            pi->qtd++;
            if (pilha_cheia(pi)) return 0;
        }
        if (string[i] == '.') return 1;
    }
    return 1;
}

int remove_pilha (Pilha* pi) {
    if (pi == NULL || pi->qtd == 0) return 0;
    pi->qtd--;
    return 1;
}

int impressao_parcial (Pilha* pi) {
    if (pi == NULL || pi->qtd == 0)
        return 0;
    do {
        printf("%c", pi->texto[pi->qtd-1].x);
        remove_pilha (pi);
    }while (pi->qtd != 0);
    return 1;
}