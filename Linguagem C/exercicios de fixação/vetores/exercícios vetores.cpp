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
10 elementos cada. Imprimir todos os conjuntos.

#include <math.h>

int main() {
    float numeros[10]; 
    float resultados[10]; 
    
    for(int i = 0; i < 10; i++) {
        printf("Insira o %do valor: ", i + 1);
        scanf("%f", &numeros[i]);
    }
    
    printf("\n");
    
    for(int j = 0; j < 10; j++) {
        if(numeros[j] < 0) {
			printf("Posicao [%d]: Valor invalido!\n", j);
        } else {
            resultados[j] = sqrt(numeros[j]);
		
		printf("Posicao [%d]: raiz de %.2f -> %.2f\n", j, numeros[j], resultados[j]);
        
		}
    }
    
    return 0;
}*/

/*4. Faca um programa que leia um vetor de 8 posicoes e, 
em seguida, leia tambem dois valores X e Y quaisquer 
correspondentes a duas posicoes no vetor. 
Ao final seu programa devera escrever a soma dos valores 
encontrados nas respectivas posicoes X e Y .

int main() {
    
    int vetorNumeros[8];
    int posicaoX, posicaoY;
    int somaDosValoresSelecionados = 0;
    int verificaEntradaValida = 0; 
    
    printf("|------------- Armazene 8 valores -----------|\n");
    
    for(int i = 0; i < 8; i++) {
        printf("Insira o valor para posicao %d: ", i);
        scanf("%d", &vetorNumeros[i]); 
    }
    
    system("pause");
    system("cls");

    do {
        fflush(stdin); 
        
        printf("|- Escolha duas posicoes entre 0 e 7 para somar -|\n\n");
        
        printf("Digite a posicao X desejada: ");
        scanf("%d", &posicaoX);
        
        printf("Digite a posicao Y desejada: ");
        scanf("%d", &posicaoY);
        
        if(posicaoX >= 0 && posicaoX < 8 && posicaoY >= 0 && posicaoY < 8) {
            
            somaDosValoresSelecionados = vetorNumeros[posicaoX] + vetorNumeros[posicaoY];
            
            printf("\nValor encontrado na posicao [%d]: %d\n", posicaoX, vetorNumeros[posicaoX]);
            printf("Valor encontrado na posicao [%d]: %d\n", posicaoY, vetorNumeros[posicaoY]);
            printf("\nSoma final = %d\n", somaDosValoresSelecionados);
            
            verificaEntradaValida = 1; 
            
        } else {
            printf("\n[ERRO] Posicao invalida! Por favor, escolha entre 0 e 7.\n");
        
        }
        
        if (verificaEntradaValida == 0) {
            system("pause");
            system("cls");
        }
    
    } while (verificaEntradaValida == 0);
    
    return 0;    
}*/

/*5. Leia um vetor de 10 posicoes. 
Contar e escrever quantos valores pares ele possui.

int verificaSeEhPar(int numeroVerificado);

int main() {
	int vetorNumeros[10];
	int quantidadeNumPares = 0;
	
	printf("\t|---- Guarde 10 numeros ----|\n\n");
	for(int i = 0; i < 10; i++) {
		printf("Insira o %do numero: ", i + 1);
		scanf("%d", &vetorNumeros[i]);
	}
	
	system("cls");
	fflush(stdin);
	
	printf("\t|------ Numeros Pares ------|\n\n");
	for(int j = 0; j < 10; j++) {
		if(verificaSeEhPar(vetorNumeros[j]) == 1) {
			quantidadeNumPares++;
			printf(" %d | ", vetorNumeros[j]);
		}
	}
	
	printf("\n\nTotal de numeros pares: %d\n", quantidadeNumPares);
	
	return 0;
}

int verificaSeEhPar(int numeroVerificado) {
	
	if(numeroVerificado % 2 == 0) {
		return 1; // retorna TRUE
	} else {
		return 0; // retorno FALSE
	}
}*/

/*6. Faca um programa que receba do usuario 
um vetor com 10 posicoes. Em seguida devera
ser impresso o maior e o menor elemento do vetor.

int main() {
	int vetorNumeros[10];
	int maiorValor, menorValor;
	
	for(int i = 0; i < 10; i++) {
		printf("Insira o %do valor: ", i + 1);
		scanf("%d", &vetorNumeros[i]);
	}
	
	maiorValor = vetorNumeros[0];
	menorValor = vetorNumeros[0];
	
	for(int j = 1; j < 10; j++) {
		if(vetorNumeros[j] > maiorValor) {
			maiorValor = vetorNumeros[j];
		} if (vetorNumeros[j] < menorValor) {
			menorValor = vetorNumeros[j];
		}
	}
	
	system("cls");
	fflush(stdin);
	
	printf("## VALORES ARMAZENADOS ##\n");
	for(int i = 0; i < 10; i++) {
		printf(" %d |", vetorNumeros[i]);
	}
	
	printf("\n");
	printf("\n## COMPARANDO VALORES ##\n");
	printf("MAIOR VALOR: %d | MENOR VALOR: %d\n", maiorValor, menorValor);
	
	return 0;
} */

