#include <stdio.h>
#include "lista_circular.h"

int main (void) {
    Lista *li = cria_lista ();

    struct aluno alns[10] = {{7, "Tiago", 10.0, 8.0, 9.0},
                            {1, "Joao", 8.0, 7.5, 9.5},
                            {3, "Pedro", 7.0, 9.0, 7.5},
                            {10, "Mateus", 6.5, 8.0, 9.0},
                            {4, "Lucas", 8.0, 8.5, 5.0},
                            {2, "Rafael", 10.0, 9.0, 7.5},
                            {9, "Bernardo", 5.5, 6.5, 8.5},
                            {5, "Tadeu", 7.5, 10.0, 5.0},
                            {8, "Jose", 6.5, 8.5, 9.0},
                            {6, "Andre", 8.5, 8.0, 9.5}};

    for (int i=0; i<10; i++)
        insere_lista_ordenada (li, alns[i]);

    imprimir_lista (li);

    int tam = tamanho_lista (li);
    printf ("\nTamanho da lista: %d", tam);

    libera_lista (li);

    return 0;
}