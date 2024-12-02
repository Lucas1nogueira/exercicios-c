#include <stdio.h>

int main () {
	int prefeito, vereador;
	float joao=0, pedro=0, marcos=0, guilherme=0, victor=0, paulo=0;
	float t_joao, t_pedro, t_marcos, t_guilherme, t_victor, t_paulo;
	float total_pref, total_ver, nulos, total_nulos, perc_nulos;
	char escolha1, escolha2;
	
	do {
		do{
			printf("\nInsira o numero do candidato para prefeito:\n");
			printf("\t20 - Joao\n\t35 - Pedro\n\t58 - Marcos\n");
			scanf("%d", &prefeito);
			switch(prefeito) {
				case 20:
				printf("\nCandidato Joao.\n");
				printf("Numero 20.\n");
				printf("Partido A.\n");
				printf("\tConfirme ou corrija sua escolha:\n");
				printf("\t'C'-confirmar   'D'-corrigir\n");
				getchar();
				scanf("%c", &escolha1);
				if(escolha1 == 'C') {
					printf("\n\tVoto confirmado!");
					++joao;
					++total_pref;
				}
				if(escolha1 == 'D')
				printf("\n\tVoce sera redirecionado ao inicio.\n");
				break;
				case 35:
				printf("\nCandidato Pedro.\n");
				printf("Numero 35.\n");
				printf("Partido B.\n");
				printf("\tConfirme ou corrija sua escolha:\n");
				printf("\t'C'-confirmar   'D'-corrigir\n");
				getchar();
				scanf("%c", &escolha1);
				if(escolha1 == 'C') {
					printf("\n\tVoto confirmado!");
					++pedro;
					++total_pref;
				}
				if(escolha1 == 'D')
				printf("\n\tVoce sera redirecionado ao inicio.\n");
				break;
				case 58:
				printf("\nCandidato Marcos.\n");
				printf("Numero 58.\n");
				printf("Partido C.\n");
				printf("\tConfirme ou corrija sua escolha:\n");
				printf("\t'C'-confirmar   'D'-corrigir\n");
				getchar();
				scanf("%c", &escolha1);
				if(escolha1 == 'C') {
					printf("\n\tVoto confirmado!");
					++marcos;
					++total_pref;
				}
				if(escolha1 == 'D')
				printf("\n\tVoce sera redirecionado ao inicio.\n");
				break;
				case 000:
				printf("\nOpcao voto nulo.\n");
				printf("\tConfirme ou corrija sua escolha:\n");
				printf("\t'C'-confirmar   'D'-corrigir\n");
				getchar();
				scanf("%c", &escolha1);
				if(escolha1 == 'C') {
					printf("\n\tConfirmado!");
					++nulos;
					++total_pref;
				}
				if(escolha1 == 'D')
				printf("\n\tVoce sera redirecionado ao inicio.\n");
				break;
			}
		}while (escolha1 == 'D');
		if(prefeito >= 0) {
			do{
				printf("\n\nInsira o numero do candidato para vereador:\n");
				printf("\t2200 - Guilherme\n\t4700 - Victor\n\t6010 - Paulo\n");
				getchar();
				scanf("%d", &vereador);
				switch(vereador) {
					case 2200:
					printf("\nCandidato Guilherme.\n");
					printf("Numero 2200.\n");
					printf("Partido C.\n");
					printf("\tConfirme ou corrija sua escolha:\n");
					printf("\t'C'-confirmar   'D'-corrigir\n");
					getchar();
					scanf("%c", &escolha2);
					if(escolha2 == 'C') {
						printf("\n\tVoto confirmado!");
						++guilherme;
						++total_ver;
					}
					if(escolha2 == 'D')
					printf("\n\tVoce sera redirecionado ao inicio.\n");
					break;
					case 4700:
					printf("\nCandidato Victor.\n");
					printf("Numero 4700.\n");
					printf("Partido A.\n");
					printf("\tConfirme ou corrija sua escolha:\n");
					printf("\t'C'-confirmar   'D'-corrigir\n");
					getchar();
					scanf("%c", &escolha2);
					if(escolha2 == 'C') {
						printf("\n\tVoto confirmado!");
						++victor;
						++total_ver;
					}
					if(escolha2 == 'D')
					printf("\n\tVoce sera redirecionado ao inicio.\n");
					break;
					case 6010:
					printf("\nCandidato Paulo.\n");
					printf("Numero 6010.\n");
					printf("Partido B.\n");
					printf("\tConfirme ou corrija sua escolha:\n");
					printf("\t'C'-confirmar   'D'-corrigir\n");
					getchar();
					scanf("%c", &escolha2);
					if(escolha2 == 'C') {
						printf("\n\tVoto confirmado!");
						++paulo;
						++total_ver;
					}
					if(escolha2 == 'D')
					printf("\n\tVoce sera redirecionado ao inicio.\n");
					break;
					case 000:
					printf("\nOpcao voto nulo.\n");
					printf("\tConfirme ou corrija sua escolha:\n");
					printf("\t'C'-confirmar   'D'-corrigir\n");
					getchar();
					scanf("%c", &escolha2);
					if(escolha2 == 'C') {
						printf("\n\tConfirmado!");
						++nulos;
						++total_ver;
					}
					if(escolha2 == 'D')
					printf("\n\tVoce sera redirecionado ao inicio.\n");
					break;
				}
			}while (escolha2 == 'D');
		}
	}while (prefeito >= 0);
	
	printf("\n\nResultados:\n\nCandidatos a prefeito:");
	
	t_joao = (joao/total_pref)*100.00;
	t_pedro = (pedro/total_pref)*100.00;
	t_marcos = (marcos/total_pref)*100.00;
	
	printf("\nJoao: %.0f votos, %.2f por cento.", joao, t_joao);
	printf("\nPedro: %.0f votos, %.2f por cento.", pedro, t_pedro);
	printf("\nMarcos: %.0f votos, %.2f por cento.", marcos, t_marcos);
	
	printf("\n\nCandidatos a vereador:");
	
	t_guilherme = (guilherme/total_ver)*100.00;
	t_victor = (victor/total_ver)*100.00;
	t_paulo = (paulo/total_ver)*100.00;
	
	printf("\nGuilherme: %.0f votos, %.2f por cento.", guilherme, t_guilherme);
	printf("\nVictor: %.0f votos, %.2f por cento.", victor, t_victor);
	printf("\nPaulo: %.0f votos, %.2f por cento.", paulo, t_paulo);
	
	printf("\n\nCandidatos vencedores:");
	
	printf("\nPara prefeito: ");
	if(joao > pedro && joao > marcos) printf("JOAO");
	if(pedro > joao && pedro > marcos) printf("PEDRO");
	if(marcos > pedro && marcos > joao) printf("MARCOS");
	
	printf("\nPara vereador: ");
	if(guilherme > victor && guilherme > paulo) printf("GUILHERME");
	if(victor > guilherme && victor > paulo) printf("VICTOR");
	if(paulo > victor && paulo > guilherme) printf("PAULO");
	
	if(nulos > 0) {
		total_nulos = total_pref + total_ver;
		perc_nulos = (nulos/total_nulos) * 100.00;
		printf("\n\nPercentual de votos nulos: %.2f", perc_nulos);
	}
	if(nulos == 0) printf("\n\nPercentual de votos nulos: 0");
	
	return 0;
}
