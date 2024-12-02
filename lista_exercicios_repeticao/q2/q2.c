#include <stdio.h>

int main () {
	int sexo, cabelo, idade;
	float populacao_total, porc_louras, porc_morenas, result_louras, result_morenas;
	do{
		printf("\nEscolha o sexo do habitante:\n");
		printf("\t1- Masculino; 2- Feminino;\n");
		scanf("%d", &sexo);
		switch(sexo) {
			case 1:
			printf("Escolha agora cor do cabelo:\n");
			printf("\t1- Louro; 2- Castanho; 3- Preto;\n");
			scanf("%d", &cabelo);
			switch(cabelo) {
				case 1:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				case 2:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				case 3:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				default:
				printf("Opcao invalida.");
				break;
			}
			break;
			case 2:
			printf("Escolha agora cor do cabelo:\n");
			printf("\t1- Louro; 2- Castanho; 3- Preto;\n");
			scanf("%d", &cabelo);
			switch(cabelo) {
				case 1:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade >= 18 && idade <=35) ++porc_louras;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				case 2:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				case 3:
				printf("Informe agora a idade: ");
				scanf("%d", &idade); ++populacao_total;
				if (idade >= 18 && idade <=35) ++porc_morenas;
				if (idade == -1) {printf("Lista concluida!"); --populacao_total;}
				break;
				default:
				printf("Opcao invalida.");
				break;
			}
			break;
		}
	}while (idade != (-1));
	result_louras = (porc_louras / populacao_total);
	result_morenas = (porc_morenas / populacao_total);
	printf("\n\nA porcentagem de louras e igual a: %.2f por cento.", result_louras * 100.00);
	printf("\n\nA porcentagem de morenas e igual a: %.2f por cento.", result_morenas * 100.00);
	return 0;
}
