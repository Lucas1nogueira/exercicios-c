#include <stdio.h>

int main () {
	int codigo_produto, quantidade, opcao_pagamento, numero_parcelas;
	float total_compra;
	char opcao;
	
	do {
		printf("\nInsira o codigo do produto desejado: ");
		scanf("%d", &codigo_produto);
		switch(codigo_produto) {
			case 1200:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (5.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1300:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (6.30 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1400:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (4.25 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1500:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (5.50 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1600:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (1.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1700:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (7.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1800:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (3.19 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 1900:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (9.30 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2000:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (8.80 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2100:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (6.70 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2200:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (30.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2300:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (2.45 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2400:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (2.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2500:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (21.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2600:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (4.55 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2700:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (0.32 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2800:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (3.40 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 2900:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (12.40 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3000:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (35.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3100:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (2.33 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3200:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (15.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3300:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (5.60 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3400:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (13.21 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3500:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (23.00 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			case 3600:
			printf("Digite a quantidade: "); scanf("%d", &quantidade);
			total_compra = total_compra + (2.45 * quantidade);
			printf("\nDeseja inserir mais produtos?\nS -> Sim\nN -> Nao\n");
			scanf("%s", &opcao);
			break;
			default:
			printf("Codigo invalido.\n");
			break;
		}
	} while (opcao == 'S');
	
	printf("\n\tVALOR TOTAL: R$ %.2f\n\n", total_compra);
	printf("\nEscolha uma opcao de pagamento:\n");
	printf("1. A vista com 10 por cento de desconto.\n");
	printf("2. A prazo.\n");
	printf("3. No crediario com acrescimo de 5 por cento.\n");
	scanf("%d", &opcao_pagamento);
	switch(opcao_pagamento) {
		case 1:
		printf("\nValor total da compra: R$ %.2f\n", total_compra);
		printf("Valor com desconto: R$ %.2f", total_compra * 0.90);
		break;
		case 2:
		printf("\nDigite o numero de parcelas: \n\n");
		scanf("%d", &numero_parcelas);
		printf("Numero de parcelas: %d", numero_parcelas);
		printf("\nValor de cada parcela: R$ %.2f", total_compra / numero_parcelas);
		printf("\nValor total: R$ %.2f", total_compra);
		break;
		case 3:
		printf("\nDigite o numero de parcelas: \n\n");
		scanf("%d", &numero_parcelas);
		printf("Numero de parcelas: %d", numero_parcelas);
		printf("\nValor total com acrescimo de 5 por cento: %.2f", total_compra * 1.05);
		printf("\nValor de cada parcela: R$ %.2f", (total_compra * 1.05) / numero_parcelas);
		break;
	}
	return 0;
}
