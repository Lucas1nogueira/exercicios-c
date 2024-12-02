#include <stdio.h>

int main () {
	int numero;
	int contador=0, contador2=0, numero_exibido=0;
	
	printf("Insira um numero inteiro positivo: ");
	scanf("%d", &numero);
	
	for(contador=1; contador<=numero; contador++) {
		for(contador2=1; contador2<=contador; contador2++) {
			numero_exibido++;
			printf("%d\t", numero_exibido);
		}
		printf("\n");
	}
	return 0;
}
