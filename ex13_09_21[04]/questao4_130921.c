#include <stdio.h>

int main () {
	int X, Y;
	
	printf("Insira um numero inteiro:\n");
	scanf("%d", &X);
	
	printf("Insira um numero inteiro diferente do inserido anteriormente:\n");
	scanf("%d", &Y);
	
	if (X > Y) {
		printf("O numero %d e maior do que %d", X, Y);
	}else{
		if (X < Y) {
			printf("O numero %d e maior do que %d", Y, X);
		}else{
			if (X == Y) {
				printf("Erro: os numeros inseridos sao iguais.");
			}
		}
	}
	
	return 0;
}
