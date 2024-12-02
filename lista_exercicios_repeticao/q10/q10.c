#include <stdio.h>

int main () {
	int decimal, resto;
	
	printf("Insira um numero decimal: ");
	scanf("%d", &decimal);
	
	do{
		resto = decimal%2;
		printf("%d", resto);
		decimal = decimal / 2;
	}while (decimal >= 1);
	
	return 0;
}
