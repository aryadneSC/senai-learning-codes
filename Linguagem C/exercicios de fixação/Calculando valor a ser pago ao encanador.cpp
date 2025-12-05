/*Uma empresa contrata um encanador a R$ 45,00 por dia. 
Faça um programa que solicite o número de dias trabalhados pelo encanador 
e imprima a quantia líquida que deverá ser paga, 
sabendo que são descontados 8% para imposto de renda.*/

#include <stdio.h>

int main() {
	int dias;
	float valorTotal, impostoRenda; 
	
	printf("Insira a quantidade de dias trabalhados: ");
	scanf("%d", &dias);
	
	valorTotal = dias * 45;
	
	printf("Valor inicial: R$ %.2f\n", valorTotal);
	
	impostoRenda = valorTotal * 8/100;
	valorTotal -= impostoRenda;
	
	printf("Desconto: R$ %.2f\nValor a receber: R$%.2f ", impostoRenda, valorTotal);
	return 0;
}