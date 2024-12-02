#include <stdio.h>

int main () {
	int opcao;
	float a, b;
	
	do{
		printf("\n\nInsira a opcao referente a operacao desejada:");
		printf("\n1- adicao");
		printf("\n2- subtracao");
		printf("\n3- multiplicacao");
		printf("\n4- divisao");
		printf("\n5- sair\n");
		scanf("%d", &opcao);
		switch(opcao) {
			case 1:
			printf("Insira o valor de A: ");
			scanf("%f", &a);
			printf("Insira o valor de B: ");
			scanf("%f", &b);
			printf("\n%.2f + %.2f = %.2f", a, b, a+b);
			break;
			case 2:
			printf("Insira o valor de A: ");
			scanf("%f", &a);
			printf("Insira o valor de B: ");
			scanf("%f", &b);
			printf("\n%.2f - %.2f = %.2f", a, b, a-b);
			break;
			case 3:
			printf("Insira o valor de A: ");
			scanf("%f", &a);
			printf("Insira o valor de B: ");
			scanf("%f", &b);
			printf("\n%.2f x %.2f = %.2f", a, b, a*b);
			break;
			case 4:
			printf("Insira o valor de A: ");
			scanf("%f", &a);
			printf("Insira o valor de B: ");
			scanf("%f", &b);
			printf("\n%.2f + %.2f = %.2f", a, b, a/b);
			break;
			case 5:
			printf("\nSaindo do programa...");
			break;
			default:
			printf("\nOpcao invalida.\n");
		}
	}while(opcao != 5);
	return 0;
}
