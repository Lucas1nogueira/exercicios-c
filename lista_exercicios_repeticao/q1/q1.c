#include <stdio.h>
#include <string.h>

int main (void) {
	char nome_funcionario[20], nome_func_maior_tempo[20], nome_func_menor_tempo[20];
	int tempo_servico, tempo_maior_servico = 0, tempo_menor_servico = 0;
	
	for (int contador = 0; contador < 10; contador++) {
		printf("-> Insira o nome do funcionario: ");
		scanf("%s", nome_funcionario);
		printf("-> Insira o tempo de servico em meses: ");
		scanf("%d", &tempo_servico);
		printf("\n\n");
		
		if (tempo_servico > tempo_maior_servico) {
			strcpy(nome_func_maior_tempo, nome_funcionario);
			tempo_maior_servico = tempo_servico;
		}else{
			tempo_menor_servico = tempo_servico;
			strcpy(nome_func_menor_tempo, nome_funcionario);
			tempo_menor_servico = tempo_servico;
		}
	}
		
	printf("\tO nome do funcionario de maior servico e: %s.\n", nome_func_maior_tempo);
	printf("\tTempo de servico: %d.\n\n", tempo_maior_servico);
	
	printf("\tO nome do funcionario de menor tempo de servico e: %s.\n", nome_func_menor_tempo);
	printf("\tTempo de servico: %d.", tempo_menor_servico);
	
	return 0;
}
