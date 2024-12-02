#include <stdio.h>

int main () {
  char string[20];
  int palavras=1;
  
  printf("Insira uma string com ate 20 caracteres:\n");
  scanf("%[^\n]", string);
  
  for(int contador=0; contador<20; contador++) {
    if(string[contador]==32)
    palavras++;
  }
  
  printf("\nO numero de palavras nesta string e de: %d palavras", palavras);
  
  return 0;
} 
