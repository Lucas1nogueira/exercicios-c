#include <stdio.h>

int main () {
	int numero;
	
	printf("Insira um numero inteiro: ");
	scanf("%d", &numero);
	
	printf("Os numeros pares menores do que %d sao:\n", numero);
	
	do{
		if(numero%2==0) {
			numero = numero - 2;
			printf("%d  ", numero);
		}else{
			numero--;
			printf("%d  ", numero);
		}
	}while(numero>3);
	
	return 0;
}
