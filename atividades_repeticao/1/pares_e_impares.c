#include <stdio.h>

int main () {
	int numero, pares=0, impares=0;
	
	for(int contador=0; contador<10; contador++) {
		printf("Digite um numero: ");
		scanf("%d", &numero);
		printf("\n");
		if(numero%2==0)
		pares++;
		else
		impares++;
	}
	
	printf("A quantidade de numeros pares e de: %d\n", pares);
	printf("A quantidade de numeros impares e de: %d", impares);
	
	return 0;
}
