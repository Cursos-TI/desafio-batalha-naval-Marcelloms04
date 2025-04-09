#include <stdio.h>

#define TAMANHO 10
#define NAVIO_TAMANHO 3

// Começar o tabuleiro com água > 0
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verificar se o posicionamento do navio é válido 
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') { 
        if (coluna + NAVIO_TAMANHO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        }
    } 
    else if (direcao == 'V') { 
        if (linha + NAVIO_TAMANHO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    } 
    else if (direcao == 'D') { 
        if (linha + NAVIO_TAMANHO > TAMANHO || coluna + NAVIO_TAMANHO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) return 0;
        }
    } 
    else if (direcao == 'I') { 
        if (linha + NAVIO_TAMANHO > TAMANHO || coluna - NAVIO_TAMANHO < -1) return 0;
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) return 0;
        }
    }
    return 1; 
}

// Posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO_TAMANHO; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = 3; // Horizontal
        else if (direcao == 'V') tabuleiro[linha + i][coluna] = 3; // Vertical
        else if (direcao == 'D') tabuleiro[linha + i][coluna + i] = 3; // Diagonal 
        else if (direcao == 'I') tabuleiro[linha + i][coluna - i] = 3; // Diagonal contraria
    }
}

// Exibir o tabuleiro 
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definiçãode posições para os navios
    int posicoes[4][3] = {
        {1, 2, 'H'}, // Horizontal em B3 a B5
        {5, 7, 'V'}, // Vertical em F8 a H8
        {2, 2, 'D'}, // Diagonal em C3 a E5
        {6, 8, 'I'}  // Diagonal em G9 a I7
    };

    // Posiciona os navios no tabuleiro
    for (int i = 0; i < 4; i++) {
        int linha = posicoes[i][0];
        int coluna = posicoes[i][1];
        char direcao = (char)posicoes[i][2];


        if (podePosicionar(tabuleiro, linha, coluna, direcao)) {
            posicionarNavio(tabuleiro, linha, coluna, direcao);
        } else {
            printf("Erro ao posicionar navio %d!\n", i + 1);
        }
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
