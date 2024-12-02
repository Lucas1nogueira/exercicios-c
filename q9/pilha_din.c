#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_din.h"

struct Elemento {
    struct Dados texto;
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
    Elm* no = (Elm*) malloc(sizeof(Elm));
    if (no == NULL) return 0;
    strcpy (no->texto.palavra, string);
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_pilha (Pilha* pi, Pilha* pi2) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;
    if (pi != NULL) {
        Elm *no = *pi;
        consulta_topo_pilha (pi);
        insere_pilha (pi2, (*no).texto.palavra); // insere a palavra que sera' removida de uma pilha para outra.
        *pi = no->prox;
        free(no);
    }
    return 1;
}

int consulta_topo_pilha (Pilha* pi) {
    if (pi == NULL) return 0;
    if ((*pi) == NULL) return 0;
    printf("\n%s", (*pi)->texto.palavra);
    return 1;
}

void verifica_string (Pilha* pi, char txt[]) {
    int tam = strlen (txt);
    char aux[50];
    int pos=0, pos2=0, i=0, j=0;
    for (i=0; i<tam; i++) {
        if (txt[i] == ' ') {
            pos = i;
            j=0;
            do {
                aux[j] = txt[pos2];
                j++;
                pos2++;
            }while (pos2 != pos);
            aux[j] = '\0';
            pos2 = pos+1;
            insere_pilha (pi, aux); // insere cada palavra separadamente na pilha.
        }
        if (i == tam-1) {
            j=0;
            do {
                aux[j] = txt[pos2];
                j++;
                pos2++;
            }while (txt[pos2] != '\0');
            aux[j] = '\0';
            insere_pilha (pi, aux); // insere a ultima palavra do texto na pilha.
        }
    }
}