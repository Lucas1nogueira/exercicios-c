#include <stdio.h>
#include "pilha_din.h"

int main () {
    Pilha *pi;
    int a, op;
    char letra;

    pi = cria_pilha ();

    a = insere_pilha (pi, 'A'); if (a == 0) return 0;
    a = insere_pilha (pi, 'B'); if (a == 0) return 0;
    a = insere_pilha (pi, 'C'); if (a == 0) return 0;
    a = insere_pilha (pi, 'D'); if (a == 0) return 0;

    printf("\nEsta pilha contem os caracteres A, B, C e D.");

    do {
        printf("\nDigite 1 para exibir o topo da pilha e remove-lo, ou 0 para sair: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (exibe_topo_pilha (pi, &letra) == 0) {
                    printf("\nA pilha foi esvaziada! Saindo...");
                    libera_pilha (pi);
                    return 0;
                }
                printf("\nTopo da pilha: %c.\n", letra);
                remove_pilha (pi);
                break;
            case 0:
                printf("\nFinalizando...");
                break;
            default:
                printf("\nOpcao invalida.");
                break;
        }
    }while (op != 0);

    libera_pilha (pi);
    
    return 0;
}