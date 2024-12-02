#include <stdio.h>

int main () {
	float soma, numerador = 0, denominador = 1, anterior_denominador;
	
	printf("S = 100 + ");
	anterior_denominador = denominador;
	printf("%.0f/%.0f ", numerador, denominador);
	soma = 100.00 + (numerador/denominador);
	
	do{
		numerador = numerador + 5;
		denominador = denominador + anterior_denominador;
		printf("+ %.0f/%.0f ", numerador, denominador);
		soma = soma + (numerador/denominador);
		anterior_denominador = denominador - anterior_denominador;
	}while (numerador != 80 && denominador != 2583);
	
	printf("= %.0f", soma);
	
	return 0;
}
