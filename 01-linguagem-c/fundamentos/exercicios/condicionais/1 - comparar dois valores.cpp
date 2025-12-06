/*1. Faca um programa que receba dois números e mostre qual deles é o maior.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void maiorValor(int a, int b);

int main() {
	// setlocale(LC_ALL, "pt-BR");
	int valor1, valor2;
	
	printf("Insira dois valores para serem comparados: \n");
	scanf("%d%d", &valor1, &valor2);
	
	maiorValor(valor1, valor2);
	
	return 0;
}

void maiorValor(int a, int b) {
	if(a > b) {
		printf("\nO valor %d eh maior do que %d", a, b);
	} else if (a < b) {
		printf("\nO valor %d eh maior do que %d", b, a);
	} else {
		printf("Os valores sao iguais.");
	}
}