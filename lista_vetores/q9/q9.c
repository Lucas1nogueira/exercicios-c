#include <stdio.h>

int main () {
  char string[20];
  int tamanho=0, vogais=0, consoantes=0;
  
  printf("Insira uma string de ate 20 caracteres:\n");
  scanf("%s", string);
  
  while(string[tamanho]!='\0')
  tamanho++;
  
  for(int contador=0; contador<tamanho; contador++){
    if(string[contador]=='A' || string[contador]=='a'
    || string[contador]=='E' || string[contador]=='e'
    || string[contador]=='I' || string[contador]=='i'
    || string[contador]=='O' || string[contador]=='o'
    || string[contador]=='U' || string[contador]=='u')
    vogais++;
    else
    consoantes++;
  }
  
  printf("\n\nPalavra: '%s'", string);
  printf("\nA quantidade de vogais e: %d", vogais);
  printf("\nA quantidade de consoantes e: %d", consoantes);
  
  return 0;
}
