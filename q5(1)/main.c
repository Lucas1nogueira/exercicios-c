#include <stdio.h>
#include "fila_din.h"

int main () {
    Fila *fi;

    fi = cria_fila ();

    int numeros[5] = {1, 2, 3, 4, 5};

    for (int cont = 0; cont < 5; cont++) {
        insere_fila (fi, numeros[cont]);
    }

    imprime_fila (fi);

    libera_fila (fi);
    
    return 0;
}