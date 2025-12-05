/*Crie um programa em C que permita fazer a conversão cambial entre Reais e Dólares. 
Considere como taxa de câmbio US$1,0 = R$5,30. 
Leia um valor em Reais e mostre o correspondente em Dólares.*/

#include <stdio.h>

int main() {
	float real, valorDolar;
	
	printf("Valor em R$: ");
	scanf("%f", &real);
	
	valorDolar = real / 5.30;
	
	printf("Valor em US$: %.2f", valorDolar);
	return 0;
}