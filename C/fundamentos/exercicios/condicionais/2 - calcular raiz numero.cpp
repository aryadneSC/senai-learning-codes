/*2. Leia um numero fornecido pelo usuario. 
Se esse numero for positivo, calcule a raiz
quadrada do numero. Se o numero for negativo, 
mostre uma mensagem dizendo que o numero e invalido.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // para usar sqrt, calcular raiz quadrada

void calculaRaiz(int a);

int main() {

    int valor;

    printf("Insira um numero para calcular a raiz: ");
    scanf("%d", &valor);

    calculaRaiz(valor); 

    return 0;
}

void calculaRaiz(int a) {
    if (a >= 0) { 
        int raiz = sqrt(a); 
        printf("A raiz de %d eh: %d\n", a, raiz);
    } else {
        printf("Numero invalido! Nao existe raiz real de numero negativo.\n");
    }
}
