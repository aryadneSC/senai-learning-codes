/*Elabore um algoritmo que leia dois valores do usuário e a operação que ele deseja executar 
(Operações: soma, subtração, divisão, multiplicação). 
Execute a operação desejada e imprima na tela.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int valor1, valor2;
	int opcao;
	char continuar = 's';
	
	do {
	printf("Insira o primeiro valor: ");
	scanf("%d", &valor1);
	
	printf("Insira o segundo valor: ");
	scanf("%d", &valor2);
	
	printf("## Escolha Operacao ##\n");
	printf("[1] Soma\n");
	printf("[2] Subtracao\n");
	printf("[3] Multiplicacao\n");
	printf("[4] Divisao\n");
	printf("[5] Sair\n");
	printf("Escolha: ");
	scanf("%d", &opcao);
	
	system("cls");
	
	printf("\nResultado: ");	
	switch(opcao) {
		case 1:
			printf("%d + %d = %d\n", valor1, valor2, valor1 + valor2);
			break;
		case 2:
			printf("%d - %d = %d\n", valor1, valor2, valor1 - valor2);
			break;
		case 3:
			printf("%d X %d = %d\n", valor1, valor2, valor1 * valor2);
			break;
		case 4:
			if(valor2 == 0) 
				printf("Erro! Divisao por zero.");
			 else 
				printf("%d / %d = %d\n", valor1, valor2, valor1 / valor2);
			break;
		case 5:
			printf("Saindo...");
			abort();
		default:
			printf("Opcao invalida!\n");
		}
		
		printf("\n==============================\n");
		
		printf("Deseja fazer outra conta? [S/N]: ");
		scanf(" %c", &continuar);
		
		system("cls");
			
	} while(continuar == 's' || continuar == 'S');
	
	printf("Programa encerrado!\n");
	
	return 0;	
}