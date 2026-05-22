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

    //parte nível mestre

  int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // construção das matrizes de área de efeito utilizando condicionais
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            // Lógica do Cone (Exata forma do exemplo do professor)
            if (i < 3 && j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }

            // Lógica da Cruz
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }

            // Lógica do Octaedro (Losango)
            int dist_i = i - 2;
            if (dist_i < 0) dist_i = -dist_i;

            int dist_j = j - 2;
            if (dist_j < 0) dist_j = -dist_j;

            if (dist_i + dist_j <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // definindo pontos de origem SEGUROS (longe o suficiente das bordas para não cortar as matrizes 5x5)
    int origem_cone_l = 7, origem_cone_c = 2;
    int origem_cruz_l = 2, origem_cruz_c = 3;
    int origem_octaedro_l = 5, origem_octaedro_c = 7;

    // sobrepondo o cone (usa o número 1)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int l = origem_cone_l + (i - 2);
                int c = origem_cone_c + (j - 2);

                // condiciinal exigida: garante que só desenha se estiver dentro dos limites do tabuleiro
                if (l >= 0 && l < 10 && c >= 0 && c < 10) {
                    tabuleiro[l][c] = 1;
                }
            }
        }
    }

    // cruz (usa o número 3)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int l = origem_cruz_l + (i - 2);
                int c = origem_cruz_c + (j - 2);

                if (l >= 0 && l < 10 && c >= 0 && c < 10) {
                    tabuleiro[l][c] = 3;
                }
            }
        }
    }

    // octaedro (usa o número 2)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int l = origem_octaedro_l + (i - 2);
                int c = origem_octaedro_c + (j - 2);

                if (l >= 0 && l < 10 && c >= 0 && c < 10) {
                    tabuleiro[l][c] = 2;
                }
            }
        }
    }

    // exibir o tabuliro atualizado
    printf("\nTabuleiro de Batalha Naval (Nivel Mestre)\n\n");

    // título das colunas
    printf("    ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", colunas[j]);
    }
    printf("\n");

    // linhas e matriz
    for (int i = 0; i < 10; i++) {
        printf(" %2d ", i + 1);

        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

//considerações finais: graças a deusa existe o for porque eu teria demorado mais 3 horas pra escrever linha por linha do tabuleirokkkk
