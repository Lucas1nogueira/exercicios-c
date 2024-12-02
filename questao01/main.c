#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main(){
    struct cliente normal[4] = {{"Andre", 10, 'N'},
                           {"Ricardo", 20, 'N'},
                           {"Bianca", 30, 'N'},
                           {"Ana", 40, 'N'}};

    struct cliente prioridade[4] = {{"Joao", 50, 'P'},
                                 {"Pedro", 60, 'P'},
                                 {"Alex", 70, 'P'},
                                 {"Edu", 80, 'P'}};

    Fila* fi_normal = cria_Fila();
    Fila* fi_prioridade = cria_Fila();
    Fila* fi_atendimento = cria_Fila();
    
    int i;
    for (i=0; i < 4; i++) {
        insere_Fila (fi_normal, normal[i]);
        insere_Fila (fi_prioridade, prioridade[i]);
    }

    printf ("\nFILA NORMAL:\n");
    imprime_Fila (fi_normal);
    printf ("\n\n");

    printf ("\nFILA PRIORIDADE:\n");
    imprime_Fila (fi_prioridade);
    printf ("\n\n");

    fila_atendimento (fi_normal,
                      fi_prioridade,
                      fi_atendimento);

    printf ("\nFILA DE ATENDIMENTO:\n");
    imprime_Fila (fi_atendimento);

    libera_Fila (fi_normal);
    libera_Fila (fi_prioridade);
    libera_Fila (fi_atendimento);
    
    return 0;
}