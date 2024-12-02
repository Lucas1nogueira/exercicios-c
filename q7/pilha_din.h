struct Dados {
    char x;
};

typedef struct Elemento* Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int insere_pilha (Pilha* pi, char letra);

int exibe_topo_pilha (Pilha* pi, char* letra);

int remove_pilha (Pilha* pi);