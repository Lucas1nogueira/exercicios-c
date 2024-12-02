#define MAX 50

struct Dados {
    char x;
};

typedef struct Pilha Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int pilha_cheia (Pilha* pi);

int insere_pilha (Pilha* pi, char string[]);

int remove_pilha (Pilha* pi);

Pilha* inverte_pilha (Pilha* pi);

int comp_pilhas (Pilha* pi, Pilha* pi2);