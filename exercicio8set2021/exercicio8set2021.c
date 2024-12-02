#include <stdio.h>

int main () {
	float nota;
	
	printf("Insira a sua nota:\n");
	scanf("%f", &nota);
	
	printf("A nota inserida foi: %.1f\n", nota);
	
	if (nota >= 30 && nota < 60) {
		printf("Voce nao atingiu a nota minima necessaria para passar, por isso precisara fazer a sub.");
	}
	
	if (nota >= 60) {
		printf("Parabens, voce passou na disciplina.");
	}
	
	return 0;
}
