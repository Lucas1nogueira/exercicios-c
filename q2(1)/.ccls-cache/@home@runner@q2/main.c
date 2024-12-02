#include <stdio.h>
#include "fila_din.h"

int main () {
    Fila *fi, *fi2, *fi3;

    fi = cria_fila ();
    fi2 = cria_fila ();
    fi3 = cria_fila ();

    struct Dados numeros[4] = {{1}, {6}, {8}, {9}};

    for (int cont = 0; cont < 4; cont++) {
        insere_fila (fi, numeros[cont]);
    }

    struct Dados numeros2[4] = {{3}, {7}, {10}, {12}};

    for (int cont2 = 0; cont2 < 4; cont2++) {
        insere_fila (fi2, numeros2[cont2]);
    }

    ordena_fila (fi, fi2, fi3);

    imprime_fila (fi3);

    libera_fila (fi);
    libera_fila (fi2);
    libera_fila (fi3);
    
    return 0;
}