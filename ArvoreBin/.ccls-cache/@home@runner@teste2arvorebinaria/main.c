#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main () {
    int N = 8, dados[8] = {10,22,34,45,55,65,80,95};

    ArvBin* raiz = cria_ArvBin ();

    for (int i = 0; i < N; i++)
        insere_ArvBin (raiz, dados[i]);

    preOrdem_ArvBin (raiz);

    float md_ar = media_aritmetica (raiz);
    printf ("\nA media aritmetica da arvore e' de: %.2f", md_ar);

    libera_ArvBin (raiz);

    return 0;
}