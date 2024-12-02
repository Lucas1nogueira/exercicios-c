#define MAX 31

struct Dados {
    int x;
};

typedef struct Pilha Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int pilha_cheia (Pilha* pi);

int insere_n_pilha (Pilha* pi, int n);

int remove_pilha (Pilha* pi);

Pilha* inverte_pilha (Pilha* pi);

int exibe_pilha (Pilha* pi);