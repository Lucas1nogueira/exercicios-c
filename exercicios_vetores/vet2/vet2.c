#include <stdio.h>

int main () {
	int i;
	
	printf("Insira o numero de elementos a serem armazenados no vetor: ");
	scanf("%d", &i);
	
	int elementos[i];
	
	printf("Insira os %d numeros a serem colocados no vetor:\n", i);
	
	for(int contador=0; contador<i; contador++) {
		scanf("%d", &elementos[contador]);
	}
	
	printf("\n\nOs valores armazenados na matriz sao: ");
	
	for(int contador=0; contador<i; contador++) {
		printf("%d ", elementos[contador]);
	}
	
	printf("\n\nOs valores armazenados na matriz ao contrario sao: ");
	
	for(int contador=i-1; contador>=0; contador--) {
		printf("%d ", elementos[contador]);
	}
	
	return 0;
}
