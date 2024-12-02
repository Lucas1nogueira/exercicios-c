#include <stdio.h>

int main () {
  int tamanho=0;
  char frase[20];
  
  printf("Insira uma frase de ate 20 caracteres:\n");
  scanf("%[^\n]", frase);
  
  while(frase[tamanho]!='\0')
  tamanho++;
  
  for(int contador=0; contador<tamanho; contador++){
    int contador_mi=97;
    for(int contador_ma=65; contador_ma<=90; contador_ma++){
      if(frase[contador]==contador_ma)
      frase[contador]=contador_ma+32;
      else
      if(frase[contador]==contador_mi
      && frase[contador]>=97
      && frase[contador]<=122) 
      frase[contador]=contador_mi-32;
      contador_mi++;
    }
  }
  
  printf("\n\nA frase modificada e: %s", frase);
  
  return 0;
}
