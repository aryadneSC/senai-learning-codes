#include <stdio.h>
#include <stdlib.h>

/*1. Faca um programa que possua um vetor denominado A que armazene 6 numeros inteiros. 
O programa deve executar os seguintes passos:

(a) Atribua os seguintes valores a esse vetor: 1, 0, 5, -2, -5, 7.
(b) Armazene em uma variavel inteira (simples) a soma entre os valores 
das posicoes A[0], A[1] e A[5] do vetor e mostre na tela esta soma.
(c) Modifique o vetor na posicao 4, atribuindo a esta posicao o valor 
100.
(d) Mostre na tela cada valor do vetor A, um em cada linha.

int main() {
	int A[6] = {1, 0, 5, -2, -5, 7};
	int soma = 0;
	
	printf("Soma = %d\n", soma = A[0] + A[1] + A[5]);
	
	A[4] = 100;
	
	for(int i = 0; i < 6; i++) {
		printf("Valor na posicao %d: %d\n", i, A[i]);
	}
	
	return 0;
}*/

/*2. Crie um programa que le 6 valores inteiros e, 
em seguida, mostre na tela os valores lidos.

int main() {
	int vetor[6];
	
	for(int i = 0; i < 6; i++) {
		printf("Insira o %do valor: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	
	printf("\n");
	
	printf("Valores lidos:\n");
	for(int j = 0; j < 6; j++) {
		printf("%d\n", vetor[j]);
	}
	
	return 0;
}*/

/*3. Ler um conjunto de numeros reais, armazenando-o 
em vetor e calcular a raiz dos
componentes deste vetor, armazenando o resultado em 
outro vetor. Os conjuntos tem
10 elementos cada. Imprimir todos os conjuntos.*/

#include <math.h>

int main() {
    float numeros[10]; 
    float resultados[10]; 
    
    for(int i = 0; i < 10; i++) {
        printf("Insira o %do valor: ", i + 1);
        scanf("%f", &numeros[i]);
    }
    
    for(int j = 0; j < 10; j++) {
        if(numeros[j] < 0) {
			printf("Posicao [%d]: Valor invalido!\n", j);
        } else {
            resultados[j] = sqrt(numeros[j]);
		
		printf("\nPosicao [%d]: raiz de %.2f -> %.2f\n", j, numeros[j], resultados[j]);
        
		}
    }
    
    return 0;
}