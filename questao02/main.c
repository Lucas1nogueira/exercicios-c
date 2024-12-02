#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main () {
    struct dados n[9] = {{22},{58},{37},
                         {75},{10},{60},
                         {43},{15},{90}};

    Fila* fi = cria_Fila ();
    Fila* fi_aux = cria_Fila ();
    Fila* fi_ord = cria_Fila ();

    int i;
    for (i=0; i < 9; i++) {
        insere_Fila (fi, n[i]);
    }

    printf ("\nFILA ORIGINAL: ");
    imprime_Fila (fi);

    printf ("\n\nFILA ORDENADA: ");
    ordena_Fila (fi, fi_aux, fi_ord);
    imprime_Fila (fi_ord);

    libera_Fila (fi);
    libera_Fila (fi_aux);
    libera_Fila (fi_ord);

    return 0;
}