#include <stdio.h>

int main () {
	int sexo, func_normal, func_obeso;
	float peso, altura, imc, percentual_normal, percentual_obeso;
	 
	for (int contador = 1; contador <= 5; contador ++) {
		printf("\nEscolha o sexo do funcionario:\n");
		printf("1- Masculino; 2- Feminino;\n");
		scanf("%d", &sexo);
		switch(sexo) {
			case 1:
			printf("Insira o peso do funcionario em quilos: ");
			scanf("%f", &peso);
			printf("\nInforme agora a altura do funcionario em metros: ");
			scanf("%f", &altura);
			imc = peso / (altura * altura);
			printf("\nO IMC deste funcionario e igual a: %.2f\n", imc);
			if (imc <= 25) func_normal = func_normal + 1;
			if (imc >= 30) func_obeso = func_obeso + 1;
			break;
			case 2:
			printf("Insira o peso do funcionario em quilos: ");
			scanf("%f", &peso);
			printf("\nInforme agora a altura do funcionario em metros: ");
			scanf("%f", &altura);
			imc = peso / (altura * altura);
			printf("\nO IMC deste funcionario e igual a: %.2f\n", imc);
			if (imc <= 27) func_normal = func_normal + 1; 
			if (imc >= 30) func_obeso = func_obeso + 1;
			break;
			default:
			printf("Opcao invalida.");
		}
	}
	percentual_obeso = func_obeso / 20.0;
	percentual_normal = func_normal / 20.0;
	
	printf("\nO percentual de obesos e de: %.2f \n", percentual_obeso * 100.0);
	printf("O percentual de funcionarios normais e de: %.2f ", percentual_normal * 100.0);
	
	return 0;
}
