#include <stdio.h>

int main () {
	int elemento[10];
	
	for(int contador=0; contador<10; contador++) {
		elemento[contador] = contador;
		printf("%d ", elemento[contador]);
	}
	
	return 0;
}
