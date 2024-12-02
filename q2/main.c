#include <stdio.h>
#include "pilha_estatica.h"

int main () {
    Pilha *pi;
    int a;
    char string[MAX];

    pi = cria_pilha ();

    printf("\nInsira um texto terminado com ponto: ");
    scanf(" %[^\n]", string);

    a = ins_imp_pilha_inversa (pi, string); // insere cada palavra separadamente na pilha e ao mesmo tempo imprime a palavra invertida na tela.

    if (a == 0) {
        printf("\nErro ao inserir pilha.");
        return 0;
    }

    libera_pilha (pi);

    return 0;
}