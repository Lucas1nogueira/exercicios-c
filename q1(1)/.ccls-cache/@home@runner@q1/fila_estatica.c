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

int ordena_fila (Fila* fi, Fila* fi2) {
    if (fi == NULL || fi2 == NULL)
        return 0;
    int aux = fi->inicio;
    int cont = fi->inicio;
    while (cont != fi->final) {
        if (fi->info[cont].num < fi->info[aux].num)
            aux = cont;
        cont = (cont+1) % MAX;
    }
    insere_fila (fi2, fi->info[aux]);
    int var = 0;
    while (fi2->qtd != fi->qtd) {
        var = var + 1;
        cont = fi->inicio;
        while (cont != fi->final) {
            if (fi->info[cont].num == fi2->info[fi2->final-1].num+var) {
                insere_fila (fi2, fi->info[cont]);
                var = 0;
                break;
            }
            cont = (cont+1) % MAX;
        }
    }
    return 1;
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