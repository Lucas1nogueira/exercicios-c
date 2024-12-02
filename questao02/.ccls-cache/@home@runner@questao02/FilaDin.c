#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos

//Defini�o do tipo Fila
struct elemento {
    struct dados num;
    struct elemento *prox;
};

//Defini�o do N� Descritor da Fila
struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct dados *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->num;
    return 1;
}

int insere_Fila(Fila* fi, struct dados al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->num = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("\n%d", no->num.x);
        no = no->prox;
    }
}

void ordena_Fila (Fila* fi, Fila* fi_aux, Fila* fi_ord) {
    if (fi == NULL || fi_aux == NULL)
        return;
    int i = tamanho_Fila (fi), cont = 0;
    do {
        Elem *menor = busca_menor (fi);
        while (fi->inicio != menor) {
            insere_Fi_mod (fi_aux, fi->inicio);
            remove_Fi_mod (fi);
        }
        while (!Fila_vazia (fi_aux)) {
            if (fi_aux->inicio->prox == menor)
                fi_aux->inicio->prox = NULL;
            insere_Fi_mod (fi, fi_aux->inicio);
            remove_Fi_mod (fi_aux);
        }
        insere_Fi_mod (fi_ord, fi->inicio);
        remove_Fi_mod (fi);
        cont++;
    } while (cont != i);
}

Elem* busca_menor (Fila* fi) {
    Elem *no = fi->inicio;
    Elem *menor = fi->inicio;
    while (no->prox != NULL) {
        if (no->num.x < no->prox->num.x
            && no->num.x < menor->num.x)
            menor = no;
        if (no->prox->num.x < no->num.x
            && no->prox->num.x < menor->num.x)
            menor = no->prox;
        no = no->prox;
    }
    return menor;
}

int insere_Fi_mod (Fila* fi, Elem* no) {
    if (fi == NULL || no == NULL)
        return 0;
    if (fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fi_mod (Fila* fi) {
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    //o free foi removido, ja' que os enderecos serao manipulados.
    fi->qtd--;
    return 1;
}