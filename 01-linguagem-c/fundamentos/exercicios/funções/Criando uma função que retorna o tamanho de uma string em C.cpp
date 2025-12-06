#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrlen(char str[]);

int main() {
	char vet[20] = ("Hello");
	
	printf("strlen: %d\n", strlen(vet));
	printf("mystrlen: %d\n", myStrlen(vet));
	
	return 0;
}

int myStrlen(char str[]) {
	
	int tam = 0;
	
	while(str[tam] != '\0') {
		tam++;
	}
	return tam;
}