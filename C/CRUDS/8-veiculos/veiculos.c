#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_VEICULOS 100

enum TipoVeiculo {
    CARRO,
    MOTO,
    CAMINHAO,
    ONIBUS
};

typedef struct {
    char marca[50];
    char modelo[100];
    int ano;
    float preco;
    enum TipoVeiculo tipo;
} Veiculo;

Veiculo veiculos[MAX_VEICULOS];
int numVeiculosCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarVeiculo();
void listarVeiculos();
void filtrarPorTipo();
void removerVeiculo();
char* obterTextoTipo(enum TipoVeiculo t);
void exibirMenuTipo();
int lerTipo();
int temVeiculosCadastrados();
void imprimirVeiculo(int indice);

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
            cadastrarVeiculo();
            break;
        case 2:
            system("cls");
            listarVeiculos();
            break;
        case 3:
            system("cls");
            filtrarPorTipo();
            break;
        case 4:
            system("cls");
            removerVeiculo();
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
    printf("|           SISTEMA - VEICULOS           |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Veículo\n");
    printf("   [2] Listar Todos os Veículos\n");
    printf("   [3] Filtrar por Tipo\n");
    printf("   [4] Remover Veículo\n");
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

void cadastrarVeiculo() {
    printf("|========================================|\n");
    printf("|         CADASTRAR NOVO VEICULO         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numVeiculosCadastrados >= MAX_VEICULOS) {
            printf("   Limite de veículos atingido!\n");
            break;
        }

        Veiculo *v = &veiculos[numVeiculosCadastrados];

        printf("   Marca: ");
        fgets(v->marca, 50, stdin);
        v->marca[strcspn(v->marca, "\n")] = '\0';

        printf("   Modelo: ");
        fgets(v->modelo, 100, stdin);
        v->modelo[strcspn(v->modelo, "\n")] = '\0';

        printf("   Ano: ");
        scanf("%d", &v->ano);
        limparBuffer();

        printf("   Preço: R$ ");
        scanf("%f", &v->preco);
        limparBuffer();

        exibirMenuTipo();
        v->tipo = lerTipo();

        numVeiculosCadastrados++;

        printf("\n   Veículo cadastrado com sucesso!\n\n");

        printf("   Deseja cadastrar outro veículo?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarVeiculos() {
    printf("|========================================|\n");
    printf("|            LISTAR VEICULOS             |\n");
    printf("|========================================|\n\n");

    if (!temVeiculosCadastrados()) return;

    for (int i = 0; i < numVeiculosCadastrados; i++) {
        imprimirVeiculo(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d veículo(s) cadastrado(s)\n", numVeiculosCadastrados);
}

void filtrarPorTipo() {
    printf("|========================================|\n");
    printf("|            FILTRAR POR TIPO            |\n");
    printf("|========================================|\n\n");

    if (!temVeiculosCadastrados()) return;

    exibirMenuTipo();
    int tipo = lerTipo();

    int encontrados = 0;

    for (int i = 0; i < numVeiculosCadastrados; i++) {
        if (veiculos[i].tipo == tipo) {
            if (encontrados == 0)
                printf("   Veículos do tipo [%s]:\n", obterTextoTipo(tipo));
            imprimirVeiculo(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("   Nenhum veículo do tipo [%s].\n\n", obterTextoTipo(tipo));
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d veículo(s) encontrado(s)\n", encontrados);
    }
}

void removerVeiculo() {
    printf("|========================================|\n");
    printf("|            REMOVER VEICULO             |\n");
    printf("|========================================|\n\n");

    if (!temVeiculosCadastrados()) return;

    printf("   Veículos cadastrados:\n\n");

    for (int i = 0; i < numVeiculosCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s %s (%d)\n", i + 1, veiculos[i].marca, veiculos[i].modelo, veiculos[i].ano);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual veículo deseja remover? (1-%d): ", numVeiculosCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numVeiculosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numVeiculosCadastrados);
        }
    } while (escolha < 1 || escolha > numVeiculosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s %s'?\n", veiculos[indice].marca, veiculos[indice].modelo);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numVeiculosCadastrados - 1; i++) {
        veiculos[i] = veiculos[i + 1];
    }

    numVeiculosCadastrados--;
    printf("   Veículo removido com sucesso!\n");
}

char* obterTextoTipo(enum TipoVeiculo t) {
    switch (t) {
        case CARRO:    return "Carro";
        case MOTO:     return "Moto";
        case CAMINHAO: return "Caminhão";
        case ONIBUS:   return "Ônibus";
        default:       return "Desconhecido";
    }
}

void exibirMenuTipo() {
    printf("\n   Tipo:\n");
    printf("   [0] Carro\n");
    printf("   [1] Moto\n");
    printf("   [2] Caminhão\n");
    printf("   [3] Ônibus\n");
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

int temVeiculosCadastrados() {
    if (numVeiculosCadastrados == 0) {
        printf("   Nenhum veículo cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void imprimirVeiculo(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Veículo #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Marca:  %s\n", veiculos[indice].marca);
    printf("   Modelo: %s\n", veiculos[indice].modelo);
    printf("   Ano:    %d\n", veiculos[indice].ano);
    printf("   Preço:  R$ %.2f\n", veiculos[indice].preco);
    printf("   Tipo:   %s\n", obterTextoTipo(veiculos[indice].tipo));
}
