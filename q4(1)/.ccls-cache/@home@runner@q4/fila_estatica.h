#define MAX 100

struct Dados {
    int num;
};

typedef struct fila Fila;

Fila* cria_fila ();

void libera_fila (Fila* fi);

int tamanho_fila (Fila* fi);

int fila_cheia (Fila* fi);

int insere_fila (Fila* fi, struct Dados x); // sempre no final.

int remove_fila (Fila* fi);

int consulta_fila (Fila* fi, struct Dados *y);

Fila* intercala_filas (Fila* fi, Fila* fi2);

void imprime_fila (Fila* fi);