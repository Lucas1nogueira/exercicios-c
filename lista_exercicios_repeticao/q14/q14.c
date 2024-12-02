#include <stdio.h>

int main () {
	int numero, quantidade, maior = 0, quantidade_maior = 0;
	
	printf("Digite a quantidade de numeros a serem lidos: ");
	scanf("%d", &quantidade);
	
	for(int contador = 0; contador < quantidade; contador++) {
		printf("\nInsira um numero: ");
		scanf("%d", &numero);
		if(numero > maior) {
			maior = numero;
			quantidade_maior = 0;
		}
		if(numero == maior)
		quantidade_maior++;
	}

	printf("\nMaior numero inserido: %d", maior);
	printf("\nO maior numero foi lido %d vezes", quantidade_maior);
	
	return 0;
}
