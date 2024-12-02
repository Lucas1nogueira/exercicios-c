struct filme {
    int codfilme; //cod produto
    char titulo[10]; //nome produto
    float valor; //valor produto
    int qtdEstoque; //qtd disponivel em estoque
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int consulta_lista_cod(Lista* li, int cod, struct filme *fi);
int insere_lista_ordenada(Lista* li, struct filme fi);
int remove_lista(Lista* li, int cod);
int remove_lista_inicio(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void soma_valores (Lista* li);