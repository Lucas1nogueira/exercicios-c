#include <stdio.h>
#include <string.h>
#include "fila_estatica.h"

int main () {
    Fila *fi, *fi2, *fi_espera;
    
    fi = cria_fila ();
    fi2 = cria_fila ();
    fi_espera = cria_fila ();
    
    char op;

    printf ("\nESTACIONAMENTO\n");

    do {
        printf ("\n\n-- Menu --\n");
        printf ("\nC: Realiza a chegada de um novo carro.");
        printf ("\nP: Realiza a partida de um carro ja' existente.");
        printf ("\n0: Sai do programa.");
        printf ("\n*OBS - A letra deve ser maiuscula.");
        printf ("\n\nSua escolha -> ");
        scanf (" %c", &op);
        switch (op) {
            case 'C':
                if (fila_cheia (fi)) {
                    printf ("\nNao ha' vagas disponiveis!");
                    printf ("\nEste carro ira' esperar por uma vaga.");
                    struct Dados espera;
                    espera.deslocamento = 0;
                    printf ("\nInsira a nova placa: ");
                    scanf (" %s", espera.placa);
                    insere_fila (fi_espera, espera);
                } else {
                    struct Dados insercao;
                    printf ("\nVaga disponivel!");
                    insercao.deslocamento = 0;
                    printf ("\nInsira a nova placa: ");
                    scanf (" %s", insercao.placa);
                    if (insere_fila (fi, insercao)) {
                        printf ("O carro (%s) estacionou!\n", insercao.placa);
                        printf ("\nFILA DE CARROS ESTACIONADOS:\n");
                        imprime_fila (fi);
                    }
                }
                break;
            case 'P':
                printf ("Insira a placa do carro que ira' partir: ");
                char placa;
                scanf (" %s", &placa);
                int pos;
                if (busca_carro (fi, &placa, &pos)) {
                    int verif = fila_cheia (fi); // verifica se a fila esta' cheia antes de retirar o carro.
                    retira_carro (fi, fi2, pos);
                    if (verif == 1 && fila_vazia (fi_espera) == 0) { // se vdd, poe o primeiro carro da espera na fila.
                        struct Dados carro_espera = acesso_espera (fi_espera);
                        insere_fila (fi, carro_espera);
                        printf ("\nO carro (%s) da lista de espera entrou na fila.",
                                                            carro_espera.placa);
                    }
                    if (fila_vazia (fi) != 1) {
                        printf ("\nFILA DE CARROS ESTACIONADOS:\n");
                        imprime_fila (fi);
                    }
                } else {
                    printf ("\nCarro nao encontrado!");
                    printf ("\n- Buscando na 1ª posicao da fila de espera...");
                    struct Dados car_esp;
                    consulta_fila (fi_espera, &car_esp);
                    if (strcmp (car_esp.placa, &placa) == 0) {
                        printf ("\nEncontrado na espera.");
                        printf ("\nO carro (%s) se deslocou %d vezes.\n",
                            car_esp.placa, car_esp.deslocamento);
                    } else {
                        printf ("\nNao esta' na fila de espera tambem!");
                    }
                }
                break;
            case '0':
                printf ("\nSaindo do programa...");
                break;
            default:
                printf ("\nOpcao invalida!\n");
                break;
        }
    } while (op != '0');
    
    libera_fila (fi);
    libera_fila (fi2);
    libera_fila (fi_espera);
    
    return 0;
}