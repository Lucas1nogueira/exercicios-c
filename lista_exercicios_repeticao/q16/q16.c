#include <stdio.h>

int main () {
	int conversao;
	float velocidade_kmh, velocidade_ms;
	
	do {
		printf("\nEscolha a opcao de conversao:\n\n");
		printf("1- km/h para m/s\n");
		printf("2- m/s para km/h\n");
		printf("3- Finalizar programa.\n");
		scanf("%d", &conversao);
	
		switch(conversao) {
			case 1:
			printf("\n\nInsira a velocidade em km/h: ");
			scanf("%f", &velocidade_kmh);
			velocidade_ms = velocidade_kmh / 3.6;
			printf("\nA velocidade convertida e igual a: %.2f", velocidade_ms);
			break;
			case 2:
			printf("\n\nInsira a velocidade em m/s: ");
			scanf("%f", &velocidade_ms);
			velocidade_kmh = velocidade_ms * 3.6;
			printf("\nA velocidade convertida e igual a: %.2f", velocidade_kmh);
			break;
			case 3:
			printf("O programa sera encerrado.");
			break;
			default:
			printf("Opcao invalida.");
			break;
		}
	}while (conversao != 3);
	
	return 0;
}
