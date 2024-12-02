#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main () {
    Fila *fi_orig = cria_Fila ();
    Fila *fi1 = cria_Fila ();
    Fila *fi2 = cria_Fila ();
    Fila *fi3 = cria_Fila ();

    int id, num;
    struct dados inserir;

    printf ("\nInsira um ID de fila (1, 2, 3) e um numero.");
    printf ("\nDigite -1 para terminar a sequencia.");

    do {
        printf ("\n\n\tID: ");
        scanf ("%d", &id);
        if (id == -1) break;
        if (id != 1 && id != 2 && id != 3)
            printf ("\nErro: ID deve ser de 1 a 3.\n");
        printf ("\n\tNumero: ");
        scanf ("%d", &num);
        inserir.id = id;
        inserir.num = num;
        insere_Fila (fi_orig, inserir);
    } while (id != -1);

    printf ("\nFILA ORIGINAL:\n");
    imprime_Fila (fi_orig);

    demultiplexador (fi_orig, fi1, fi2, fi3);

    printf ("\n\n\n");

    printf ("\nFILA 1:\n");
    imprime_Fila (fi1);

    printf ("\nFILA 2:\n");
    imprime_Fila (fi2);

    printf ("\nFILA 3:\n");
    imprime_Fila (fi3);

    libera_Fila (fi_orig);
    libera_Fila (fi1);
    libera_Fila (fi2);
    libera_Fila (fi3);

    return 0;
}