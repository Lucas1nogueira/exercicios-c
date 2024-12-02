#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

struct fila {
    int inicio, final, qtd;
    struct Dados info[MAX];
};

Fila* cria_fila () {
    Fila *fi = (Fila*) malloc (sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila (Fila* fi) {
    free (fi);
}

int tamanho_fila (Fila* fi) {
    if (fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_cheia (Fila* fi) {
    if (fi == NULL) return -1;
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int fila_vazia (Fila* fi) {
    if (fi == NULL) return -1;
    if (fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_fila (Fila* fi, struct Dados x) {
    if (fi == NULL) return 0;
    if (fila_cheia (fi)) return 0;
    fi->info[fi->final] = x;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int remove_fila (Fila* fi) {
    if (fi == NULL || fila_vazia (fi))
        return 0;
    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    return 1;
}

int consulta_fila (Fila* fi, struct Dados *y) {
    if (fi == NULL || fila_vazia (fi))
        return 0;
    *y = fi->info[fi->inicio];
    return 1;
}

Fila* intercala_filas (Fila* fi, Fila* fi2) {
    Fila* fi3 = cria_fila ();
    int cont = fi->inicio;
    int cont2 = fi2->inicio;
    while (cont != fi->final && cont2 != fi->final) {
        insere_fila (fi3, fi->info[cont]);
        insere_fila (fi3, fi2->info[cont2]);
        cont = (cont+1) % MAX;
        cont2 = (cont2+1) % MAX;
    }
    return fi3;
}

void imprime_fila (Fila* fi) {
    if (fi == NULL || fi->qtd == 0)
        return;
    int cont = fi->inicio;
    while (cont != fi->final) {
        printf ("\n%d", fi->info[cont].num);
        cont = (cont+1) % MAX;
    }
}