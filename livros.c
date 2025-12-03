#include <stdio.h>
#include <string.h>

// constante do tamanho do acervo

#define TAMANHO_ACERVO 20

// Estrutura que representa um livro

struct livro
{
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

// Protótipos das funções
// Cada função recebe o vetor de livro (acervo) e o tamanho do vetor.

void cadastrarLivros (struct livro acervo[], int tamanho);
void imprimirLivros(struct livro acervo[], int tamanho);
void pesquisarLivros(struct livro acervo[], int tamanho);
void ordenarLivros(struct livro acervo[], int tamanho);

// MENU PRINCIPAL

int main(){
    struct livro acervo[TAMANHO_ACERVO]; // vetor de structs (acervo)
    int op;
    int i;

    // Inicia o acervo como "vazio" (codigo = 0 significa posição livre)
    for ( i = 0; i < TAMANHO_ACERVO; i++)
    {
        acervo[i].codigo = 0;
    }

    do{
        printf("\n ***********************************");
        printf("SISTEMA DE GERENCIAMENTO DE LIVROS\n");
        printf("\n ***********************************");     
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros \n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        fflush(stdin); // usado conforme orientação

    switch (op)
        {
            case 1:
                cadastrarLivros(acervo, TAMANHO_ACERVO);
                break;
            case 2:
                imprimirLivros(acervo, TAMANHO_ACERVO);
                break;

            case 3:
                pesquisarLivros(acervo, TAMANHO_ACERVO);
                break;
                
            case 4:
                ordenarLivros(acervo, TAMANHO_ACERVO);
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.");
        }
    while (op != 5)
    {
        return(0);
    }
    
    
}