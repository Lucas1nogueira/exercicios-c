#include <stdio.h>

int main () {

	char nomepiloto[40];
	float distancia, tempo, velocidade;
	
	printf("Insira o nome do piloto:\n");
	scanf("%[^\n]", nomepiloto);
	
	printf("Insira a distancia percorrida, em quilometros:\n");
	scanf("%f", &distancia);
	
	printf("Insira o tempo gasto no percurso, em horas:\n");
	scanf("%f", &tempo);
	
	velocidade = distancia / tempo;
	printf("A velocidade media de %s foi de %.2f km/h.", nomepiloto, velocidade);
	
	return 0;
}
