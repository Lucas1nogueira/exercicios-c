struct Dados {
    char palavra[50];
};

typedef struct Elemento* Pilha;

Pilha* cria_pilha ();

void libera_pilha (Pilha* pi);

int insere_pilha (Pilha* pi, char txt[]);

int remove_pilha (Pilha* pi, Pilha* pi2);

int consulta_topo_pilha (Pilha* pi);

void verifica_string (Pilha* pi, char txt[]);