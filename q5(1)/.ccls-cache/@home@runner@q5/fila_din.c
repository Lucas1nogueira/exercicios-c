#include <stdio.h>
#include <stdlib.h>
#include "fila_din.h"

struct fila {
    struct elemento *inicio;
    struct elemento *final;
};

struct elemento {
    int num;
    struct elemento *prox;
};

typedef struct elemento Elm;

Fila* cria_fila () {
    Fila* fi = (Fila*) malloc (sizeof(Fila));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
    }
    return fi;
}

void libera_fila (Fila* fi) {
    if (fi != NULL) {
        Elm *no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free (no);
        }
        free (fi);
    }
}

int tamanho_fila (Fila* fi) {
    if (fi == NULL) return 0;
    int cont = 0;
    Elm *no = fi->inicio;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_cheia (Fila* fi) {
    return 0;
}

int fila_vazia (Fila* fi) {
    if (fi == NULL) return 1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_fila (Fila* fi, int x) {
    if (fi == NULL) return 0;
    Elm *no = (Elm*) malloc (sizeof(Elm));
    if (no == NULL) return 0;
    no->num = x;
    no->prox = NULL;
    if (fi->final == NULL) //fila vazia.
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

int remove_fila (Fila* fi) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) //fila vazia.
        return 0;
    Elm *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL) //fila ficou vazia.
        fi->final = NULL;
    free (no);
    return 1;
}

int consulta_fila (Fila* fi, int *y) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL) //fila vazia.
        return 0;
    *y = fi->inicio->num;
    return 1;
}

void imprime_fila (Fila* fi) {
    if (fi == NULL)
        return;
    Elm *no = fi->inicio;
    while (no != NULL) {
        printf ("\n%d", no->num);
        no = no->prox;
    }
}