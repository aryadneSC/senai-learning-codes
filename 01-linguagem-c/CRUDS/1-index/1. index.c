#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int lerOpcaoValida();
void limparBuffer();
void menu();
void biblioteca();
void contatos();
void alunos();
void produtos();
void usuarios();
void playlist();
void veiculos();
void receitas();
void filmes();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int op;

    do {
        menu();
        printf("\n   Escolha: ");
        op = lerOpcaoValida();

        printf("\n");

    switch(op) {
        case 1:
            system("cls");
            biblioteca();
            break;
        case 2:
            system("cls");
            contatos();
            break;
        case 3:
            system("cls");
            alunos();
            break;
        case 4:
            system("cls");
            produtos();
            break;
        case 5:
            system("cls");
            usuarios();
            break;
        case 6:
            system("cls");
            playlist();
            break;
        case 7:
            system("cls");
            veiculos();
            break;
        case 8:
            system("cls");
            receitas();
            break;
        case 9:
            system("cls");
            filmes();
            break;
        case 0:
            printf("    Até logo!\n\n");
            printf("|========================================|\n");
            break;
        default:
            printf("    Opção inválida! Tente novamente!\n\n");
        }

        if(op != 0)
            printf("|===========================================|\n");
            system("pause");
            system("cls");

    } while(op != 0);

    return 0;
}

void filmes() {

    printf("\n|===========================================|\n");
    printf("|                   FILMES                  |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void receitas() {

    printf("\n|===========================================|\n");
    printf("|                  RECEITAS                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void veiculos() {

    printf("\n|===========================================|\n");
    printf("|                  VEICULOS                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void playlist() {

    printf("\n|===========================================|\n");
    printf("|                  PLAYLIST                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void usuarios() {

    printf("\n|===========================================|\n");
    printf("|                  USUARIOS                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void produtos() {

    printf("\n|===========================================|\n");
    printf("|                  PRODUTOS                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void alunos() {

    printf("\n|===========================================|\n");
    printf("|                   ALUNOS                  |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void contatos() {

    printf("\n|===========================================|\n");
    printf("|                  CONTATOS                 |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void biblioteca() {

    printf("\n|===========================================|\n");
    printf("|                 BIBLIOTECA                |\n");
    printf("|===========================================|\n\n");
    printf("   Em construção...\n");
}

void menu() {

    printf("|========================================|\n");
    printf("|              INDEX CRUDS               |\n");
    printf("|========================================|\n\n");
    printf("   [1] Biblioteca\n");
    printf("   [2] Contatos\n");
    printf("   [3] Alunos\n");
    printf("   [4] Produtos\n");
    printf("   [5] Usuários\n");
    printf("   [6] Playlist\n");
    printf("   [7] Veículos\n");
    printf("   [8] Receitas\n");
    printf("   [9] Filmes\n");
    printf("   [0] Sair\n\n");
}

void limparBuffer() {

    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

int lerOpcaoValida() {

     int op;
     int leitura;

     do {

     leitura = scanf("%d", &op);
     limparBuffer();

     if(leitura == 0) {

        printf("\n   Entrada inválida! Digite um número: ");
     }

     } while(leitura == 0);

     return op;
 }
/*
Conceitos: switch, loops, modularização
Estrutura:
- Menu com lista de CRUDs disponíveis
- Navegação entre projetos
- Sistema de "voltar ao menu"
*/
