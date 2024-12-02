#include <stdio.h>
#include "pilha_din.h"

int main () {
    Pilha *pi;
    int a, qtd, num;
    char op;

    pi = cria_pilha ();

    printf("\nDigite a quantidade de numeros a serem inseridos na pilha: ");
    scanf("%d", &qtd);

    for (int i=0; i<qtd; i++) {
        printf("\tInsira o %dº numero: ", i+1);
        scanf("%d", &num);
        a = insere_pilha (pi, num);
        if (a == 0) {
            printf("\nErro ao inserir pilha(s).");
            return 0;
        }
    }

    pi = organiza_pilha (pi, qtd); // reformula a pilha para que fique em ordem crescente.

    printf("\nPilha organizada:");

    pi = inverte_pilha (pi); // inverte a pilha organizada para que ao ser desempilhada seja exibida de forma correta.
    
    exibe_pilha (pi);

    libera_pilha (pi);
    
    return 0;
}