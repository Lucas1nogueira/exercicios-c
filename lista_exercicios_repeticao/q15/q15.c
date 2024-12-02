#include <stdio.h>

int main () {
	int numero, divisor, soma = 0;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &numero);
	
	printf("A soma dos divisores do numero %d e:\n", numero);
	
	for(divisor = 1; divisor < numero; divisor++) {
		if(numero%divisor==0) {
			printf("%d", divisor);
			soma = soma + divisor;
		}
		if((numero%divisor==0) && (divisor < (numero/2)))
		printf(" + ");
	}
	
	printf(" = %d", soma);
	
	return 0;
}
