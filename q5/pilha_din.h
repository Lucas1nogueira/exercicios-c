struct Dados {
    int x;
};

typedef struct Elemento* Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int insere_pilha (Pilha* pi, int num);

int remove_pilha (Pilha* pi);

Pilha* organiza_pilha (Pilha* pi, int qtd);

Pilha* inverte_pilha (Pilha* pi);

int exibe_pilha (Pilha* pi);