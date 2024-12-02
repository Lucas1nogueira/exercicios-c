#include <stdio.h>

int main () {
	int numero;
	float soma=0, quantidade=0, maior=0, menor=0;
	float soma_pares=0, quant_pares=0;
	float media, media_pares;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &numero);
	menor = numero;
	
	do {
		quantidade++;
		if(numero==0)
		quantidade--;
		soma = soma + numero;
		media = soma / quantidade;
		if(numero > maior)
		maior = numero;
		if(numero < menor && numero !=0)
		menor = numero;
		if(numero%2==0) {
			quant_pares++;
			soma_pares = soma_pares + numero;
		}
		media_pares = soma_pares / quant_pares;			
		printf("Insira um numero inteiro: ");
		scanf("%d", &numero);
	}while (numero!=0);
	
	printf("\nSoma dos numeros digitados = %.0f\n", soma);
	printf("Quantidade de numeros digitados = %.0f\n", quantidade);
	printf("Media dos numeros digitados = %.2f\n", media);
	printf("O maior numero digitado e igual a = %.0f\n", maior);
	printf("O menor numero digitado e igual a = %.0f\n", menor);
	printf("Media dos numeros pares = %.2f\n", media_pares);
	
	return 0;
}
