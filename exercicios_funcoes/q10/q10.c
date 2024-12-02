#include <stdio.h>

int decbin (int dec);

int main (){
	int decimal;

	printf("Insira um numero decimal: ");
	scanf("%d", &decimal);

	decbin(decimal);
}

int decbin (int dec){
	int binario[10]={}, resto=0, i=0, j=0;

  do{
    if(dec%2==1)
      binario[i]=1;
    else{
      if(dec%2==0)
        binario[i]=0;
    }
    i++;
    dec=dec/2;
  }while(dec/2>=1);

  binario[i]=1;

  printf("Tal numero em binario e igual a: ");

  while(j<=i){
  	printf("%d", binario[j]);
  	j++;
  }

	return 0;
}