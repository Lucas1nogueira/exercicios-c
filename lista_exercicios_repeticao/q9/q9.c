#include <stdio.h>
#include <string.h>

int main () {
	int idade, opiniao, mais_velha, respostas_dez=0;
	char identificador[20], ident_mais_velha[20];
	float media_idade=0, perc_cinco_ou_menos=0;
	
	for(int contador = 0; contador < 200; contador++) {	
		printf("\n\nInsira a idade do espectador: ");
		scanf("%d", &idade);
		media_idade = media_idade + idade;
		
		printf("\nInforme o identificador do espectador: ");
		scanf("%s", identificador);
		if (idade > mais_velha) {
			mais_velha = idade;
			strcpy(ident_mais_velha,identificador);
		}
		
		printf("\nDigite a opiniao do espectador de 0 a 10: ");
		scanf("%d", &opiniao);
		if(opiniao == 10)
		respostas_dez++;
		if(opiniao <= 5)
		perc_cinco_ou_menos++;
	}
	printf("\n\nQuantidade de respostas dez: %d", respostas_dez);
	printf("\nMedia de idade das pessoas que responderam o questionario: %.1f", media_idade / 3);
	printf("\nPercentagem de pessoas que responderam 5 ou menos: %.2f", (perc_cinco_ou_menos / 3) * 100);
	printf("\nIdentificador da pessoa mais velha: %s", ident_mais_velha);
	return 0;
}
