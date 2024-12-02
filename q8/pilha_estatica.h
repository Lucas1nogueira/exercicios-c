#define MAX 51

struct Dados {
    int x;
};

typedef struct Pilha Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int pilha_cheia (Pilha* pi);

int insere_pilha (Pilha* pi, int num);

int remove_pilha (Pilha* pi);

int conta_pares (Pilha* pi, int* pares);