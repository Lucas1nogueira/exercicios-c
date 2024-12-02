#include <stdio.h>
#include "fila_estatica.h"

int main () {
    Fila *fi, *fi2;
    
    fi = cria_fila ();
    fi2 = cria_fila ();

    struct Dados numeros[9] = {{5},{3},{8},
                               {4},{0},{9},
                               {7},{1},{2}};

    for (int c = 0; c < 9; c++) {
        if (!insere_fila (fi, numeros[c]))
            return 0;
    }

    if (!ordena_fila (fi, fi2))
        return 0;
    
    imprime_fila (fi2);
    
    libera_fila (fi);
    libera_fila (fi2);
    
    return 0;
}