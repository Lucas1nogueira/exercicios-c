#include <stdio.h>

int somaserie (int num);

int main (){
  printf("A soma da serie e igual a: ");

  printf("%d", somaserie(5));

  return 0;
}

int somaserie (int num){
  if(num>=1){
    int soma=0;
    int fat=num;
    
    for(int i=num-1; i>=1; i--){
      fat=fat*i;
    }

    soma=(fat/num)+somaserie(num-1);
    
    return (soma);
  }else
    return 0;
}