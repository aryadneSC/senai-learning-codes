#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILMES 100

enum Genero {
    ACAO,
    COMEDIA,
    DRAMA,
    TERROR,
    FICCAO_CIENTIFICA,
    DOCUMENTARIO
};

typedef struct {
    char titulo[100];
    char diretor[100];
    int ano;
    float nota;
    enum Genero genero;
} Filme;

Filme filmes[MAX_FILMES];
int numFilmesCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarFilme();
void listarFilmes();
void filtrarPorGenero();
void buscarPorTitulo();
void removerFilme();
char* obterTextoGenero(enum Genero g);
void exibirMenuGenero();
int lerGenero();
int temFilmesCadastrados();
void imprimirFilme(int indice);
void converterParaMinuscula(char *str);

int main() {
    setlocale(LC_ALL, "pt-br.UTF-8");
    int op;

    do {
        menu();
        printf("\n   Escolha: ");
        op = validarOpcao();
        printf("\n");

        switch (op) {
        case 1:
            system("cls");
            cadastrarFilme();
            break;
        case 2:
            system("cls");
            listarFilmes();
            break;
        case 3:
            system("cls");
            filtrarPorGenero();
            break;
        case 4:
            system("cls");
            buscarPorTitulo();
            break;
        case 5:
            system("cls");
            removerFilme();
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
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu() {
    printf("|========================================|\n");
    printf("|            SISTEMA - FILMES            |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Filme\n");
    printf("   [2] Listar Todos os Filmes\n");
    printf("   [3] Filtrar por Gênero\n");
    printf("   [4] Buscar por Título\n");
    printf("   [5] Remover Filme\n");
    printf("   [0] Sair\n\n");
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

void cadastrarFilme() {
    printf("|========================================|\n");
    printf("|          CADASTRAR NOVO FILME          |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numFilmesCadastrados >= MAX_FILMES) {
            printf("   Limite de filmes atingido!\n");
            break;
        }

        Filme *f = &filmes[numFilmesCadastrados];

        printf("   Título: ");
        fgets(f->titulo, 100, stdin);
        f->titulo[strcspn(f->titulo, "\n")] = '\0';

        printf("   Diretor: ");
        fgets(f->diretor, 100, stdin);
        f->diretor[strcspn(f->diretor, "\n")] = '\0';

        printf("   Ano: ");
        scanf("%d", &f->ano);
        limparBuffer();

        printf("   Nota (0.0 a 10.0): ");
        scanf("%f", &f->nota);
        limparBuffer();

        exibirMenuGenero();
        f->genero = lerGenero();

        numFilmesCadastrados++;

        printf("\n   Filme cadastrado com sucesso!\n\n");

        printf("   Deseja cadastrar outro filme?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarFilmes() {
    printf("|========================================|\n");
    printf("|             LISTAR FILMES              |\n");
    printf("|========================================|\n\n");

    if (!temFilmesCadastrados()) return;

    for (int i = 0; i < numFilmesCadastrados; i++) {
        imprimirFilme(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d filme(s) cadastrado(s)\n", numFilmesCadastrados);
}

void filtrarPorGenero() {
    printf("|========================================|\n");
    printf("|           FILTRAR POR GENERO           |\n");
    printf("|========================================|\n\n");

    if (!temFilmesCadastrados()) return;

    exibirMenuGenero();
    int gen = lerGenero();

    int encontrados = 0;

    for (int i = 0; i < numFilmesCadastrados; i++) {
        if (filmes[i].genero == gen) {
            if (encontrados == 0)
                printf("   Filmes em [%s]:\n", obterTextoGenero(gen));
            imprimirFilme(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("   Nenhum filme no gênero [%s].\n\n", obterTextoGenero(gen));
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d filme(s) encontrado(s)\n", encontrados);
    }
}

void buscarPorTitulo() {
    printf("|========================================|\n");
    printf("|             BUSCAR FILME               |\n");
    printf("|========================================|\n\n");

    if (!temFilmesCadastrados()) return;

    char busca[100];
    printf("   Digite o título (ou parte dele): ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    char buscaMin[100];
    strcpy(buscaMin, busca);
    converterParaMinuscula(buscaMin);

    int encontrados = 0;

    for (int i = 0; i < numFilmesCadastrados; i++) {
        char tituloMin[100];
        strcpy(tituloMin, filmes[i].titulo);
        converterParaMinuscula(tituloMin);

        if (strstr(tituloMin, buscaMin) != NULL) {
            if (encontrados == 0) printf("\n   Filmes encontrados:\n");
            imprimirFilme(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\n   Nenhum filme encontrado com '%s'.\n", busca);
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d filme(s) encontrado(s)\n", encontrados);
    }
}

void removerFilme() {
    printf("|========================================|\n");
    printf("|             REMOVER FILME              |\n");
    printf("|========================================|\n\n");

    if (!temFilmesCadastrados()) return;

    printf("   Filmes cadastrados:\n\n");

    for (int i = 0; i < numFilmesCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s (%d)\n", i + 1, filmes[i].titulo, filmes[i].ano);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual filme deseja remover? (1-%d): ", numFilmesCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numFilmesCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numFilmesCadastrados);
        }
    } while (escolha < 1 || escolha > numFilmesCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", filmes[indice].titulo);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numFilmesCadastrados - 1; i++) {
        filmes[i] = filmes[i + 1];
    }

    numFilmesCadastrados--;
    printf("   Filme removido com sucesso!\n");
}

char* obterTextoGenero(enum Genero g) {
    switch (g) {
        case ACAO:              return "Ação";
        case COMEDIA:           return "Comédia";
        case DRAMA:             return "Drama";
        case TERROR:            return "Terror";
        case FICCAO_CIENTIFICA: return "Ficção Científica";
        case DOCUMENTARIO:      return "Documentário";
        default:                return "Desconhecido";
    }
}

void exibirMenuGenero() {
    printf("\n   Gênero:\n");
    printf("   [0] Ação\n");
    printf("   [1] Comédia\n");
    printf("   [2] Drama\n");
    printf("   [3] Terror\n");
    printf("   [4] Ficção Científica\n");
    printf("   [5] Documentário\n");
    printf("   Escolha: ");
}

int lerGenero() {
    int g;
    do {
        g = validarOpcao();
        if (g < 0 || g > 5) {
            printf("   Gênero inválido! Digite entre 0 e 5: ");
        }
    } while (g < 0 || g > 5);
    return g;
}

int temFilmesCadastrados() {
    if (numFilmesCadastrados == 0) {
        printf("   Nenhum filme cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void converterParaMinuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void imprimirFilme(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Filme #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Título:   %s\n", filmes[indice].titulo);
    printf("   Diretor:  %s\n", filmes[indice].diretor);
    printf("   Ano:      %d\n", filmes[indice].ano);
    printf("   Nota:     %.1f\n", filmes[indice].nota);
    printf("   Gênero:   %s\n", obterTextoGenero(filmes[indice].genero));
}
