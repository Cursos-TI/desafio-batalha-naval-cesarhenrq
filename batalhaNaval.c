#include <stdio.h>
#include <stdbool.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

bool pode_posicionar_diagonal(int tabuleiro[10][10], int linha, int coluna, int tamanho)
{
    bool passa_do_limite = (linha + tamanho > 10 || coluna + tamanho > 10);
    if (passa_do_limite)
        return false;

    for (int i = 0; i < tamanho; i++)
    {
        bool tem_navio = (tabuleiro[linha + i][coluna + i] != 0);
        if (tem_navio)
            return false;
    }

    return true;
}

void posicionar_navio_diagonal(int tabuleiro[10][10], int linha, int coluna, int tamanho, int valor)
{

    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[linha + i][coluna + i] = valor;
    }
}

bool pode_posicionar_horizontal(int tabuleiro[10][10], int linha, int coluna, int tamanho) {
    if (coluna + tamanho > 10) return false;

    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return false;
    }

    return true;
}

bool pode_posicionar_vertical(int tabuleiro[10][10], int linha, int coluna, int tamanho) {
    if (linha + tamanho > 10) return false;

    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return false;
    }

    return true;
}

void posicionar_horizontal(int tabuleiro[10][10], int linha, int coluna, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha][coluna + i] = valor;
    }
}

void posicionar_vertical(int tabuleiro[10][10], int linha, int coluna, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[linha + i][coluna] = valor;
    }
}

void inicializar_tabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibir_tabuleiro(int tabuleiro[10][10]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro[10][10];
    int tamanho_navio = 3;
    int valor_navio = 3;

    // Inicializando o tabuleiro com água (0)
    inicializar_tabuleiro(tabuleiro);

    // Posicionar navio 1 na posição (0, 0) horizontal
    if (pode_posicionar_horizontal(tabuleiro, 0, 0, tamanho_navio))
    {
        printf("Posicionando navio 1 na posição (0, 0) horizontal.\n");
        posicionar_horizontal(tabuleiro, 0, 0, tamanho_navio, valor_navio);
    }
    else
    {
        printf("Não é possível posicionar o navio 1 na posição (0, 0) horizontal.\n");
    }

    // Posicionar navio 2 na posição (1, 1) vertical
    if (pode_posicionar_vertical(tabuleiro, 1, 1, tamanho_navio))
    {
        printf("Posicionando navio 2 na posição (1, 1) vertical.\n");
        posicionar_vertical(tabuleiro, 1, 1, tamanho_navio, valor_navio);
    }
    else
    {
        printf("Não é possível posicionar o navio 2 na posição (1, 1) vertical.\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Posicionar navio 3 na posição (2, 2) diagonal
    if (pode_posicionar_diagonal(tabuleiro, 2, 2, tamanho_navio))
    {
        printf("Posicionando navio 3 na posição (2, 2) diagonal.\n");
        posicionar_navio_diagonal(tabuleiro, 2, 2, tamanho_navio, valor_navio);
    }
    else
    {
        printf("Não é possível posicionar o navio 3 na posição (2, 2) diagonal.\n");
    }
    

    // Posicionar navio 4 na posição (5, 5) diagonal
    if (pode_posicionar_diagonal(tabuleiro, 5, 5, tamanho_navio))
    {
        printf("Posicionando navio 4 na posição (5, 5) diagonal.\n");
        posicionar_navio_diagonal(tabuleiro, 5, 5, tamanho_navio, valor_navio);
    }
    else
    {
        printf("Não é possível posicionar o navio 4 na posição (5, 5) diagonal.\n");
    }
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Exibindo o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}
