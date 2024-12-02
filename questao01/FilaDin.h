//Arquivo FilaDin.h
struct cliente {
    char nome[30];
    int id;
    char tipo_cliente;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct cliente *al);
int insere_Fila(Fila* fi, struct cliente al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
void fila_atendimento (Fila* N, Fila* P, Fila* at);