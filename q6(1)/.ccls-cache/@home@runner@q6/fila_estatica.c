#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void imprime_fila (Fila* fi) {
    if (fi == NULL || fi->qtd == 0)
        return;
    int cont = fi->inicio;
    while (cont != fi->final) {
        printf ("\n%s", fi->info[cont].placa);
        printf (" -- %d deslocamentos.\n",
                fi->info[cont].deslocamento);
        cont = (cont+1) % MAX;
    }
}

int busca_carro (Fila* fi, char placa[], int *pos) {
    if (fi == NULL || fila_vazia (fi))
        return 0;
    int cont = fi->inicio;
    while (cont != fi->final) {
        if (strcmp (fi->info[cont].placa, placa) == 0) {
            *pos = cont;
            return 1;
        }
        cont = (cont+1) % MAX;
    }
    return 0;
}

void retira_carro (Fila* fi, Fila* fi2, int pos) {
    int cont = fi->inicio;
    while (cont != pos) {
        fi->info[cont].deslocamento += 1;
        insere_fila (fi2, fi->info[cont]);
        remove_fila (fi);
        cont = fi->inicio;
    }
    fi->info[cont].deslocamento += 1;
    printf ("\nCarro retirado com sucesso!");
    printf ("\nO carro (%s) se deslocou %d vezes.\n",
                                fi->info[cont].placa,
                                fi->info[cont].deslocamento);
    remove_fila (fi);
    int cont2 = fi2->inicio;
    while (cont2 != fi2->final) {
        insere_fila (fi, fi2->info[cont2]);
        remove_fila (fi2);
        cont2 = fi2->inicio;
    }
}

struct Dados acesso_espera (Fila* fi_espera) {
    struct Dados carro_esp = fi_espera->info[fi_espera->inicio];
    return carro_esp;
}