#include <stdio.h>

int main () {
  char string1[40];
  char string2[20];
  
  printf("Insira uma string com ate 20 caracteres:\n");
  scanf("%[^\n]", string1);
  getchar();
  
  printf("\nInsira outra string de ate 20 caracteres:\n");
  scanf("%[^\n]", string2);
  
  int tamanho_string2=0;
  
  for(int contador=0; contador<20; contador++){
    if(string2[contador]!='\0')
    tamanho_string2++;
  }
  
  int contador=0;
  int num=0;
  
  do{
    contador++;
    if(string1[contador]=='\0'){
      string1[contador] = 32;
      for(int contador2=contador+1; contador2<=tamanho_string2; contador2++){
        string1[contador2]=string2[num];
        ++num;
      }
      string1[contador+tamanho_string2] = 0;
      break;
    }
  }while(string1[contador]!='\0');
  
  printf("\n\nAs strings concatenadas sao iguais a:\n");
  printf("%s", string1);
  
  return 0;
}
