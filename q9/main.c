#include <stdio.h>
#include <string.h>
#include "pilha_din.h"

int main () {
    Pilha *pi, *pi2;
    char txt[200];
    int a, op=0;
    char escolha[5];

    pi = cria_pilha ();

    pi2 = cria_pilha ();

    printf("\nInsira um texto, no qual cada palavra contenha no maximo 50 caracteres: ");
    scanf(" %[^\n]", txt);

    verifica_string (pi, txt);

    printf("\nDigite agora '-' seguido de enter para desempilhar a ultima palavra (RENDO), ou '+' para reinserir a ultima palavra que foi removida (UNDO), ou 'exit' para sair.");
    
    do {
        printf("\n\nInsira uma opcao: ");
        scanf("%s", escolha);
        if (strcmp (escolha, "-") == 0) {
            if (remove_pilha (pi, pi2) == 0)
                printf("\nImpossivel realizar RENDO!");
        }
        if (strcmp (escolha, "+") == 0) {
            if (remove_pilha (pi2, pi) == 0)
                printf("\nImpossivel realizar UNDO!");
        }
        if (strcmp (escolha, "exit") == 0) {
            printf("\nFinalizando...");
            op = 1;
        }
    }while (op != 1);

    libera_pilha (pi);

    libera_pilha (pi2);
    
    return 0;
}