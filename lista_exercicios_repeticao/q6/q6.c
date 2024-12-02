#include <stdio.h>

int main () {
	int num1, num2, resultado_fatorial;
	
	printf("Insira um numero inteiro positivo: ");
	scanf("%d", &num1);
	
	printf("\n %d! = ", num1);
	num2 = num1;
	printf("%d", num2);
	resultado_fatorial = num1;
	
	for(int contador = 1; contador < num1; contador++) {
		num2--;
		printf(" x %d", num2);
		resultado_fatorial = resultado_fatorial * num2;
	}
	
	printf(" = %d", resultado_fatorial);
	
	return 0;
}
