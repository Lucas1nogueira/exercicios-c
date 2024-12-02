#include <stdio.h>

int main () {
	int numero;
	
	printf("Insira um numero inteiro:\n");
	scanf("%d", &numero);
	
	if (numero > 0) {
		printf("O numero digitado e positivo.");
	}else{
		if (numero < 0) {
			printf("O numero digitado e negativo.");
		}else{
			if (numero == 0) {
				printf("O numero digitado e nulo, ou seja, igual a 0.");
			}
		}
	}
	
	return 0;
}
