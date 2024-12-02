#include <stdio.h>

int main () {
	int operacao;
	float a, b;
	
	printf("Escolha a operacao a ser realizada:\n");
	printf("\n\t1 - Adicao.");
	printf("\n\t2 - Subtracao.");
	printf("\n\t3 - Multiplicacao.");
	printf("\n\t4 - Divisao.");
	
	printf("\n\nDigite o numero correspondente a operacao escolhida:\n");
	scanf("%d", &operacao);
	
	switch (operacao) {
		case 1:
		printf("Insira o valor de A e B para realizacao da soma:\n\n");
		printf("\tValor de A = ");
		scanf("%f", &a);
		printf("\n\tValor de B = ");
		scanf("%f", &b);
		printf("\n\nA+B = %.2f", a + b);
		break;
		
		case 2:
		printf("Insira o valor de A e B para realizacao da subtracao:\n\n");
		printf("\tValor de A = ");
		scanf("%f", &a);
		printf("\n\tValor de B = ");
		scanf("%f", &b);
		printf("\n\nA-B = %.2f", a - b);
		break;
		
		case 3:
		printf("Insira o valor de A e B para realizacao da multiplicacao:\n\n");
		printf("\tValor de A = ");
		scanf("%f", &a);
		printf("\n\tValor de B = ");
		scanf("%f", &b);
		printf("\n\nA x B = %.2f", a * b);
		break;
		
		case 4:
		printf("Insira o valor de A e B para realizacao da divisao:\n\n");
		printf("\tValor de A = ");
		scanf("%f", &a);
		printf("\n\tValor de B = ");
		scanf("%f", &b);
		if (b == 0) {
			printf("Erro: O divisor nao pode ser igual a zero.");
			break;
		}
		printf("\n\nA / B = %.2f", a / b);
		break;
		
		default:
		printf("\n\nErro: Nao existe tal opcao no menu.");
		break;
	}
	
	return 0;
}
