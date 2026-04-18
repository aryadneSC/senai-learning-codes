#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_MUSICAS 100

enum Genero {
    POP,
    ROCK,
    JAZZ,
    CLASSICO,
    OUTROS
};

typedef struct {
    char titulo[100];
    char artista[100];
    int duracaoSegundos;
    enum Genero genero;
} Musica;

Musica playlist[MAX_MUSICAS];
int numMusicasCadastradas = 0;

void limparBuffer();
void menu();
int validarOpcao();
void adicionarMusica();
void listarMusicas();
void filtrarPorGenero();
void removerMusica();
char* obterTextoGenero(enum Genero g);
void exibirMenuGenero();
int lerGenero();
int temMusicasCadastradas();
void imprimirMusica(int indice);
void formatarDuracao(int segundos, int *min, int *seg);

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
            adicionarMusica();
            break;
        case 2:
            system("cls");
            listarMusicas();
            break;
        case 3:
            system("cls");
            filtrarPorGenero();
            break;
        case 4:
            system("cls");
            removerMusica();
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
    printf("|           SISTEMA - PLAYLIST           |\n");
    printf("|========================================|\n\n");
    printf("   [1] Adicionar Música\n");
    printf("   [2] Listar Playlist\n");
    printf("   [3] Filtrar por Gênero\n");
    printf("   [4] Remover Música\n");
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

void adicionarMusica() {
    printf("|========================================|\n");
    printf("|          ADICIONAR NOVA MUSICA         |\n");
    printf("|========================================|\n\n");

    int continuar;

    do {
        if (numMusicasCadastradas >= MAX_MUSICAS) {
            printf("   Limite da playlist atingido!\n");
            break;
        }

        Musica *m = &playlist[numMusicasCadastradas];

        printf("   Título: ");
        fgets(m->titulo, 100, stdin);
        m->titulo[strcspn(m->titulo, "\n")] = '\0';

        printf("   Artista: ");
        fgets(m->artista, 100, stdin);
        m->artista[strcspn(m->artista, "\n")] = '\0';

        printf("   Duração (em segundos): ");
        scanf("%d", &m->duracaoSegundos);
        limparBuffer();

        exibirMenuGenero();
        m->genero = lerGenero();

        numMusicasCadastradas++;

        printf("\n   Música adicionada com sucesso!\n\n");

        printf("   Deseja adicionar outra música?\n");
        printf("   [1] Sim\n");
        printf("   [0] Não\n");
        printf("   Escolha: ");
        continuar = validarOpcao();

        system("cls");
        printf("|========================================|\n\n");

    } while (continuar == 1);
}

void listarMusicas() {
    printf("|========================================|\n");
    printf("|             LISTAR PLAYLIST            |\n");
    printf("|========================================|\n\n");

    if (!temMusicasCadastradas()) return;

    for (int i = 0; i < numMusicasCadastradas; i++) {
        imprimirMusica(i);
    }

    printf("   ----------------------------------|\n");
    printf("   Total: %d música(s) na playlist\n", numMusicasCadastradas);
}

void filtrarPorGenero() {
    printf("|========================================|\n");
    printf("|           FILTRAR POR GENERO           |\n");
    printf("|========================================|\n\n");

    if (!temMusicasCadastradas()) return;

    exibirMenuGenero();
    int gen = lerGenero();

    int encontrados = 0;

    for (int i = 0; i < numMusicasCadastradas; i++) {
        if (playlist[i].genero == gen) {
            if (encontrados == 0)
                printf("   Músicas em [%s]:\n", obterTextoGenero(gen));
            imprimirMusica(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("   Nenhuma música no gênero [%s].\n\n", obterTextoGenero(gen));
    } else {
        printf("\n   --------------------------------------|\\n");
        printf("   Total: %d música(s) encontrada(s)\n", encontrados);
    }
}

void removerMusica() {
    printf("|========================================|\n");
    printf("|            REMOVER MUSICA              |\n");
    printf("|========================================|\n\n");

    if (!temMusicasCadastradas()) return;

    printf("   Músicas na playlist:\n\n");

    for (int i = 0; i < numMusicasCadastradas; i++) {
        printf("   ----------------------------------|\\n");
        printf("   [%d] %s - %s\n", i + 1, playlist[i].titulo, playlist[i].artista);
    }

    printf("   ----------------------------------|\\n");
    printf("   Qual música deseja remover? (1-%d): ", numMusicasCadastradas);

    int escolha;
    do {
        escolha = validarOpcao();
        if (escolha < 1 || escolha > numMusicasCadastradas) {
            printf("   Opção inválida! Digite entre 1 e %d: ", numMusicasCadastradas);
        }
    } while (escolha < 1 || escolha > numMusicasCadastradas);

    int indice = escolha - 1;

    printf("   Tem certeza que deseja remover '%s'?\n", playlist[indice].titulo);
    printf("   [1] Sim\n");
    printf("   [2] Não\n");
    printf("   Escolha: ");

    int confirma = validarOpcao();

    if (confirma != 1) {
        printf("   Remoção cancelada!\n");
        return;
    }

    for (int i = indice; i < numMusicasCadastradas - 1; i++) {
        playlist[i] = playlist[i + 1];
    }

    numMusicasCadastradas--;
    printf("   Música removida com sucesso!\n");
}

char* obterTextoGenero(enum Genero g) {
    switch (g) {
        case POP:      return "Pop";
        case ROCK:     return "Rock";
        case JAZZ:     return "Jazz";
        case CLASSICO: return "Clássico";
        case OUTROS:   return "Outros";
        default:       return "Desconhecido";
    }
}

void exibirMenuGenero() {
    printf("\n   Gênero:\n");
    printf("   [0] Pop\n");
    printf("   [1] Rock\n");
    printf("   [2] Jazz\n");
    printf("   [3] Clássico\n");
    printf("   [4] Outros\n");
    printf("   Escolha: ");
}

int lerGenero() {
    int g;
    do {
        g = validarOpcao();
        if (g < 0 || g > 4) {
            printf("   Gênero inválido! Digite entre 0 e 4: ");
        }
    } while (g < 0 || g > 4);
    return g;
}

void formatarDuracao(int segundos, int *min, int *seg) {
    *min = segundos / 60;
    *seg = segundos % 60;
}

int temMusicasCadastradas() {
    if (numMusicasCadastradas == 0) {
        printf("   Nenhuma música na playlist!\n\n");
        return 0;
    }
    return 1;
}

void imprimirMusica(int indice) {
    int min, seg;
    formatarDuracao(playlist[indice].duracaoSegundos, &min, &seg);

    printf("\n");
    printf("   --------------------------------------\n");
    printf("   Faixa #%d\n", indice + 1);
    printf("   --------------------------------------\n");
    printf("   Título:   %s\n", playlist[indice].titulo);
    printf("   Artista:  %s\n", playlist[indice].artista);
    printf("   Duração:  %d:%02d\n", min, seg);
    printf("   Gênero:   %s\n", obterTextoGenero(playlist[indice].genero));
}
