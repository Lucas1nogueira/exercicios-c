#include <stdio.h>
#include "pilha_estatica.h"

int main () {
    Pilha *pi;
    int a, tam, num, pares=0;

    pi = cria_pilha ();

    printf("\nInsira a quantidade de numeros para a pilha (maximo de 50): ");
    scanf("%d", &tam);

    for (int i=0; i<tam; i++) {
        printf("\nInsira o %dº numero: ", i+1);
        scanf("%d", &num);
        a = insere_pilha (pi, num);
        if (a == 0) {
            printf("\nErro ao inserir pilha.");
            return 0;
        }
    }
    
    conta_pares (pi, &pares);

    printf("\nO numero de elementos pares da pilha e' de: %d", pares);
    
    libera_pilha (pi);

    return 0;
}