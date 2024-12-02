#include <stdio.h>

int main () {
	int numero;
	
	printf("Digite um numero inteiro:\n");
	scanf("%d", &numero);
	
	printf("O numero digitado foi: %d.\n", numero);
	
	if (numero % 2 == 0) {
		printf("O numero inserido e par.");
	}else{
		printf("O numero inserido e impar.");
	}
	
	return 0;
}
