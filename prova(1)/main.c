#include <stdio.h>
#include <stdlib.h>
#include "lista_din_encad_dupla.h"

int main () {
    struct filme flms[4] = {{2, "Acao", 50.0, 5},
                            {5, "Aventura", 70.0, 6},
                            {3, "Drama", 45.0, 2},
                            {8, "Comedia", 67.5, 7}};

    Lista* li = cria_lista ();

    for (int i=0; i < 4; i++)
        insere_lista_ordenada (li, flms[i]);

    imprime_lista (li);

    printf ("\nTamanho da lista: %d\n", tamanho_lista (li));

    soma_valores (li);

    libera_lista (li);

    return 0;
}