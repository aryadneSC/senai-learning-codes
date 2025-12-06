/*Elabore um algoritmo que receba, por meio do teclado, dois valores, 
um para a variável “a” e um para a variável “b”. 
Em seguida, faça os passos que julgar necessário para que ao final, 
a variável “a” possua o valor que inicialmente estava em “b” e 
a variável “b” possua o valor que inicialmente estava em “a”. 
Traduza seu algoritmo para a linguagem C e exiba os valores na tela.*/

#include <stdio.h>

void switchNum(int *a, int *b);

int main() {
	int a, b;
	
	printf("Forneca dois valores: ");
	scanf("%d%d", &a, &b);
	
	printf("Valores iniciais: A = %d | B = %d\n", a, b);
	
	switchNum(&a, &b);
	
	printf("Valores trocados: A = %d | B = %d\n", a, b);
	
	return 0;
}

void switchNum(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}