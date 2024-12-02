#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main () {
    Fila *fi_orig = cria_Fila ();
    Fila *fi_vd = cria_Fila ();
    Fila *fi_am = cria_Fila ();
    Fila *fi_ve = cria_Fila ();

    struct dados pessoas[10] = {{"Joao", 1000, prior_aleat ()},
                                {"Maria", 2000, prior_aleat ()},
                                {"Alex", 3000, prior_aleat ()},
                                {"Pedro", 4000, prior_aleat ()},
                                {"Lucas", 5000, prior_aleat ()},
                                {"Marta", 6000, prior_aleat ()},
                                {"Marcos", 7000, prior_aleat ()},
                                {"Jonas", 8000, prior_aleat ()},
                                {"Lazaro", 9000, prior_aleat ()},
                                {"Tiago", 10000, prior_aleat ()}};

    for (int i=0; i<10; i++) {
        insere_Fila (fi_orig, pessoas[i]);
    }

    printf ("\nPESSOAS NA FILA:\n");
    imprime_Fila (fi_orig);

    gerencia_socorro (fi_orig, fi_vd, fi_am, fi_ve);

    printf ("\n\n\nAtendendo pacientes...\n\n\n");
    atende_fila (fi_ve);
    atende_fila (fi_am);
    atende_fila (fi_vd);

    libera_Fila (fi_orig);

    return 0;
}


