#include <stdio.h>

// definindo constantes para facilitar a leitura e futuras alterações
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. represente o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // inicializando todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. posicione os navios
    // criando os vetores que representam os navios com o valor 3
    int navio1[TAMANHO_NAVIO] = {3, 3, 3};
    int navio2[TAMANHO_NAVIO] = {3, 3, 3};

    // preparando as variaveis para receberem entrada do usuario no futuro
    int linha_horiz, col_horiz;
    int linha_vert, col_vert;

    // definindo coordenadas para o navio horizontal
    // no proximo nivel, o scanf entrara aqui
    linha_horiz = 2;
    col_horiz = 4;

    // definindo coordenadas para o navio vertical
    // no proximo nivel, o scanf entrara aqui
    linha_vert = 5;
    col_vert = 8;

    // validando e posicionando o navio horizontal
    // verifica se o navio cabe no tabuleiro a partir da coluna inicial
    if (col_horiz + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // copiando o valor do vetor do navio para o tabuleiro
            tabuleiro[linha_horiz][col_horiz + i] = navio1[i];
        }
    }

    // validando e posicionando o navio vertical
    // verifica se o navio cabe no tabuleiro a partir da linha inicial
    // como escolhemos as posições manualmente, sabemos que não vão se sobrepor
    if (linha_vert + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // aqui a linha muda e a coluna fica fixa
            tabuleiro[linha_vert + i][col_vert] = navio2[i];
        }
    }

    // 3. exiba o tabuleiro
    printf("\ntabuleiro de batalha naval\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // imprimindo o valor com um espaco extra para ficar organizado
            printf("%d ", tabuleiro[i][j]);
        }
        // pula para a linha de baixo apos terminar as colunas da linha atual
        printf("\n");
    }

    printf("\n");
    return 0;
}
