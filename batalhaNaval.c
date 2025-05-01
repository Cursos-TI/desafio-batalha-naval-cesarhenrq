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

bool pode_posicionar_horizontal(int tabuleiro[10][10], int linha, int coluna, int tamanho)
{
    if (coluna + tamanho > 10)
        return false;

    for (int i = 0; i < tamanho; i++)
    {
        if (tabuleiro[linha][coluna + i] != 0)
            return false;
    }

    return true;
}

bool pode_posicionar_vertical(int tabuleiro[10][10], int linha, int coluna, int tamanho)
{
    if (linha + tamanho > 10)
        return false;

    for (int i = 0; i < tamanho; i++)
    {
        if (tabuleiro[linha + i][coluna] != 0)
            return false;
    }

    return true;
}

void posicionar_horizontal(int tabuleiro[10][10], int linha, int coluna, int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[linha][coluna + i] = valor;
    }
}

void posicionar_vertical(int tabuleiro[10][10], int linha, int coluna, int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[linha + i][coluna] = valor;
    }
}

void inicializar_tabuleiro(int tabuleiro[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibir_tabuleiro(int tabuleiro[10][10])
{
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void inicializar_habilidade_cone(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (i == 2 && j == 2)
            {
                habilidade[i][j] = 1;
            }
            else if (i == 3 && j > 0 && j < 4)
            {
                habilidade[i][j] = 1;
            }
            else if (i == 4 && j >= 0 && j <= 4)
            {
                habilidade[i][j] = 1;
            }
            else
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

void inicializar_habilidade_octaedro(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 0 || i == 4) && j == 2)
            {
                habilidade[i][j] = 1;
            }
            else if ((i == 1 || i == 3) && (j > 0 && j < 4))
            {   
                habilidade[i][j] = 1;
            }
            else if (i == 2)
            {
                habilidade[i][j] = 1;
            }
            else
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

void inicializar_habilidade_cruz(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 || j == 2)
            {
                habilidade[i][j] = 1;
            }
            else 
            {
                habilidade[i][j] = 0;
            }
        }
    }
}

void exibir_habilidade(int habilidade[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", habilidade[i][j]);
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
    int habilidade_cone[5][5];
    int habilidade_octaedro[5][5];
    int habilidade_cruz[5][5];

    // Inicializando o tabuleiro com água (0)
    inicializar_tabuleiro(tabuleiro);

    // Inicializando as habilidades
    inicializar_habilidade_cone(habilidade_cone);
    inicializar_habilidade_octaedro(habilidade_octaedro);
    inicializar_habilidade_cruz(habilidade_cruz);

    // Exibindo as habilidades
    printf("Habilidade Cone:\n");
    exibir_habilidade(habilidade_cone);
    
    printf("Habilidade octaedro:\n");
    exibir_habilidade(habilidade_octaedro);

    printf("Habilidade Cruz:\n");
    exibir_habilidade(habilidade_cruz);

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
