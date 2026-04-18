#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_PRODUTOS 100

enum Categoria {
    ELETRONICO,
    ALIMENTO,
    VESTUARIO,
    OUTROS
};

typedef struct {
    char nome[100];
    float preco;
    int quantidade;
    enum Categoria categoria;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutosCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarProduto();
void listarProdutos();
void filtrarPorCategoria();
void removerProduto();
char* obterTextoCategoria(enum Categoria c);
void exibirMenuCategoria();
int lerCategoria();
int temProdutosCadastrados();
void imprimirProduto(int indice);

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
            cadastrarProduto();
            break;
        case 2:
            system("cls");
            listarProdutos();
            break;
        case 3:
            system("cls");
            filtrarPorCategoria();
            break;
        case 4:
            system("cls");
            removerProduto();
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
    printf("|           SISTEMA - PRODUTOS           |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Produto\n");
    printf("   [2] Listar Todos os Produtos\n");
    printf("   [3] Filtrar por Categoria\n");
    printf("   [4] Remover Produto\n");
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

void cadastrarProduto() {
    printf("|========================================|\n");
    printf("|         CADASTRAR NOVO PRODUTO         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numProdutosCadastrados >= MAX_PRODUTOS) {
            printf("   Limite de produtos atingido!\n");
            break;
        }

        Produto *p = &produtos[numProdutosCadastrados];

        printf("   Nome: ");
        fgets(p->nome, 100, stdin);
        p->nome[strcspn(p->nome, "\n")] = '\0';

        printf("   Preço: R$ ");
        scanf("%f", &p->preco);
        limparBuffer();

        printf("   Quantidade em estoque: ");
        scanf("%d", &p->quantidade);
        limparBuffer();

        exibirMenuCategoria();
        p->categoria = lerCategoria();

        numProdutosCadastrados++;

        printf("\n   Produto cadastrado com sucesso!\n\n");

        printf("   Deseja cadastrar outro produto?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarProdutos() {
    printf("|========================================|\n");
    printf("|            LISTAR PRODUTOS             |\n");
    printf("|========================================|\n\n");

    if (!temProdutosCadastrados()) return;

    for (int i = 0; i < numProdutosCadastrados; i++) {
        imprimirProduto(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d produto(s) cadastrado(s)\n", numProdutosCadastrados);
}

void filtrarPorCategoria() {
    printf("|========================================|\n");
    printf("|          FILTRAR POR CATEGORIA         |\n");
    printf("|========================================|\n\n");

    if (!temProdutosCadastrados()) return;

    exibirMenuCategoria();
    int cat = lerCategoria();

    int encontrados = 0;

    for (int i = 0; i < numProdutosCadastrados; i++) {
        if (produtos[i].categoria == cat) {
            if (encontrados == 0)
                printf("   Produtos em [%s]:\n", obterTextoCategoria(cat));
            imprimirProduto(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("   Nenhum produto na categoria [%s].\n\n", obterTextoCategoria(cat));
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d produto(s) encontrado(s)\n", encontrados);
    }
}

void removerProduto() {
    printf("|========================================|\n");
    printf("|            REMOVER PRODUTO             |\n");
    printf("|========================================|\n\n");

    if (!temProdutosCadastrados()) return;

    printf("   Produtos cadastrados:\n\n");

    for (int i = 0; i < numProdutosCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s - R$ %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual produto deseja remover? (1-%d): ", numProdutosCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numProdutosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numProdutosCadastrados);
        }
    } while (escolha < 1 || escolha > numProdutosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", produtos[indice].nome);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numProdutosCadastrados - 1; i++) {
        produtos[i] = produtos[i + 1];
    }

    numProdutosCadastrados--;
    printf("   Produto removido com sucesso!\n");
}

char* obterTextoCategoria(enum Categoria c) {
    switch (c) {
        case ELETRONICO: return "Eletrônico";
        case ALIMENTO:   return "Alimento";
        case VESTUARIO:  return "Vestuário";
        case OUTROS:     return "Outros";
        default:         return "Desconhecido";
    }
}

void exibirMenuCategoria() {
    printf("\n   Categoria:\n");
    printf("   [0] Eletrônico\n");
    printf("   [1] Alimento\n");
    printf("   [2] Vestuário\n");
    printf("   [3] Outros\n");
    printf("   Escolha: ");
}

int lerCategoria() {
    int cat;
    do {
        cat = validarOpcao();
        if (cat < 0 || cat > 3) {
            printf("   Categoria inválida! Digite 0, 1, 2 ou 3: ");
        }
    } while (cat < 0 || cat > 3);
    return cat;
}

int temProdutosCadastrados() {
    if (numProdutosCadastrados == 0) {
        printf("   Nenhum produto cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void imprimirProduto(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Produto #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Nome:       %s\n", produtos[indice].nome);
    printf("   Preço:      R$ %.2f\n", produtos[indice].preco);
    printf("   Estoque:    %d unidade(s)\n", produtos[indice].quantidade);
    printf("   Categoria:  %s\n", obterTextoCategoria(produtos[indice].categoria));
}
