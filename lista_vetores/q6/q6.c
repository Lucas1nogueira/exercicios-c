#include <stdio.h>

int main () {
  char string[10]={'A','L','G','O','R','I','T','M','O','S'};
  
  printf("String original: %s", string);
  
  printf("\n\nString invertida:\n");
  
  for(int contador=9; contador>=0; contador--){
    printf("%c\n", string[contador]);
  }
  
  return 0;
}
