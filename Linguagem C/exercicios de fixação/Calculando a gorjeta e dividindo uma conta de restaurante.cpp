/*Exercício 4:
Escreva um programa que leia um valor de despesa de restaurante, 
o valor da gorjeta (em porcentagem) e o número de pessoas para dividir a conta. 
Imprima o valor que cada um deve pagar. 
Assuma que a conta será dividida igualmente.*/

#include <stdio.h>

int main() {
	int numPessoas;
	float valorDespesa, gorjeta;
	float valorTotal, valorPorPessoa;
	
	printf("Insira:\n\n");
	printf("O valor total da conta: R$ ");
	scanf("%f", &valorDespesa);
	printf("Valor da gorjeta: R$ ");
	scanf("%f", &gorjeta);
	printf("Numero de pessoas: ");
	scanf("%d", &numPessoas);
	
	valorTotal = valorDespesa * gorjeta/100 + valorDespesa;
	valorPorPessoa = valorTotal / numPessoas;
	
	printf("Valor por pessoa: R$%.2f \n", valorPorPessoa);
	
	return 0;
}