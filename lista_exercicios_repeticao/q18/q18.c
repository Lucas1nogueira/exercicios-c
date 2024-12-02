#include <stdio.h>

int main () {
	float sal_carlos, sal_joao;
	int meses_necessarios=0;
	float poupanca_carlos=0, rendafixa_joao=0;
	
	sal_carlos = 3000.00;
	sal_joao = sal_carlos/3;
	meses_necessarios++;
	poupanca_carlos = poupanca_carlos + (sal_carlos * 1.02);
	rendafixa_joao = rendafixa_joao + (sal_joao * 1.05);
	
	do {
		meses_necessarios++;
		poupanca_carlos = poupanca_carlos * 1.02;
		rendafixa_joao = rendafixa_joao * 1.05;
	}while (rendafixa_joao < poupanca_carlos);
	
	printf("A quantidade de meses necessarios para que Joao passe Carlos e:");
	printf(" %d meses.", meses_necessarios);
	
	return 0;
}
