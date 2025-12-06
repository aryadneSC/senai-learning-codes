#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 100

enum Status {
    DISPONIVEL,
    EMPRESTADO,
    MANUTENCAO
};

typedef struct {
    char titulo[100];
    char autor[50];
    int anoPublicacao;
    enum Status status;
} Livro;

Livro livros[MAX_LIVROS];
int numLivrosCadastrados = 0;

void limparBuffer();                   // FEITO
void menu();                           // FEITO
int validarOpcao();                    // FEITO
void cadastrarLivro();                 // FEITO
char* obterTextoStatus(enum Status s); // FEITO
void listarLivros();                   // FEITO
void buscarPorTitulo();                // FEITO
void converterParaMinuscula(char *str);// FEITO
void filtrarPorStatus();               // TODO
void removerLivro();                   // TODO

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op;

    do {
        menu();
        printf("\n   Escolha: ");
        op = validarOpcao();
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
            printf("   Até logo!\n\n");
            printf("|========================================|\n");
            break;
        default:
            printf("   Opção inválida! Tente novamente!\n\n");
        }

        if (op != 0) {
            system("pause");
            system("cls");
        }

    } while (op != 0);

    return 0;
}

void limparBuffer() {
    int c;

    while((c = getchar()) != '\n' && c != EOF);
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

        if (leitura == 0) {
            printf("   Entrada inválida! Digite um número: ");
        }

    } while (leitura == 0);

    return op;
}

void cadastrarLivro() {
    printf("|========================================|\n");
    printf("|          CADASTRAR NOVO LIVRO          |\n");
    printf("|========================================|\n\n");

    if(numLivrosCadastrados >= MAX_LIVROS) {
        printf("   Limite de cadastros atingido!\n");
        return;
    }

    int continuarCadastro;

    do {
        if(numLivrosCadastrados >= MAX_LIVROS) {
            printf("   Limite atingido!\n");
            break;
        }

        Livro *livroAtual = &livros[numLivrosCadastrados];

        printf("   Título: ");
        fgets(livroAtual->titulo, 100, stdin);
        livroAtual->titulo[strcspn(livroAtual->titulo, "\n")] = '\0';

        printf("   Autor: ");
        fgets(livroAtual->autor, 50, stdin);
        livroAtual->autor[strcspn(livroAtual->autor, "\n")] = '\0';

        printf("   Ano de publicação: ");
        scanf("%d", &livroAtual->anoPublicacao);
        limparBuffer();

        printf("   \nStatus:\n");
        printf("   [0] Disponível\n");
        printf("   [1] Emprestado\n");
        printf("   [2] Manutenção\n\n");
        printf("   Escolha: ");

        int opcaoStatus;
        do {
            opcaoStatus = validarOpcao();
            if(opcaoStatus < 0 || opcaoStatus > 2) {
                printf("   Status inválido! Digite 0, 1 ou 2");
            }
        } while(opcaoStatus < 0 || opcaoStatus > 2);

        livroAtual->status = opcaoStatus;

        numLivrosCadastrados++;

        printf("\n   Livro cadastrado com sucesso!\n\n");

        printf("\n   Deseja cadastrar outro livro?\n");
        printf("\n   [1] Sim");
        printf("\n   [0] Não");
        printf("\n   Escolha: ");
        continuarCadastro = validarOpcao();

        system("cls");
        printf("|========================================|\n");
        printf("\n");

    } while(continuarCadastro == 1);
}

char* obterTextoStatus(enum Status s) {
    switch(s) {
        case DISPONIVEL:   return "Disponível";
        case EMPRESTADO:   return "Emprestado";
        case MANUTENCAO:   return "Manutenção";
        default:           return "Desconhecido";
    }
}

void listarLivros() {
    printf("|========================================|\n");
    printf("|              LISTAR LIVROS             |\n");
    printf("|========================================|\n\n");

    if(numLivrosCadastrados == 0) {
        printf("   Nenhum livro cadastrado!");
        return;
    }

    for(int i = 0; i < numLivrosCadastrados; i++) {
        printf("   ----------------------------------|\n");
        printf("   Livro #%d\n", i + 1);
        printf("   ----------------------------------|\n");
        printf("   Título: %s\n", livros[i].titulo);
        printf("   Autor(a): %s\n", livros[i].autor);
        printf("   Ano de publicação: %d\n", livros[i].anoPublicacao);
        printf("   Status: %s\n", obterTextoStatus(livros[i].status));
        printf("\n");
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d livro(s) cadastrado(s)", numLivrosCadastrados);
}

void buscarPorTitulo() {
    printf("|========================================|\n");
    printf("|              BUSCAR LIVRO              |\n");
    printf("|========================================|\n\n");

    if (numLivrosCadastrados == 0) {
        printf("   Nenhum livro cadastrado!\n");
        return;
    }

    char busca[100];
    printf("   Digite o título (ou parte dele): ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    char buscaMinuscula[100];
    strcpy(buscaMinuscula, busca);
    converterParaMinuscula(buscaMinuscula);

    int encontrados = 0;

    for (int i = 0; i < numLivrosCadastrados; i++) {
        char tituloMinusculo[100];
        strcpy(tituloMinusculo, livros[i].titulo);
        converterParaMinuscula(tituloMinusculo);

        if (strstr(tituloMinusculo, buscaMinuscula) != NULL) {
        if (encontrados == 0) {
            printf("\n   Livros encontrados:\n");
        }

        printf("\n   --------------------------------------|\n");
        printf("     Livro #%d\n", i + 1);
        printf("\n   --------------------------------------|\n");
        printf("   Título:  %s\n", livros[i].titulo);
        printf("   Autor:   %s\n", livros[i].autor);
        printf("   Ano:     %d\n", livros[i].anoPublicacao);
        printf("   Status:  %s\n", obterTextoStatus(livros[i].status));

        encontrados++;

        }
    }

        if (encontrados == 0) {
            printf("\n   Nenhum livro encontrado com '%s'.\n", busca);
        } else {
            printf("\n   --------------------------------------|\n");
            printf("   Total: %d livro(s) encontrado(s)\n", encontrados);
    }
}

void converterParaMinuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void filtrarPorStatus() {

}

void removerLivro() {

}
