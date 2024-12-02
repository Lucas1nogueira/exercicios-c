#include <stdio.h>

int main () {
	char id;
	float valor, percentual, resultado, nao_aumentou, mais_caro = 0;
	int maior_cem_cinco_porcento = 0, quantidade_nao_aumentou = 0;
	
	do{
		printf("Insira o ID do produto: ");
		scanf("%s", &id);
		
		printf("Insira o valor deste produto: ");
		scanf("%f", &valor);
		
		printf("Insira o percentual de aumento sem o simbolo de porcentagem: ");
		scanf("%f", &percentual);
		
		resultado = valor + ((valor*percentual)/100.00);
		printf("O novo valor deste produto e igual a: %.2f\n\n", resultado);
		
		if(resultado > 100.00 && percentual > 5)
		maior_cem_cinco_porcento++;
		if(percentual == 0) {
			nao_aumentou = nao_aumentou + resultado;
			quantidade_nao_aumentou++;
		}
		if(resultado > mais_caro)
		mais_caro = resultado;
	}while (id != '0');
	
	printf("Quantidade de mais caros que R$100.00 apos o aumento, e c/ aumento maior que 5 porcento e de:");
	printf(" %d", maior_cem_cinco_porcento);
	
	printf("\nMedia de valor dos produtos que nao sofreram aumento e de: R$ %.2f", nao_aumentou / quantidade_nao_aumentou);
	
	printf("\nO valor do produto mais caro e igual a: R$ %.2f", mais_caro);
	
	return 0;
}
