#include <stdio.h>

char conceito (int media);

int main (){
  float media;

  printf("Insira a media final do aluno: ");
  scanf("%f", &media);

  printf("Conceito: %c", conceito(media));

  return 0;
}

char conceito (int media){
  if(media>=0 && media <=4.9)
    return('D');
  else{
    if(media>=5.0 && media <=6.9)
      return('C');
    else{
      if(media>=7.0 && media <=8.9)
        return('B');
      else{
        if(media>=9.0 && media <=10.0)
          return('A');
        else
          return(0);
      }
    }
  }
}