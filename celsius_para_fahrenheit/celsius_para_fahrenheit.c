#include <stdio.h>

int main () {
	float celsius, fh;
	
	printf("Insira o valor em graus Celsius:\n");
	scanf("%f", &celsius);
	
	fh = (celsius * (9.0 / 5.0)) + 32.0;
	printf("O valor correspondente em graus Fahrenheit e igual a: %.2f", fh);
	
	return 0;
	}
