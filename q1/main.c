#include <stdio.h>
#include "pilha_din.h"

int main () {
    Pilha *pi, *pi2;
    char string1[30], string2[30];
    int a, b;

    pi = cria_pilha ();

    pi2 = cria_pilha ();

    printf("\nInsira a primeira string: ");
    scanf("%s", string1);

    printf("\nInsira a segunda string: ");
    scanf("%s", string2);

    a = insere_pilha (pi, string1);

    b = insere_pilha (pi2, string2);

    if (a == 0 || b == 0) {
        printf("\nErro ao inserir pilha(s).");
        return 0;
    }

    pi = inverte_pilha (pi);
    
    if (comp_pilhas (pi, pi2))
        printf("\n\nVerdadeiro: As strings sao reversas.");
    else
        printf("\n\nFalso: As strings nao sao reversas.");

    libera_pilha (pi);

    libera_pilha (pi2);
    
    return 0;
}