#include <stdio.h>

int main () {
	int x;
	
	printf("Digite um numero inteiro:\n");
	scanf("%d", &x);
	
	if (x % 3 == 0)
		printf("%d e multiplo de 3.", x);
	else
		printf("%d nao e multiplo de 3.", x);
		
	return 0;
}
