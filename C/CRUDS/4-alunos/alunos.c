#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_ALUNOS 100

typedef struct {
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
    float media;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int numAlunosCadastrados = 0;

void limparBuffer();
void menu();
int validarOpcao();
void cadastrarAluno();
void listarAlunos();
void buscarPorMatricula();
void removerAluno();
float calcularMedia(float n1, float n2);
char* obterSituacao(float media);
int temAlunosCadastrados();
void imprimirAluno(int indice);

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
            cadastrarAluno();
            break;
        case 2:
            system("cls");
            listarAlunos();
            break;
        case 3:
            system("cls");
            buscarPorMatricula();
            break;
        case 4:
            system("cls");
            removerAluno();
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
    printf("|           SISTEMA - ALUNOS             |\n");
    printf("|========================================|\n\n");
    printf("   [1] Cadastrar Aluno\n");
    printf("   [2] Listar Todos os Alunos\n");
    printf("   [3] Buscar por Matrícula\n");
    printf("   [4] Remover Aluno\n");
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

void cadastrarAluno() {
    printf("|========================================|\n");
    printf("|          CADASTRAR NOVO ALUNO          |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numAlunosCadastrados >= MAX_ALUNOS) {
            printf("   Limite de alunos atingido!\n");
            break;
        }

        Aluno *a = &alunos[numAlunosCadastrados];

        printf("   Nome: ");
        fgets(a->nome, 100, stdin);
        a->nome[strcspn(a->nome, "\n")] = '\0';

        printf("   Matrícula: ");
        scanf("%d", &a->matricula);
        limparBuffer();

        printf("   Nota 1: ");
        scanf("%f", &a->nota1);
        limparBuffer();

        printf("   Nota 2: ");
        scanf("%f", &a->nota2);
        limparBuffer();

        a->media = calcularMedia(a->nota1, a->nota2);

        numAlunosCadastrados++;

        printf("\n   Aluno cadastrado com sucesso!\n");
        printf("   Média calculada: %.1f - %s\n\n", a->media, obterSituacao(a->media));

        printf("   Deseja cadastrar outro aluno?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarAlunos() {
    printf("|========================================|\n");
    printf("|             LISTAR ALUNOS              |\n");
    printf("|========================================|\n\n");

    if (!temAlunosCadastrados()) return;

    for (int i = 0; i < numAlunosCadastrados; i++) {
        imprimirAluno(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d aluno(s) cadastrado(s)\n", numAlunosCadastrados);
}

void buscarPorMatricula() {
    printf("|========================================|\n");
    printf("|            BUSCAR ALUNO                |\n");
    printf("|========================================|\n\n");

    if (!temAlunosCadastrados()) return;

    int matricula;
    printf("   Digite a matrícula: ");
    scanf("%d", &matricula);
    limparBuffer();

    for (int i = 0; i < numAlunosCadastrados; i++) {
        if (alunos[i].matricula == matricula) {
            printf("\n   Aluno encontrado:\n");
            imprimirAluno(i);
            return;
        }
    }

    printf("\n   Nenhum aluno com matrícula %d encontrado.\n", matricula);
}

void removerAluno() {
    printf("|========================================|\n");
    printf("|             REMOVER ALUNO              |\n");
    printf("|========================================|\n\n");

    if (!temAlunosCadastrados()) return;

    printf("   Alunos cadastrados:\n\n");

    for (int i = 0; i < numAlunosCadastrados; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s - Matrícula: %d\n", i + 1, alunos[i].nome, alunos[i].matricula);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual aluno deseja remover? (1-%d): ", numAlunosCadastrados);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numAlunosCadastrados) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numAlunosCadastrados);
        }
    } while (escolha < 1 || escolha > numAlunosCadastrados);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", alunos[indice].nome);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numAlunosCadastrados - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    numAlunosCadastrados--;
    printf("   Aluno removido com sucesso!\n");
}

float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2.0;
}

char* obterSituacao(float media) {
    if (media >= 7.0) return "Aprovado";
    if (media >= 5.0) return "Recuperação";
    return "Reprovado";
}

int temAlunosCadastrados() {
    if (numAlunosCadastrados == 0) {
        printf("   Nenhum aluno cadastrado!\n\n");
        return 0;
    }
    return 1;
}

void imprimirAluno(int indice) {
    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Aluno #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Nome:      %s\n", alunos[indice].nome);
    printf("   Matrícula: %d\n", alunos[indice].matricula);
    printf("   Nota 1:    %.1f\n", alunos[indice].nota1);
    printf("   Nota 2:    %.1f\n", alunos[indice].nota2);
    printf("   Média:     %.1f - %s\n", alunos[indice].media, obterSituacao(alunos[indice].media));
}
