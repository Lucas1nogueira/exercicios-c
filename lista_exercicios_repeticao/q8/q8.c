#include <stdio.h>

int main () {
	int primeiro, final, primo;
	
	printf("Insira o primeiro numero do intervalo: ");
	scanf("%d", &primeiro);
	
	printf("Insira o numero final do intervalo: ");
	scanf("%d", &final);
	
	printf("Os numeros primos entre %d e %d sao: ", primeiro, final);
	primo = primeiro;
	
	do{
		primeiro++;
		if (primo==2 || primo==3 || primo==5 || primo==7)
		printf("%d; ", primo);
		if (primo > 1 && primo%2!=0 && primo%3!=0 && primo%5!=0 && primo%7!=0)
		printf("%d; ", primo);
		primo++;
	}while (primeiro < final);
	
	return 0;
}
