#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_LIVROS 100

typedef struct {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    enum Status status;
} Livro;

enum Status {
    DISPONIVEL, // = 0
    EMPRESTADO, // = 1
    MANUTENCAO  // = 2
};

Livro livros[MAX_LIVROS];
int numLivrosCadastrados = 0;

int validarOpcao();
void limparBuffer();
void menu();
void cadastrarLivros();
void listarLivros();
void buscarPorTitulo();
void filtrarPorStatus();
void removerLivro();
char* obterTextoStatus(int Status s);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op;

    do {
        menu();
        printf("\n   Escolha: ");
        validarOpcao();

        printf("\n");

        switch (op) {
        case 1:
            system("cls");
            cadastrarLivro();
            break;
        case 2:
            system("cls");
            listarLivros();
            break;
        case 3:
            system("cls");
            buscarPorTitulo();
            break;
        case 4:
            system("cls");
            filtrarPorStatus();
            break;
        case 5:
            system("cls");
            removerLivro();
            break;
        case 0:
            printf("    Até logo!\n\n");
            printf("|========================================|\n");
            break;
        default:
            printf("    Opção inválida! Tente novamente!\n\n");
        }

        if (op != 0) {
            printf("\n|===========================================|\n");
            system("pause");
            system("cls");
        }

    } while (op != 0);

    return 0;
}

void removerLivro() {

}

char* obterTextoStatus(int Status s) {

}

void filtrarPorStatus() {

}

void buscarPorTitulo() {

}

void listarLivros() {

}

void cadastrarLivro() {

}

void menu() {
    printf("|========================================|\n");
    printf("|          SISTEMA - BIBLIOTECA          |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Livro\n");
    printf("   [2] Listar Todos os Livros\n");
    printf("   [3] Buscar por Título\n");
    printf("   [4] Filtrar por Status\n");
    printf("   [5] Remover Livro\n");
    printf("   [0] Voltar ao Index\n\n");
}

int validarOpcao() {
    int op;
    int leitura;

    do {
    leitura = scanf("%d", &op);
    limparBuffer();

    if(leitura == 0) {
        printf("   Entrada inválida! Digite um número: ");
        }

    } while(leitura == 0);

    return op;
}

void limparBuffer() {
    int c;

    while ((c = getchar()) != '\n' && EOF);
}
