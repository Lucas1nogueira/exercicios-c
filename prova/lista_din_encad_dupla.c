#include <stdio.h>
#include <stdlib.h>
#include "lista_din_encad_dupla.h" //inclui os Prototipos

//Definicao do tipo lista
struct elemento{
    struct elemento *ant;
    struct filme flm;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista (Lista* li) {
    if (li != NULL && (*li) != NULL) {
        Elem *ant, *no = *li;
        while (no->prox != (*li)) {
            ant = no;
            no = no->prox;
            free (ant);
        }
        free (no);
        free (li);
    }
}

int consulta_lista_cod (Lista* li, int cod, struct filme *fi) {
    if (li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;
    while (no->prox != (*li) && no->flm.codfilme != cod)
        no = no->prox;
    if (no->flm.codfilme != cod)
        return 0;
    else {
        *fi = no->flm;
        return 1;
    }
}

int insere_lista_ordenada (Lista* li, struct filme fi) {
    if (li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->flm = fi;
    if ((*li) == NULL) { //lista vazia: insere inicio
        no->prox = no;
        no->ant = no;
        *li = no;
        return 1;
    }
    else {
        if (fi.codfilme < (*li)->flm.codfilme) {
            Elem *ultimo = *li;
            while (ultimo->prox != (*li)) //procura o ultimo
                ultimo = ultimo->prox;
            no->prox = *li;
            no->prox->ant = no;
            ultimo->prox = no;
            no->ant = ultimo->ant->prox;
            *li = no;
            return 1;
        }
        Elem *anterior = *li, *atual = (*li)->prox;
        while (atual != (*li) && atual->flm.codfilme < fi.codfilme) {
            anterior = atual;
            atual = atual->prox;
        }
        no->prox = anterior->prox;
        no->ant = anterior;
        anterior->prox = no;
        atual->ant = no;
    }
    return 1;
}

int remove_lista_inicio (Lista* li) {
    if (li == NULL || (*li) == NULL)
        return 0;
    if ((*li)->prox == (*li)) {
        free (*li);
        *li = NULL;
        return 1;
    }
    Elem *ultimo = *li;
    while (ultimo->prox != (*li)) //procura o ultimo
        ultimo = ultimo->prox;
    Elem *no = *li;
    *li = no->prox;
    ultimo->prox = no->prox;
    no->prox->ant = ultimo->ant->prox;
    free (no);
    return 1;
}

int tamanho_lista (Lista* li) {
    if (li == NULL || (*li) == NULL)
        return 0;
    int cont = 1;
    Elem* no = *li;
    while (no->prox != (*li)) {
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
    if (*li == NULL)
        return 1;
    return 0;
}

void imprime_lista (Lista* li) {
    if (li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do {
        printf ("\nCodigo: %d\n", no->flm.codfilme);
        printf ("Titulo: %s\n", no->flm.titulo);
        printf ("Valor: R$ %.2f\n", no->flm.valor);
        printf ("Estoque: %d\n", no->flm.qtdEstoque);
        printf ("- - - - - - - - - - -\n");
        no = no->prox;
    } while (no != (*li));
}

void soma_valores (Lista* li) {
    if (li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    float soma = 0;
    do {
        soma = soma + no->flm.valor;
        no = no->prox;
    } while (no != (*li));
    printf ("\nSoma dos valores = R$ %.2f\n", soma);
}