#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

Contato contatos[MAX_CONTATOS];
int numContatosCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarContato();
void listarContatos();
void buscarPorNome();
void removerContato();
void converterParaMinuscula(char *str);
int temContatosCadastrados();
void imprimirContato(int indice);

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
            cadastrarContato();
            break;
        case 2:
            system("cls");
            listarContatos();
            break;
        case 3:
            system("cls");
            buscarPorNome();
            break;
        case 4:
            system("cls");
            removerContato();
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
    printf("|          SISTEMA - CONTATOS            |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Contato\n");
    printf("   [2] Listar Todos os Contatos\n");
    printf("   [3] Buscar por Nome\n");
    printf("   [4] Remover Contato\n");
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

void cadastrarContato() {
    printf("|========================================|\n");
    printf("|         CADASTRAR NOVO CONTATO         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numContatosCadastrados >= MAX_CONTATOS) {
            printf("   Limite de contatos atingido!\n");
            break;
        }

        Contato *c = &contatos[numContatosCadastrados];

        printf("   Nome: ");
        fgets(c->nome, 100, stdin);
        c->nome[strcspn(c->nome, "\n")] = '\0';

        printf("   Telefone: ");
        fgets(c->telefone, 20, stdin);
        c->telefone[strcspn(c->telefone, "\n")] = '\0';

        printf("   E-mail: ");
        fgets(c->email, 100, stdin);
        c->email[strcspn(c->email, "\n")] = '\0';

        numContatosCadastrados++;

        printf("\n   Contato cadastrado com sucesso!\n\n");

        printf("   Deseja cadastrar outro contato?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarContatos() {
    printf("|========================================|\n");
    printf("|            LISTAR CONTATOS             |\n");
    printf("|========================================|\n\n");

    if (!temContatosCadastrados()) return;

    for (int i = 0; i < numContatosCadastrados; i++) {
        imprimirContato(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d contato(s) cadastrado(s)\n", numContatosCadastrados);
}

void buscarPorNome() {
    printf("|========================================|\n");
    printf("|            BUSCAR CONTATO              |\n");
    printf("|========================================|\n\n");

    if (!temContatosCadastrados()) return;

    char busca[100];
    printf("   Digite o nome (ou parte dele): ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    char buscaMin[100];
    strcpy(buscaMin, busca);
    converterParaMinuscula(buscaMin);

    int encontrados = 0;

    for (int i = 0; i < numContatosCadastrados; i++) {
        char nomeMin[100];
        strcpy(nomeMin, contatos[i].nome);
        converterParaMinuscula(nomeMin);

        if (strstr(nomeMin, buscaMin) != NULL) {
            if (encontrados == 0) printf("\n   Contatos encontrados:\n");
            imprimirContato(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\n   Nenhum contato encontrado com '%s'.\n", busca);
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d contato(s) encontrado(s)\n", encontrados);
    }
}

void converterParaMinuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void removerContato() {
    printf("|========================================|\n");
    printf("|            REMOVER CONTATO             |\n");
    printf("|========================================|\n\n");

    if (!temContatosCadastrados()) return;

    printf("   Contatos cadastrados:\n\n");

    for (int i = 0; i < numContatosCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s\n", i + 1, contatos[i].nome);
        printf("   Tel: %s\n", contatos[i].telefone);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual contato deseja remover? (1-%d): ", numContatosCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numContatosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numContatosCadastrados);
        }
    } while (escolha < 1 || escolha > numContatosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", contatos[indice].nome);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numContatosCadastrados - 1; i++) {
        contatos[i] = contatos[i + 1];
    }

    numContatosCadastrados--;
    printf("   Contato removido com sucesso!\n");
}

int temContatosCadastrados() {
    if (numContatosCadastrados == 0) {
        printf("   Nenhum contato cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void imprimirContato(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Contato #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Nome:     %s\n", contatos[indice].nome);
    printf("   Telefone: %s\n", contatos[indice].telefone);
    printf("   E-mail:   %s\n", contatos[indice].email);
}
