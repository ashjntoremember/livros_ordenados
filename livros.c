#include <stdio.h>
#include <string.h>   // para strcmp

// Constante do tamanho do acervo
#define TAMANHO_ACERVO 20

// Estrutura que representa um livro
struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Protótipos das funções
void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

int main() {
    struct Livro acervo[TAMANHO_ACERVO];  // vetor de structs (acervo)
    int opcao;
    int i;
    int codigoBusca;

    // Inicializa o acervo como "vazio" (codigo = 0 significa posição livre)
    for (i = 0; i < TAMANHO_ACERVO; i++) {
        acervo[i].codigo = 0;
    }

    do {
        printf("\n=================================\n");
        printf("   SISTEMA DE GERENCIAMENTO DE LIVROS\n");
        printf("==================================\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin); // usado conforme orientação do enunciado

        switch (opcao) {
        case 1:
            cadastrarLivros(acervo, TAMANHO_ACERVO);
            break;
        case 2:
            imprimirLivros(acervo, TAMANHO_ACERVO);
            break;
        case 3:
            printf("\n=== PESQUISA DE LIVRO POR CODIGO ===\n");
            printf("Digite o codigo do livro: ");
            scanf("%d", &codigoBusca);
            fflush(stdin);
            pesquisarLivro(acervo, TAMANHO_ACERVO, codigoBusca);
            break;
        case 4:
            ordenarLivros(acervo, TAMANHO_ACERVO);
            printf("\nLivros ordenados por ano com sucesso!\n");
            break;
        case 5:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}

// Funcao: cadastrarLivros
// Objetivo: ler os dados dos livros e armazenar no vetor acervo

void cadastrarLivros(struct Livro acervo[], int tamanho) {
    int i;

    printf("\n=== CADASTRO DE LIVROS ===\n");
    printf("Digite os dados dos livros. Para encerrar antes, use codigo 0.\n");

    for (i = 0; i < tamanho; i++) {
        printf("\nLivro %d de %d\n", i + 1, tamanho);

        printf("Codigo (inteiro, 0 encerra o cadastro): ");
        scanf("%d", &acervo[i].codigo);
        fflush(stdin);

        // Se usuario digitar 0, para de cadastrar antes de chegar a 20
        if (acervo[i].codigo == 0) {
            printf("Cadastro encerrado antecipadamente.\n");
            break;
        }

        printf("Titulo: ");
        scanf(" %49[^\n]", acervo[i].titulo);
        fflush(stdin);

        printf("Autor: ");
        scanf(" %29[^\n]", acervo[i].autor);
        fflush(stdin);

        printf("Area: ");
        scanf(" %29[^\n]", acervo[i].area);
        fflush(stdin);

        printf("Ano de publicacao: ");
        scanf("%d", &acervo[i].ano);
        fflush(stdin);

        printf("Editora: ");
        scanf(" %29[^\n]", acervo[i].editora);
        fflush(stdin);
    }

    // Se parou antes do tamanho, zera o resto para manter consistência
    for (; i < tamanho; i++) {
        acervo[i].codigo = 0;
    }
}

// Funcao: imprimirLivros
// Objetivo: mostrar todos os livros cadastrados na tela

void imprimirLivros(struct Livro acervo[], int tamanho) {
    int i;
    int encontrou = 0;

    printf("\n=== LISTA DE LIVROS CADASTRADOS ===\n");

    for (i = 0; i < tamanho; i++) {
        if (acervo[i].codigo != 0) {
            encontrou = 1;
            printf("\nLivro %d:\n", i + 1);
            printf("Codigo : %d\n", acervo[i].codigo);
            printf("Titulo : %s\n", acervo[i].titulo);
            printf("Autor  : %s\n", acervo[i].autor);
            printf("Area   : %s\n", acervo[i].area);
            printf("Ano    : %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
        }
    }

    if (!encontrou) {
        printf("\nNenhum livro cadastrado.\n");
    }
}

// Funcao: pesquisarLivro
// Objetivo: pesquisar um livro pelo codigo e exibir seus dados

void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
    int i = 0;
    int encontrado = 0;

    // Percorre o vetor com while
    while (i < tamanho && !encontrado) {
        if (acervo[i].codigo == codigoBusca) {
            encontrado = 1;
        } else {
            i++;
        }
    }

    if (encontrado) {
        printf("\nLivro encontrado:\n");
        printf("Codigo : %d\n", acervo[i].codigo);
        printf("Titulo : %s\n", acervo[i].titulo);
        printf("Autor  : %s\n", acervo[i].autor);
        printf("Area   : %s\n", acervo[i].area);
        printf("Ano    : %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    } else {
        printf("\nLivro com codigo %d nao encontrado.\n", codigoBusca);
    }
}

// Funcao: ordenarLivros
// Objetivo: ordenar os livros por ano de publicacao (Bubble Sort)
//           Em caso de mesmo ano, ordena por titulo (strcmp)

void ordenarLivros(struct Livro acervo[], int tamanho) {
    int i, j;
    int qtdCadastrados = 0;
    struct Livro temp;

    // Conta quantos livros foram cadastrados (codigo != 0)
    for (i = 0; i < tamanho; i++) {
        if (acervo[i].codigo != 0) {
            qtdCadastrados++;
        } else {
            // assumindo que apos o primeiro 0 nao existem mais livros cadastrados
            break;
        }
    }

    // Bubble Sort por ano (e titulo como desempate)
    for (i = 0; i < qtdCadastrados - 1; i++) {
        for (j = 0; j < qtdCadastrados - 1 - i; j++) {
            int troca = 0;

            // Primeiro compara o ano
            if (acervo[j].ano > acervo[j + 1].ano) {
                troca = 1;
            }
            // Se o ano for igual, ordena por titulo (strcmp)
            else if (acervo[j].ano == acervo[j + 1].ano) {
                if (strcmp(acervo[j].titulo, acervo[j + 1].titulo) > 0) {
                    troca = 1;
                }
            }

            if (troca) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
}
