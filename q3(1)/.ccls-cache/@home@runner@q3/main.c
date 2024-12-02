#include <stdio.h>
#include "fila_estatica.h"

int main () {
    Fila *fi, *fi2;
    
    fi = cria_fila ();
    fi2 = cria_fila ();

    struct Dados numeros[3] = {{10},{70},{30}};

    for (int c = 0; c < 3; c++) {
        if (!insere_fila (fi, numeros[c]))
            return 0;
    }

    struct Dados numeros2[3] = {{40},{60},{100}};

    for (int c = 0; c < 3; c++) {
        if (!insere_fila (fi, numeros2[c]))
            return 0;
    }

    if (!concatena_filas (fi, fi2))
        return 0;
    
    imprime_fila (fi);
    
    libera_fila (fi);
    libera_fila (fi2);
    
    return 0;
}