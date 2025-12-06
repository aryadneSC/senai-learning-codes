/*Uma loja fornece 10% de desconto para funcionários e 5% de desconto para clientes vips. 
Faça um programa que calcule o valor total a ser pago por uma pessoa. 
O programa deverá ler o valor total da compra efetuada e um código que 
identifique se o comprador é um cliente comum (1), funcionário (2) ou vip (3).*/


#include <stdio.h>
#include <stdlib.h>

void verificaTipoCliente(int codigo, float valor);

int main() {
	
	int codigoCliente;
	float valorTotalCompra;
	char continuar = 's';
	
	printf("|----------- DESCONTOS DA LOJA ----------|\n\n");
	
	do {
	
	printf("Informe o valor total da compra: R$ ");
	scanf("%f", &valorTotalCompra);
	
	printf("Informe seu codigo:\n");
		printf("[1] Cliente comum\n");
		printf("[2] Funcionario\n");
		printf("[3] Vip\n");
		printf("[4] Sair\n");
		printf("Selecione uma opcao: ");
		scanf("%d", &codigoCliente);
			
	printf("\n");
	verificaTipoCliente(codigoCliente, valorTotalCompra);
	
	printf("\n|----------------------------------------|\n");
	printf("Deseja continuar? [S/N]: ");
	scanf(" %c", &continuar);
	
	system("cls");
	
	} while(continuar == 's' || continuar == 'S');
	
	return 0;
}

void verificaTipoCliente(int codigo, float valor) {
	float valorDescontado;
	
	switch(codigo) {
		case 1:
		printf("Cliente comum. Sem desconto.\n");
		printf("Total a pagar: R$ %.2f\n", valor);
		break;
		
		case 2:
		valorDescontado = valor - (valor*0.10);
		printf("Funcionario! Desconto de 10%% aplicado.\n");
		printf("De R$ %.2f por R$ %.2f\n", valor, valorDescontado);
		break;
		
		case 3:
		valorDescontado = valor - (valor*0.05);
		printf("Cliente VIP! Desconto de 5%% aplicado.\n");
		printf("De R$ %.2f por R$ %.2f\n", valor, valorDescontado);
		break;
		
		case 4:
		printf("Saindo...");
		abort();
		
		default:
		printf("Opcao invalida!");
		
	}
}