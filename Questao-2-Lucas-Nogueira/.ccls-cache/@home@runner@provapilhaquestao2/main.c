//Resolve a questão 2.
#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"

int main(){
    struct aluno a[4] = {{"Google","google.com"},
                         {"Facebook","facebook.com"},
                         {"Twitter","twitter.com"},
                         {"Instagram","instagram.com"}};
    
    Pilha* pi = cria_Pilha();
    Pilha* pi2 = cria_Pilha();
    
    int x;
    char nome[50];

    for (int cont=0; cont<4; cont++){
        x = insere_Pilha (pi, a[cont]);
        if (x == 0) {
            printf("\nErro ao inserir dados na pilha.");
            libera_Pilha (pi);
            return 0;
        }
    }

    printf("\nInsira um nome de um site para pesquisa: ");
    scanf("%s", nome);

    pi2 = pesquisa_site_Pilha (pi, nome);

    imprime_Pilha (pi2);

    libera_Pilha(pi);
    libera_Pilha(pi2);

    return 0;
}