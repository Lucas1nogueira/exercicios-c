typedef struct fila Fila;

Fila* cria_fila ();

void libera_fila (Fila* fi);

int tamanho_fila (Fila* fi);

int fila_cheia (Fila* fi);

int fila_vazia (Fila* fi);

int insere_fila (Fila* fi, int x);

int remove_fila (Fila* fi);

int consulta_fila (Fila* fi, int *y);

void imprime_fila (Fila* fi);