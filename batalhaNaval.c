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

    // posicionando o navio horizontal (tamanho 3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_horiz][col_horiz + i] = 3;
    }

    // posicionando o navio vertical (tamanho 3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_vert + i][col_vert] = 3;
    }

    // 3. exiba o tabuleiro
    printf("\ntabuleiro de batalha naval\n\n");

    // imprimindo o titulo das colunas (letras de A ate J)
    printf("   "); // espacos para alinhar com a numeração lateral
    for (int j = 0; j < 10; j++) {
        printf("%c ", colunas[j]);
    }
    printf("\n");

    // imprimindo as linhas (numero + conteudo da matriz)
    for (int i = 0; i < 10; i++) {
        // o %2d garante que o numero 10 nao empurre a matriz para o lado
        printf("%2d ", i + 1); 
        
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
