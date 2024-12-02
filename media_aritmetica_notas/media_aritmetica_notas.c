#include <stdio.h>

int main () {
	
	float nota1, nota2, nota3, nota4, nota5, media;
	
	printf("Insira as 5 notas do aluno:\n");
	
	printf("1a nota:\n");
	scanf("%f", &nota1);
	
	printf("2a nota:\n");
	scanf("%f", &nota2);
	
	printf("3a nota:\n");
	scanf("%f", &nota3);
	
	printf("4a nota:\n");
	scanf("%f", &nota4);
	
	printf("5a nota:\n");
	scanf("%f", &nota5);

	media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5;
	printf("A media aritmetica das 5 notas do aluno e igual a: %.2f", media);
	
	return 0;
}
