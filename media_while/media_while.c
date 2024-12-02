#include <stdio.h>

int main () {
	int quantidade_desejada, quantidade_atingida = 0, numero, soma = 0;
	
	printf("Insira a quantidade de numeros inteiros que voce quer obter a media: ");
	scanf("%d", &quantidade_desejada);
	
	printf("\n\n Insira o primeiro numero: ");
	scanf("%d", &numero);
	soma = soma + numero;
	quantidade_atingida ++;
	while (quantidade_atingida < quantidade_desejada) {
		printf("\n Insira o proximo numero: ");
		scanf("%d", &numero);
		soma = soma + numero;
		quantidade_atingida ++;
	}
			
	printf("\n\n A media dos numeros informados e igual a: %d.", soma / quantidade_desejada);
			
	return 0;

}
