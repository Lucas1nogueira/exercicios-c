#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_circular.h"

struct elemento {
    struct aluno dados;
    struct  elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista () {
    Lista* li = (Lista*) malloc (sizeof (Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista (Lista* li) {
    Elem *no = *li;
    if (tamanho_lista (li) == 1) {
        free (no);
        free (li);
        return;
    }
    while (no->prox != *li) {
        Elem *no2 = *li;
        while (no2->prox != *li)
            no2 = no2->prox;
        no2->prox = no->prox;
        *li = no->prox;
        free (no);
    }
    free (li);
}

int tamanho_lista (Lista* li) {
    if (li == NULL)
        return 0;
    int cont = 1;
    Elem* no = *li;
    while (no->prox != *li) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia (Lista* li) {
    return 0;
}

int lista_vazia (Lista* li) {
    if (li == NULL)
        return 1;
    if ((*li) == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio (Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem* no = (Elem*) malloc (sizeof (Elem));
    if (no == NULL) return 0;
    no->dados = al;
    if (lista_vazia (li)) {
        no->prox = no;
        *li = no;
    } else {
        Elem* no2 = *li;
        while (no2->prox != *li)
            no2 = no2->prox;
        no->prox = *li;
        *li = no;
        no2->prox = *li;
    }
    return 1;
}

int insere_lista_final (Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    Elem* no = (Elem*) malloc (sizeof (Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if (lista_vazia (li)) {
        no->prox = no;
        *li = no;
    } else {
        Elem* no2 = *li;
        while (no2->prox != *li)
            no2 = no2->prox;
        no->prox = *li;
        no2->prox = no;
    }
    return 1;
}

int insere_lista_ordenada (Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem *no = (Elem*) malloc (sizeof (Elem));
    if (no == NULL) return 0;
    no->dados = al;
    if (lista_vazia(li)) { //insere inicio
        no->prox = no;
        *li = no;
    } else {
        Elem *ant, *atual = *li;
        while (atual->prox != *li
               && atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { //insere inicio
            Elem *no_final = *li;
            while (no_final->prox != *li)
                no_final = no_final->prox;
            no->prox = (*li);
            no_final->prox = no;
            *li = no;
        } else {
            if (al.matricula > atual->dados.matricula) {
                no->prox = atual->prox;
                atual->prox = no;
            } else {
                no->prox = atual;
                ant->prox = no;
            }
        }
    }
    return 1;
}

int remove_lista_inicio (Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    Elem *no = *li;
    Elem *no2 = *li;
    while (no2->prox != *li)
        no2 = no2->prox;
    no2->prox = no->prox;
    *li = no->prox;
    free (no);
    return 1;
}

int remove_lista_final (Lista* li) {
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    Elem *no = *li;
    Elem *no2;
    while (no->prox != *li) {
        no2 = no;
        no = no->prox;
    }
    no2->prox = *li;
    free (no);
    return 1;
}

int remove_lista_pos (Lista* li, int pos) {
    if (li == NULL)
        return 0;
    Elem *ant, *no = *li;
    int cont = 1;
    while (no->prox != *li && cont != pos) {
        ant = no;
        no = no->prox;
        cont++;
    }
    if (no == *li) {
        Elem *no_final = *li;
        while (no_final->prox != *li)
            no_final = no_final->prox;
        no_final->prox = no->prox;
        *li = no->prox;
    } else
        ant->prox = no->prox;
    free (no);
    return 1;
}

int remove_lista_mat (Lista* li, int mat) {
    if (li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no->prox != *li && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == *li) {
        Elem *no_final = *li;
        while (no_final->prox != *li)
            no_final = no_final->prox;
        no_final->prox = no->prox;
        *li = no->prox;
    } else
        ant->prox = no->prox;
    free (no);
    return 1;
}

int remove_lista_nome (Lista* li, char nome[]) {
    if (li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no->prox != *li
           && strcmp (no->dados.nome, nome) != 0) {
        ant = no;
        no = no->prox;
    }
    if (no == *li) {
        Elem *no_final = *li;
        while (no_final->prox != *li)
            no_final = no_final->prox;
        no_final->prox = no->prox;
        *li = no->prox;
    } else
        ant->prox = no->prox;
    free (no);
    return 1;
}

int consulta_lista_pos (Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i =  1;
    while (no->prox != *li && i < pos) {
        no = no->prox;
        i++;
    }
    *al = no->dados;
    return 1;
}

int consulta_lista_matricula (Lista* li, int mat, struct aluno *al) {
    if (li == NULL || mat <= 0)
        return 0;
    Elem *no = *li;
    while (no->prox != *li && no->dados.matricula != mat) {
        no = no->prox;
    }
    *al = no->dados;
    return 1;
}

int consulta_lista_nome (Lista* li, char nome[], struct aluno *al) {
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no->prox != *li
           && strcmp (no->dados.nome, nome) != 0) {
        no = no->prox;
    }
    *al = no->dados;
    return 1;
}

void imprimir_lista (Lista* li) {
    if (lista_vazia (li)) {
        printf ("\nLista vazia!\n\n");
        return;
    }
    Elem* no = *li;
    do {
        printf("\nMat.: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("1a nota: %.2f\n", no->dados.n1);
        printf("2a nota: %.2f\n", no->dados.n2);
        printf("3a nota: %.2f\n", no->dados.n3);
        printf("- - - - - - - -\n");
        no = no->prox;
    } while (no != *li);
}