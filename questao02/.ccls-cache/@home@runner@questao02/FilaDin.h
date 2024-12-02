//Arquivo FilaDin.h
struct dados {
    int x;
};

typedef struct elemento Elem;

typedef struct fila Fila;

Fila* cria_Fila ();
void libera_Fila (Fila* fi);
int consulta_Fila (Fila* fi, struct dados *al);
int insere_Fila (Fila* fi, struct dados al);
int tamanho_Fila (Fila* fi);
int Fila_vazia (Fila* fi);
int Fila_cheia (Fila* fi);
void imprime_Fila (Fila* fi);
void ordena_Fila (Fila* fi, Fila* fi_aux, Fila* fi_ord);
Elem* busca_menor (Fila* fi);
int insere_Fi_mod (Fila* fi, Elem* no);
int remove_Fi_mod (Fila* fi);