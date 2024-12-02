#include <stdio.h>

int main () {
	int prefeito;
	int joao=0, total=0;
	char escolha1[5];
	
	
			printf("\nInsira o numero correspondente ao candidato desejado para prefeito:\n");
			printf("\t20 - Joao\n");
			printf("\t35 - Pedro\n");
			printf("\t58 - Marcos\n");
			getchar();
			scanf("%d", &prefeito);
			
			switch(prefeito) {
				case 20:
				printf("\nCandidato Joao.\n");
				printf("Numero 20.\n");
				printf("Partido A.\n");
				printf("\tConfirme ou corrija sua escolha:\n");
				printf("\t'C'-confirmar   'D'-corrigir\n");
				getchar();
				scanf("%s", escolha1);
				if(*escolha1 == 'C') {
					printf("\n\tVoto confirmado!");
					joao++;
					total++;
				}
			}
			
			return 0;
		}
