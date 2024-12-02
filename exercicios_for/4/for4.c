#include <stdio.h>

int main () {
	int numero = 1, anterior = 0;
	
	printf("%d ", numero);
	anterior = numero;
	numero++;
	printf("%d ", numero);
	
	for(numero = 2; numero <=100; ) {
		numero = numero + anterior;
		printf("%d ", numero);
		anterior = numero - anterior;
	}
	
	return 0;
}
