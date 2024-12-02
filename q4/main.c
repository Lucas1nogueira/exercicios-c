#include <stdio.h>
#include "pilha_din.h"

int main () {
    Pilha *pi;
    char expressao[50];
    int a;

    pi = cria_pilha ();

    printf("\nInsira uma expressao matematica com parentesis: ");
    scanf(" %[^\n]", expressao);

    a = insere_pilha (pi, expressao);

    if (a == 0) {
        printf("\nErro ao inserir pilha.");
        return 0;
    }

    pi = inverte_pilha (pi); // inverte a pilha para que fique do modo como foi digitada.
    
    if (verifica_expressao (pi))
        printf("\n\nA expressao foi digitada corretamente.");
    else
        printf("\n\nErro: A expressao esta' incorreta.");

    libera_pilha (pi);
    
    return 0;
}