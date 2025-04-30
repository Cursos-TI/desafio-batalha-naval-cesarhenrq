#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro[10][10];
    int navio_1[3] = { 3, 3, 3};
    int navio_2[3] = { 3, 3, 3};
    int navio_3[3] = { 3, 3, 3};
    int navio_4[3] = { 3, 3, 3};

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posicionar navio_1 na posição (0, 0) horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[0][i] = navio_1[i];
    }

    // Posicionar navio_2 na posição (1, 1) vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 1][1] = navio_2[i];
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Posicionar navio_3 na posição (2, 2) diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 2][i + 2] = navio_3[i];
    }

    // Posicionar navio_4 na posição (5, 5) diagonal
    for (int i = 0; i < 3; i++) {
        tabuleiro[i + 5][i + 5] = navio_4[i];
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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
