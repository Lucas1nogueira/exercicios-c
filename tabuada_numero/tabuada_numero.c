#include <stdio.h>

int main () {
	int numero;
	
	printf("Digite um numero de 1 a 10: ");
	scanf("%d", &numero);
	
	printf("\nNumero escolhido: %d.\n", numero);
	
	for (int multiplicador = 1; (multiplicador <= 10); multiplicador++) {
		printf("\t-> %d x %d = %d.\n", numero, multiplicador, (numero * multiplicador));
	}
		
	return 0;
}
