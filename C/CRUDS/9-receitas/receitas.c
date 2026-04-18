#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECEITAS 100
#define MAX_INGREDIENTES 20

enum TipoReceita {
    ENTRADA,
    PRATO_PRINCIPAL,
    SOBREMESA,
    BEBIDA
};

typedef struct {
    char nome[100];
    char ingredientes[MAX_INGREDIENTES][100];
    int numIngredientes;
    int tempoPreparo;
    enum TipoReceita tipo;
} Receita;

Receita receitas[MAX_RECEITAS];
int numReceitasCadastradas = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarReceita();
void listarReceitas();
void buscarPorIngrediente();
void removerReceita();
char* obterTextoTipo(enum TipoReceita t);
void exibirMenuTipo();
int lerTipo();
int temReceitasCadastradas();
void imprimirReceita(int indice);
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
            cadastrarReceita();
            break;
        case 2:
            system("cls");
            listarReceitas();
            break;
        case 3:
            system("cls");
            buscarPorIngrediente();
            break;
        case 4:
            system("cls");
            removerReceita();
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
    printf("|           SISTEMA - RECEITAS           |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Receita\n");
    printf("   [2] Listar Todas as Receitas\n");
    printf("   [3] Buscar por Ingrediente\n");
    printf("   [4] Remover Receita\n");
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

void cadastrarReceita() {
    printf("|========================================|\n");
    printf("|         CADASTRAR NOVA RECEITA         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numReceitasCadastradas >= MAX_RECEITAS) {
            printf("   Limite de receitas atingido!\n");
            break;
        }

        Receita *r = &receitas[numReceitasCadastradas];
        r->numIngredientes = 0;

        printf("   Nome da receita: ");
        fgets(r->nome, 100, stdin);
        r->nome[strcspn(r->nome, "\n")] = '\0';

        printf("   Tempo de preparo (minutos): ");
        scanf("%d", &r->tempoPreparo);
        limparBuffer();

        exibirMenuTipo();
        r->tipo = lerTipo();

        printf("\n   Quantos ingredientes? (máx. %d): ", MAX_INGREDIENTES);
        int qtd;
        scanf("%d", &qtd);
        limparBuffer();

        if (qtd > MAX_INGREDIENTES) qtd = MAX_INGREDIENTES;

        for (int i = 0; i < qtd; i++) {
            printf("   Ingrediente %d: ", i + 1);
            fgets(r->ingredientes[i], 100, stdin);
            r->ingredientes[i][strcspn(r->ingredientes[i], "\n")] = '\0';
            r->numIngredientes++;
        }

        numReceitasCadastradas++;

        printf("\n   Receita cadastrada com sucesso!\n\n");

        printf("   Deseja cadastrar outra receita?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarReceitas() {
    printf("|========================================|\n");
    printf("|            LISTAR RECEITAS             |\n");
    printf("|========================================|\n\n");

    if (!temReceitasCadastradas()) return;

    for (int i = 0; i < numReceitasCadastradas; i++) {
        imprimirReceita(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d receita(s) cadastrada(s)\n", numReceitasCadastradas);
}

void buscarPorIngrediente() {
    printf("|========================================|\n");
    printf("|         BUSCAR POR INGREDIENTE         |\n");
    printf("|========================================|\n\n");

    if (!temReceitasCadastradas()) return;

    char busca[100];
    printf("   Digite o ingrediente: ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    char buscaMin[100];
    strcpy(buscaMin, busca);
    converterParaMinuscula(buscaMin);

    int encontrados = 0;

    for (int i = 0; i < numReceitasCadastradas; i++) {
        for (int j = 0; j < receitas[i].numIngredientes; j++) {
            char ingMin[100];
            strcpy(ingMin, receitas[i].ingredientes[j]);
            converterParaMinuscula(ingMin);

            if (strstr(ingMin, buscaMin) != NULL) {
                if (encontrados == 0)
                    printf("\n   Receitas com '%s':\n", busca);
                imprimirReceita(i);
                encontrados++;
                break;
            }
        }
    }

    if (encontrados == 0) {
        printf("\n   Nenhuma receita com o ingrediente '%s'.\n", busca);
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d receita(s) encontrada(s)\n", encontrados);
    }
}

void removerReceita() {
    printf("|========================================|\n");
    printf("|            REMOVER RECEITA             |\n");
    printf("|========================================|\n\n");

    if (!temReceitasCadastradas()) return;

    printf("   Receitas cadastradas:\n\n");

    for (int i = 0; i < numReceitasCadastradas; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s - %s\n", i + 1, receitas[i].nome, obterTextoTipo(receitas[i].tipo));
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual receita deseja remover? (1-%d): ", numReceitasCadastradas);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numReceitasCadastradas) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numReceitasCadastradas);
        }
    } while (escolha < 1 || escolha > numReceitasCadastradas);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", receitas[indice].nome);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numReceitasCadastradas - 1; i++) {
        receitas[i] = receitas[i + 1];
    }

    numReceitasCadastradas--;
    printf("   Receita removida com sucesso!\n");
}

char* obterTextoTipo(enum TipoReceita t) {
    switch (t) {
        case ENTRADA:         return "Entrada";
        case PRATO_PRINCIPAL: return "Prato Principal";
        case SOBREMESA:       return "Sobremesa";
        case BEBIDA:          return "Bebida";
        default:              return "Desconhecido";
    }
}

void exibirMenuTipo() {
    printf("\n   Tipo:\n");
    printf("   [0] Entrada\n");
    printf("   [1] Prato Principal\n");
    printf("   [2] Sobremesa\n");
    printf("   [3] Bebida\n");
    printf("   Escolha: ");
}

int lerTipo() {
    int t;
    do {
        t = validarOpcao();
        if (t < 0 || t > 3) {
            printf("   Tipo inválido! Digite entre 0 e 3: ");
        }
    } while (t < 0 || t > 3);
    return t;
}

void converterParaMinuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int temReceitasCadastradas() {
    if (numReceitasCadastradas == 0) {
        printf("   Nenhuma receita cadastrada!\n\n");
        return 0;
    }
    return 1;
}

void imprimirReceita(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Receita #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Nome:    %s\n", receitas[indice].nome);
    printf("   Tipo:    %s\n", obterTextoTipo(receitas[indice].tipo));
    printf("   Preparo: %d minuto(s)\n", receitas[indice].tempoPreparo);
    printf("   Ingredientes:\n");
    for (int i = 0; i < receitas[indice].numIngredientes; i++) {
        printf("     - %s\n", receitas[indice].ingredientes[i]);
    }
}
