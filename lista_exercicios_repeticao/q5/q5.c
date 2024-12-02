#include <stdio.h>

int main () {
	int numerador=0, denominador=100;
	
	printf("%d / %d\n", numerador, denominador);
	
	do{
		numerador = numerador + 2;
		denominador = denominador - 4;
		printf("%d / %d\n", numerador, denominador);
	}while(numerador != 50 && denominador != 0);
	
	return 0;
}
