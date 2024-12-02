#include <stdio.h>
#include "pilha_estatica.h"

int main () {
    Pilha *pi;
    int a, n;

    pi = cria_pilha ();

    printf("\nDigite n valores (30 ao maximo) para exibir na sequencia de Fibonacci: ");
    scanf("%d", &n);

    a = insere_n_pilha (pi, n);

    if (a == 0) {
        printf("\nErro ao inserir pilha.");
        return 0;
    }

    pi = inverte_pilha (pi); // inverte a pilha para que seja exibida corretamente na tela ao ser desempilhada.

    exibe_pilha (pi); // vai desempilhando e imprimindo a pilha na tela.

    libera_pilha (pi);

    return 0;
}