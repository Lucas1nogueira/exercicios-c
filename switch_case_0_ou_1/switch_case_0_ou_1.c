#include <stdio.h>

int main () {
	int numero;
	
	printf("Escolha um inteiro entre 0 e 1:\n");
	scanf("%d", &numero);
	
	switch (numero) {
		case 0:
		printf("O numero digitado e igual a 0.");
		break;
		case 1:
		printf("O numero digitado e igual a 1.");
		break;
		default:
		printf("Erro: o numero digitado nao e 0 ou 1.");
		break;
	}
	
	return 0;
}
