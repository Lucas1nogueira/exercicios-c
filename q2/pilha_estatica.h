#define MAX 50

struct Dados {
    char x;
};

typedef struct Pilha Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int pilha_cheia (Pilha* pi);

int ins_imp_pilha_inversa (Pilha* pi, char string[]);

int remove_pilha (Pilha* pi);

int impressao_parcial (Pilha* pi);