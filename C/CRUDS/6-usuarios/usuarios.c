#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_USUARIOS 100

enum Perfil {
    ADMIN,
    COMUM,
    VISITANTE
};

typedef struct {
    char nome[100];
    char email[100];
    int idade;
    enum Perfil perfil;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
int numUsuariosCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarUsuario();
void listarUsuarios();
void buscarPorEmail();
void removerUsuario();
char* obterTextoPerfil(enum Perfil p);
void exibirMenuPerfil();
int lerPerfil();
int temUsuariosCadastrados();
void imprimirUsuario(int indice);

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
            cadastrarUsuario();
            break;
        case 2:
            system("cls");
            listarUsuarios();
            break;
        case 3:
            system("cls");
            buscarPorEmail();
            break;
        case 4:
            system("cls");
            removerUsuario();
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
    printf("|           SISTEMA - USUARIOS           |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Usuário\n");
    printf("   [2] Listar Todos os Usuários\n");
    printf("   [3] Buscar por E-mail\n");
    printf("   [4] Remover Usuário\n");
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

void cadastrarUsuario() {
    printf("|========================================|\n");
    printf("|         CADASTRAR NOVO USUARIO         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numUsuariosCadastrados >= MAX_USUARIOS) {
            printf("   Limite de usuários atingido!\n");
            break;
        }

        Usuario *u = &usuarios[numUsuariosCadastrados];

        printf("   Nome: ");
        fgets(u->nome, 100, stdin);
        u->nome[strcspn(u->nome, "\n")] = '\0';

        printf("   E-mail: ");
        fgets(u->email, 100, stdin);
        u->email[strcspn(u->email, "\n")] = '\0';

        printf("   Idade: ");
        scanf("%d", &u->idade);
        limparBuffer();

        exibirMenuPerfil();
        u->perfil = lerPerfil();

        numUsuariosCadastrados++;

        printf("\n   Usuário cadastrado com sucesso!\n\n");

        printf("   Deseja cadastrar outro usuário?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarUsuarios() {
    printf("|========================================|\n");
    printf("|            LISTAR USUARIOS             |\n");
    printf("|========================================|\n\n");

    if (!temUsuariosCadastrados()) return;

    for (int i = 0; i < numUsuariosCadastrados; i++) {
        imprimirUsuario(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d usuário(s) cadastrado(s)\n", numUsuariosCadastrados);
}

void buscarPorEmail() {
    printf("|========================================|\n");
    printf("|            BUSCAR USUARIO              |\n");
    printf("|========================================|\n\n");

    if (!temUsuariosCadastrados()) return;

    char busca[100];
    printf("   Digite o e-mail: ");
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (int i = 0; i < numUsuariosCadastrados; i++) {
        if (strcmp(usuarios[i].email, busca) == 0) {
            printf("\n   Usuário encontrado:\n");
            imprimirUsuario(i);
            return;
        }
    }

    printf("\n   Nenhum usuário com e-mail '%s' encontrado.\n", busca);
}

void removerUsuario() {
    printf("|========================================|\n");
    printf("|            REMOVER USUARIO             |\n");
    printf("|========================================|\n\n");

    if (!temUsuariosCadastrados()) return;

    printf("   Usuários cadastrados:\n\n");

    for (int i = 0; i < numUsuariosCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s - %s\n", i + 1, usuarios[i].nome, usuarios[i].email);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual usuário deseja remover? (1-%d): ", numUsuariosCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numUsuariosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numUsuariosCadastrados);
        }
    } while (escolha < 1 || escolha > numUsuariosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", usuarios[indice].nome);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numUsuariosCadastrados - 1; i++) {
        usuarios[i] = usuarios[i + 1];
    }

    numUsuariosCadastrados--;
    printf("   Usuário removido com sucesso!\n");
}

char* obterTextoPerfil(enum Perfil p) {
    switch (p) {
        case ADMIN:    return "Administrador";
        case COMUM:    return "Comum";
        case VISITANTE: return "Visitante";
        default:       return "Desconhecido";
    }
}

void exibirMenuPerfil() {
    printf("\n   Perfil:\n");
    printf("   [0] Administrador\n");
    printf("   [1] Comum\n");
    printf("   [2] Visitante\n");
    printf("   Escolha: ");
}

int lerPerfil() {
    int p;
    do {
        p = validarOpcao();
        if (p < 0 || p > 2) {
            printf("   Perfil inválido! Digite 0, 1 ou 2: ");
        }
    } while (p < 0 || p > 2);
    return p;
}

int temUsuariosCadastrados() {
    if (numUsuariosCadastrados == 0) {
        printf("   Nenhum usuário cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void imprimirUsuario(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Usuário #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Nome:   %s\n", usuarios[indice].nome);
    printf("   E-mail: %s\n", usuarios[indice].email);
    printf("   Idade:  %d anos\n", usuarios[indice].idade);
    printf("   Perfil: %s\n", obterTextoPerfil(usuarios[indice].perfil));
}
