#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h" //inclui os Prot�tipos

//Defini�o do tipo Fila
struct fila{
    int inicio, final;
    struct dados info[MAX];
};

Fila* cria_Fila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    free(fi);
}

int consulta_Fila(Fila* fi, struct dados *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    int pos = (fi->inicio+1)%MAX;
    *al = fi->info[pos];
    return 1;
}

int insere_Fila(Fila* fi, struct dados al){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi->final = (fi->final+1)%MAX;
    fi->info[fi->final] = al;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return -1;
    int qtd = abs(fi->final - fi->inicio);
    return qtd;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi->inicio == (fi->final+1)%MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    return (fi->inicio == fi->final);
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int i = fi->inicio;
    while(i != fi->final){
        i = (i + 1) % MAX;
        printf ("\nID: %d", fi->info[i].id);
        printf ("\nNumero: %d", fi->info[i].num);
        printf ("\n-----------\n");
    }
}

void demultiplexador (Fila* fi_orig, Fila* fi1, Fila* fi2, Fila* fi3) {
    if (fi_orig == NULL || fi1 == NULL || fi2 == NULL || fi3 == NULL)
        return;
    if (Fila_vazia (fi_orig))
        return;
    int j = fi_orig->inicio;
    while (j != fi_orig->final+1) {
        if (fi_orig->info[j].id == 1)
            insere_Fila (fi1, fi_orig->info[j]);
        if (fi_orig->info[j].id == 2)
            insere_Fila (fi2, fi_orig->info[j]);
        if (fi_orig->info[j].id == 3)
            insere_Fila (fi3, fi_orig->info[j]);
        j = (j + 1) % MAX;
    }
}