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
void filtrarPorStatus();               // FEITO
void removerLivro();                   // FEITO
int temLivrosCadastrados();     // ADICIONADO
void exibirMenuStatus();        // ADICIONADO
int lerStatusFiltro();          // ADICIONADO
void imprimirLivro(int indice); // ADICIONADO

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

    if(!temLivrosCadastrados()) {
        return;
    }

    int continuarCadastro;

    do {
        if(numLivrosCadastrados > MAX_LIVROS) {
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

        exibirMenuStatus();

        int statusFiltro = lerStatusFiltro();

        livroAtual->status = statusFiltro;

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

    if(!temLivrosCadastrados()) {
        return;
    }

    for(int i = 0; i < numLivrosCadastrados; i++) {
        imprimirLivro(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d livro(s) cadastrado(s)", numLivrosCadastrados);
}

void buscarPorTitulo() {
    printf("|========================================|\n");
    printf("|              BUSCAR LIVRO              |\n");
    printf("|========================================|\n\n");

    if(!temLivrosCadastrados()) {
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

        imprimirLivro(i);
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
    printf("|========================================|\n");
    printf("|           FILTRAR POR STATUS           |\n");
    printf("|========================================|\n\n");

    if(!temLivrosCadastrados()) {
        return;
    }

    exibirMenuStatus();
    int statusFiltro = lerStatusFiltro();

    int encontrados = 0;
    for (int i = 0; i < numLivrosCadastrados; i++) {
        if (livros[i].status == statusFiltro) {
            if (encontrados == 0) {
                printf("   Livros com status [%s] encontrados:\n",
                       obterTextoStatus(statusFiltro));
            }

            imprimirLivro(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("   Nenhum livro com status [%s].\n\n",
               obterTextoStatus(statusFiltro));
    } else {
        printf("\n   --------------------------------------|\n");
        printf("   Total: %d livro(s) encontrado(s)\n", encontrados);
    }
}

void removerLivro() {
    printf("|========================================|\n");
    printf("|              REMOVER LIVRO             |\n");
    printf("|========================================|\n\n");

    if(!temLivrosCadastrados()) {
        return;
    }

    printf("   Livros cadastrados:\n\n");

    for(int i = 0; i < numLivrosCadastrados; i++) {
        printf("   ----------------------------------|\n");
        printf("   [%d] %s\n", i + 1, livros[i].titulo);
        printf("   Autor: %s\n", livros[i].autor);
    }

    printf("   ----------------------------------|\n");

    printf("   Qual livro deseja remover? (1-%d): ", numLivrosCadastrados);

    int escolha;

    do {
        escolha = validarOpcao();

        if(escolha < 1 || escolha > numLivrosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d", numLivrosCadastrados);
        }
    } while(escolha < 1 || escolha > numLivrosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", livros[indice].titulo);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if(confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for(int i = indice; i < numLivrosCadastrados - 1; i++) {
        livros[i] = livros[i + 1];
    }

    numLivrosCadastrados--;

    printf("   Livro removido com sucesso!\n");
}

int temLivrosCadastrados() {
    if(numLivrosCadastrados == 0) {
        printf("   Nenhum livro cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void exibirMenuStatus() {
    printf("   Status para filtrar:\n");
    printf("   [0] DISPONÍVEL\n");
    printf("   [1] EMPRESTADO\n");
    printf("   [2] MANUTENÇÃO\n");
    printf("   Escolha: ");
}

int limiteCadastrosAtingido() {
    if(numLivrosCadastrados >= MAX_LIVROS) {
        printf("   Limite atingido!\n");
        return 0;
    }
        return 1;
}

int lerStatusFiltro() {
    int statusFiltro;

    do {
        statusFiltro = validarOpcao();

        if(statusFiltro < 0 || statusFiltro > 2) {
                printf("   Status inválido! Digite 0, 1 ou 2");
        }
    } while(statusFiltro < 0 || statusFiltro > 2);

    return statusFiltro;
}

void imprimirLivro(int indice) {
    printf("\n   ──────────────────────────────────────\n");
    printf("   Livro #%d\n", indice + 1);
    printf("   ──────────────────────────────────────\n");
    printf("   Título:  %s\n", livros[indice].titulo);
    printf("   Autor:   %s\n", livros[indice].autor);
    printf("   Ano:     %d\n", livros[indice].anoPublicacao);
    printf("   Status:  %s\n", obterTextoStatus(livros[indice].status));
}
