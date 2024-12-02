#include <stdio.h>
#include "fila_estatica.h"

int main () {
    Fila *fi, *fi2, *fi3;
    
    fi = cria_fila ();
    fi2 = cria_fila ();

    struct Dados numeros[4] = {{2},{4},{6},{8}};

    for (int c = 0; c < 4; c++) {
        if (!insere_fila (fi, numeros[c]))
            return 0;
    }

    struct Dados numeros2[4] = {{1},{3},{5},{7}};

    for (int c = 0; c < 4; c++) {
        if (!insere_fila (fi2, numeros2[c]))
            return 0;
    }

    fi3 = intercala_filas (fi, fi2);
    
    imprime_fila (fi3);
    
    libera_fila (fi);
    libera_fila (fi2);
    libera_fila (fi3);
    
    return 0;
}