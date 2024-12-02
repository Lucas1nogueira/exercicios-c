#include <stdio.h>

int main () {

	float salario;
	
	printf("Insira o salario do funcionario:\n");
	scanf("%f", &salario);
	
	printf("O valor do salario com 25 porcento de aumento e igual a: %.2f", salario * 1.25);
	
	return 0;
}
