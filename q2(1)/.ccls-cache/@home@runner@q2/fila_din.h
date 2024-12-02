struct Dados {
    int num;
};

typedef struct fila Fila;

Fila* cria_fila ();

void libera_fila (Fila* fi);

int tamanho_fila (Fila* fi);

int fila_cheia (Fila* fi);

int fila_vazia (Fila* fi);

int insere_fila (Fila* fi, struct Dados x);

int remove_fila (Fila* fi);

int consulta_fila (Fila* fi, struct Dados *y);

int ordena_fila (Fila* fi, Fila* fi2, Fila* fi3);

void imprime_fila (Fila* fi);