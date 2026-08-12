// Matrix Multiplication using D&C Approach:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addMatrix(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int **A11 = malloc(k * sizeof(int *));
    int **A12 = malloc(k * sizeof(int *));
    int **A21 = malloc(k * sizeof(int *));
    int **A22 = malloc(k * sizeof(int *));

    int **B11 = malloc(k * sizeof(int *));
    int **B12 = malloc(k * sizeof(int *));
    int **B21 = malloc(k * sizeof(int *));
    int **B22 = malloc(k * sizeof(int *));

    int **M1 = malloc(k * sizeof(int *));
    int **M2 = malloc(k * sizeof(int *));
    int **M3 = malloc(k * sizeof(int *));
    int **M4 = malloc(k * sizeof(int *));
    int **M5 = malloc(k * sizeof(int *));
    int **M6 = malloc(k * sizeof(int *));
    int **M7 = malloc(k * sizeof(int *));

    int **X = malloc(k * sizeof(int *));
    int **Y = malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++) {
        A11[i] = malloc(k * sizeof(int));
        A12[i] = malloc(k * sizeof(int));
        A21[i] = malloc(k * sizeof(int));
        A22[i] = malloc(k * sizeof(int));

        B11[i] = malloc(k * sizeof(int));
        B12[i] = malloc(k * sizeof(int));
        B21[i] = malloc(k * sizeof(int));
        B22[i] = malloc(k * sizeof(int));

        M1[i] = malloc(k * sizeof(int));
        M2[i] = malloc(k * sizeof(int));
        M3[i] = malloc(k * sizeof(int));
        M4[i] = malloc(k * sizeof(int));
        M5[i] = malloc(k * sizeof(int));
        M6[i] = malloc(k * sizeof(int));
        M7[i] = malloc(k * sizeof(int));

        X[i] = malloc(k * sizeof(int));
        Y[i] = malloc(k * sizeof(int));
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    addMatrix(k, A11, A22, X);
    addMatrix(k, B11, B22, Y);
    strassen(k, X, Y, M1);

    addMatrix(k, A21, A22, X);
    strassen(k, X, B11, M2);

    subtractMatrix(k, B12, B22, Y);
    strassen(k, A11, Y, M3);

    subtractMatrix(k, B21, B11, Y);
    strassen(k, A22, Y, M4);

    addMatrix(k, A11, A12, X);
    strassen(k, X, B22, M5);

    subtractMatrix(k, A21, A11, X);
    addMatrix(k, B11, B12, Y);
    strassen(k, X, Y, M6);

    subtractMatrix(k, A12, A22, X);
    addMatrix(k, B21, B22, Y);
    strassen(k, X, Y, M7);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] =
                M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

            C[i][j + k] =
                M3[i][j] + M5[i][j];

            C[i + k][j] =
                M2[i][j] + M4[i][j];

            C[i + k][j + k] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        free(A11[i]);
        free(A12[i]);
        free(A21[i]);
        free(A22[i]);

        free(B11[i]);
        free(B12[i]);
        free(B21[i]);
        free(B22[i]);

        free(M1[i]);
        free(M2[i]);
        free(M3[i]);
        free(M4[i]);
        free(M5[i]);
        free(M6[i]);
        free(M7[i]);

        free(X[i]);
        free(Y[i]);
    }

    free(A11);
    free(A12);
    free(A21);
    free(A22);

    free(B11);
    free(B12);
    free(B21);
    free(B22);

    free(M1);
    free(M2);
    free(M3);
    free(M4);
    free(M5);
    free(M6);
    free(M7);

    free(X);
    free(Y);
}

int **createMatrix(int n) {
    int **A = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            A[i][j] = rand() % 10;
    }

    return A;
}

void freeMatrix(int **A, int n) {
    for (int i = 0; i < n; i++)
        free(A[i]);

    free(A);
}

int main() {
    srand(time(NULL));
    printf("\n-----------------------------------------------\n");
    printf("|  Matrix Multiplication using D&C Approach:  |");
    printf("\n-----------------------------------------------\n");

    printf("\nSize\tTime\n");

    for (int n = 64; n <= 1024; n *= 2) {
        int **A = createMatrix(n);
        int **B = createMatrix(n);
        int **C = createMatrix(n);

        clock_t start = clock();

        strassen(n, A, B, C);

        clock_t end = clock();

        double time =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\n", n, time);

        freeMatrix(A, n);
        freeMatrix(B, n);
        freeMatrix(C, n);
    }

    return 0;
}
