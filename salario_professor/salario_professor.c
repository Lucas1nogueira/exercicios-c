#include <stdio.h>

int main () {
	float horasaula;
	int nivel;
	
	printf("Por favor, digite um numero referente a uma das opcoes:\n");
	printf("1 - Professor Nivel 1.\n");
	printf("2 - Professor Nivel 2.\n");
	printf("3 - Professor Nivel 3.\n");
	scanf("%d", &nivel);
	
	switch (nivel) {
		case 1:
		printf("\nPor favor, informe a quantidade de horas-aula:\n");
		scanf("%f", &horasaula);
		printf("\nSeu salario corresponde a: %.2f.", horasaula * 12.00);
		break;
		case 2:
		printf("\nPor favor, informe a quantidade de horas-aula:\n");
		scanf("%f", &horasaula);
		printf("\nSeu salario corresponde a: %.2f.", horasaula * 17.00);
		break;
		case 3:
		printf("\nPor favor, informe a quantidade de horas-aula:\n");
		scanf("%f", &horasaula);
		printf("\nSeu salario corresponde a: %.2f.", horasaula * 25.00);
		break;
		default:
		printf("\nErro: O numero inserido nao corresponde a uma das opcoes exibidas.");
		break;
	}
	
	return 0;
}
