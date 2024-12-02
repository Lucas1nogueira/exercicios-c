#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	char string_orig[20];
	char string_invert[20];
	int varredura_original;
	int varredura_invertida = 0;
	
	printf("Insira a palavra a ser invertida com ate 20 caracteres:\n");
	scanf("%s", string_orig);
	
	for (varredura_original = strlen(string_orig) - 1; varredura_original >= 0; varredura_original--) {
		string_invert[varredura_invertida] = string_orig[varredura_original];
		varredura_invertida++;
	}
	
	string_invert[varredura_invertida] = '\0';
	printf("%s", string_invert);
	
	return 0;
}
