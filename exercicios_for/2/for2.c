#include <stdio.h>

int main () {
	int posicao_do_caracter_lido, numero_de_letras_a = 0;
	char string[20];
	
	printf("Insira uma unica palavra de ate 20 caracteres:\n");
	scanf("%s", string);

	for(posicao_do_caracter_lido = 0; posicao_do_caracter_lido < 20; posicao_do_caracter_lido++) {
		if(string[posicao_do_caracter_lido] == 97) {
			numero_de_letras_a++;
			string[posicao_do_caracter_lido] = 98;
		}
	}
	
	printf("O numero de letras 'a' e de: %d.\n", numero_de_letras_a);
	printf("A palavra modificada: %s.", string);
	
	return 0;
}
