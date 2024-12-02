#define MAX 10

struct Dados {
    char placa[10];
    int deslocamento;
};

typedef struct fila Fila;

Fila* cria_fila ();

void libera_fila (Fila* fi);

int tamanho_fila (Fila* fi);

int fila_cheia (Fila* fi);

int fila_vazia (Fila* fi);

int insere_fila (Fila* fi, struct Dados x); // sempre no final.

int remove_fila (Fila* fi);

int consulta_fila (Fila* fi, struct Dados *y);

void imprime_fila (Fila* fi);

int busca_carro (Fila* fi, char placa[], int *pos);

void retira_carro (Fila* fi, Fila* fi2, int pos);

struct Dados acesso_espera (Fila* fi_espera);