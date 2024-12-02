#include <stdio.h>

int main () {
	int numero;
	
	printf("Insira um numero inteiro no intervalo de 0 a 5.\n");
	scanf("%d", &numero);
	
	if (numero >= 0 && numero <= 5) {
		printf("O numero inserido foi: %d", numero);
	}else {
		if (numero < 0) {
			printf("O numero inserido e menor que 0.");
		}
		if (numero > 5) {
			printf("O numero inserido e maior que 5.");
		}
	}
	
	return 0;
}
