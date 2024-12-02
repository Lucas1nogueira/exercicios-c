//Arquivo FilaEstatica.h
#define MAX 100

struct dados {
    int id;
    int num;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct dados *al);
int insere_Fila(Fila* fi, struct dados al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
void demultiplexador (Fila* fi_orig, Fila* fi1, Fila* fi2, Fila* fi3);