#include <stdio.h>

int main() {
    // 1. represente o tabuleiro
    int tabuleiro[10][10];

    // vetor de caracteres para as colunas de A ate J
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // inicializando todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. posicione os navios
    int linha_horiz = 2, col_horiz = 4;
    int linha_vert = 5, col_vert = 8;
    int linha_diag1 = 0, col_diag1 = 0;
    int linha_diag2 = 7, col_diag2 = 2;

    int pode_posicionar; // variavel para guardar o resultado da validação

    // posicionando o navio horizontal (tamanho 3)
    pode_posicionar = 1;
    if (col_horiz + 3 > 10) {
        pode_posicionar = 0; //fora dos limites
    } else {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_horiz][col_horiz + i] != 0) pode_posicionar = 0; // sobreposicao
        }
    }
    if (pode_posicionar == 1) {
        for (int i = 0; i <3; i++) {
            tabuleiro[linha_horiz][col_horiz + i] = 3;
        }
    }

    //navio verticaL
    pode_posicionar = 1;
    if (linha_vert + 3 > 10) {
        pode_posicionar = 0;
    } else {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_vert + i][col_vert] != 0) pode_posicionar = 0;
        }
    }
    if (pode_posicionar == 1) {
        for (int i = 0; i <3; i++) {
            tabuleiro[linha_vert + i][col_vert] = 3;
        }
    }
    //posicione o primeiro navio diagonal (linha aumenta, coluna aumenta
    pode_posicionar = 1;
    if (linha_diag1 + 3 > 10 || col_diag1 + 3 > 10) {
        pode_posicionar = 0;
    } else {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_diag1 + i][col_diag1 + i] != 0) pode_posicionar = 0;
        }
    }
    if (pode_posicionar == 1) {
        for (int i = 0; i <3; i++) {
            tabuleiro[linha_diag1 + i][col_diag1 + i] = 3;
        }
    }
    //pocisionar o segundo navio diagonal (linha aumenta, coluna diminui
    pode_posicionar = 1;
    //verifica se a linha passa de 9 e se a coluna fica menor que 0
    if (linha_diag2 + 3 > 10 || col_diag2 - 2 < 0) {
        pode_posicionar = 0;
    } else {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_diag2 + i][col_diag2 - i] != 0) pode_posicionar = 0;
        }
    }
    if (pode_posicionar == 1) {
        for (int i = 0; i <3; i++) {
            tabuleiro[linha_diag2 + i][col_diag2 - i] = 3;
        }
    }

    //exibir o tabuleiro
    printf("\ntabuleiro de batalha naval (nivel aventureiro)\n\n");

    //imprimir o titulo das colunas (letras de A ate J)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");

    //imprimir as linhas (numero de conteudo da matriz)
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);

        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
return 0;

}
