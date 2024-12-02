#include <stdio.h>
#include "pilha_estatica.h"

int main() {
    Pilha *pi, *pi2;
    char string[MAX];
    int a, b;

    pi = cria_pilha ();

    pi2 = cria_pilha ();

    printf("\nInsira uma palavra: ");
    scanf("%s", string);

    a = insere_pilha (pi, string);

    b = insere_pilha (pi2, string);

    if (a == 0 || b == 0) {
        printf("\nErro ao inserir pilha(s).");
        return 0;
    }

    pi2 = inverte_pilha (pi2); // insere a mesma string de forma invertida na segunda pilha para verificar se e' palindromo.

    if (comp_pilhas (pi, pi2))
        printf("\nVerdadeiro: a palavra e' um palindromo.");
    else
        printf("\nFalso: a palavra NAO e' um palindromo.");

    libera_pilha (pi);

    libera_pilha (pi2);
    
    return 0;
}