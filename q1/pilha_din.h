struct Dados {
    char x;
};

typedef struct Elemento* Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int tamanho_pilha (Pilha* pi);

int pilha_vazia (Pilha* pi);

int insere_pilha (Pilha* pi, char string1[]);

Pilha* inverte_pilha (Pilha* pi);

int comp_pilhas (Pilha* pi, Pilha *pi2);