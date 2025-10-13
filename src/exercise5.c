#include <stdio.h>

#define ROWS_A 10
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 10

int main() {
    float matrixA[ROWS_A][COLS_A];
    float matrixB[ROWS_B][COLS_B];
    float result[ROWS_A][COLS_B];
    
    printf("Введите элементы матрицы A (10x3):\n");
    for (int i = 0; i < ROWS_A; i++) {
        printf("Строка %d: ", i);
        for (int j = 0; j < COLS_A; j++) {
            scanf("%f", &matrixA[i][j]);
        }
    }
    
    printf("\nВведите элементы матрицы B (3x10):\n");
    for (int i = 0; i < ROWS_B; i++) {
        printf("Строка %d: ", i);
        for (int j = 0; j < COLS_B; j++) {
            scanf("%f", &matrixB[i][j]);
        }
    }
    
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    printf("\nРезультат умножения (матрица 10x10):\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%8.2f", result[i][j]);
        }
        printf("\n");
    }
    
    printf("\nРезультат одной строкой по строкам:\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%.2f ", result[i][j]);
        }
    }
    printf("\n");
    
    return 0;
}