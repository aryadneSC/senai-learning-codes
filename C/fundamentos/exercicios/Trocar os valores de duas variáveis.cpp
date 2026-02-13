/*Elabore um algoritmo que receba, por meio do teclado, dois valores, 
um para a variável “a” e um para a variável “b”. 
Em seguida, faça os passos que julgar necessário para que ao final, 
a variável “a” possua o valor que inicialmente estava em “b” e 
a variável “b” possua o valor que inicialmente estava em “a”. 
Traduza seu algoritmo para a linguagem C e exiba os valores na tela.*/

#include <stdio.h>

int main() {
	int a, b, aux;
	
	printf("Forneca dois valores: ");
	scanf("%d%d", &a, &b);
	
	printf("Valores iniciais: A = %d | B = %d\n", a, b);
	
	aux = a; // Variável auxiliar para armazenar valor de A
	a = b; // A recebe valor de B
	b = aux; // B recebe valor de A que está em auxiliar
	
	printf("Valores trocados: A = %d | B = %d\n", a, b);
	
	return 0;
}