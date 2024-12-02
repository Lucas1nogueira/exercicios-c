#include <stdio.h>

int main () {
	int digito=0, tamanho, tamanho2=0;
	int numero=0, resultado=0;
	int contador=0, contador2=1;
	
	printf("Digite a quantidade de digitos do numero binario desejado: ");
	scanf("%d", &tamanho);
	printf("\nInsira digito por digito o numero binario, inserindo enter:\n");
	
	for(contador = 0; (contador < tamanho); contador++) {
		scanf("%d", &digito);
		numero = digito;
		for(tamanho2 = (tamanho - contador2); tamanho2 > 0; tamanho2--) {
			numero = numero * 2;
		}
		resultado = resultado + numero;
		contador2++;
	}
	
	printf("\nO numero desejado em decimal e igual a: %d", resultado);
	
	return 0;
}
