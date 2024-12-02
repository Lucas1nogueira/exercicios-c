struct Dados {
    char x;
};

typedef struct Elemento* Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int insere_pilha (Pilha* pi, char string1[]);

int remove_pilha (Pilha* pi);

Pilha* inverte_pilha (Pilha* pi);

int verifica_expressao (Pilha* pi);