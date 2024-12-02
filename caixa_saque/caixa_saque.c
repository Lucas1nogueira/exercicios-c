#include <stdio.h>

int main () {
	int saque;
	
	printf("Digite o valor a ser sacado, ate R$ 100,00.:\n");
	scanf("%d", &saque);
	
	if (saque > 100)
	printf("O valor nao pode exceder 100.");
	else {
		printf("O valor a ser sacado corresponde a:\n");
		if (saque == 100)
		printf("1 nota de R$ 100,00.\n");
		else {
			if (saque >= 50)
			printf("1 nota de R$ 50,00.\n");
			
			if ((saque >= 60 && saque < 70) || (saque >=10 && saque < 20))
			printf("1 nota de R$ 10,00.\n");
			if ((saque >= 70 && saque < 80) || (saque >=20 && saque < 30))
			printf("2 notas de R$ 10,00.\n");
			if ((saque >= 80 && saque < 90) || (saque >=30 && saque < 40))
			printf("3 notas de R$ 10,00.\n");
			if ((saque >= 90 && saque < 100) || (saque >=40 && saque < 50))
			printf("4 notas de R$ 10,00.\n");
			
			if (saque %2!=0 && saque %5==0)
			printf ("1 nota de R$ 5,00.\n");
			if (saque >= 5 && saque %5!=0 && saque %10>5)
			printf ("1 nota de R$ 5,00.\n");
			
			if ((saque %10!=0) && (saque %5!=0) && ((saque %10==1) || (saque %10==6)))
			printf ("1 nota de R$ 1,00.\n");
			if ((saque %10!=0) && (saque %5!=0) && ((saque %10==2) || (saque %10==7)))
			printf ("2 notas de R$ 1,00.\n");
			if ((saque %10!=0) && (saque %5!=0) && ((saque %10==3) || (saque %10==8)))
			printf ("3 notas de R$ 1,00.\n");
			if ((saque %10!=0) && (saque %5!=0) && ((saque %10==4) || (saque %10==9)))
			printf ("4 notas de R$ 1,00.\n");
		}
	}
	
	return 0;
}
