#include <stdio.h>

int main () {
	int X, Y, Z;
	
	printf("Insira um numero inteiro:\n");
	scanf("%d", &X);
	
	printf("Insira outro numero inteiro:\n");
	scanf("%d", &Y);
	
	printf("Insira mais um numero inteiro, diferente dos dois anteriores:\n");
	scanf("%d", &Z);
	
	if (X > Y && X > Z) {
		printf("O numero %d e o maior dos tres.", X);
	}else{
		if (Y > X && Y > Z) {
			printf("O numero %d e o maior dos tres.", Y);
		}else{
			if (Z > X && Z > Y) {
				printf("O numero %d e o maior dos tres.", Z);
			}else{
				if (X == Y && Y == Z) {
					printf("Erro: os tres numeros sao iguais.");
				}
			}
		}
	}
	
	return 0;
}
