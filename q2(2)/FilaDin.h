//Arquivo FilaDin.h
struct dados {
    char nome[30];
    int numero_sus;
    int priori;
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
void delay (int number_of_seconds);
int prior_aleat ();
void gerencia_socorro (Fila *fi_orig, Fila* fi_vd, Fila* fi_am, Fila* ve);
void atende_fila (Fila *fi);