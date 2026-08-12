// Multiply special-pattern square matrices using D&C approach: 
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

void specialMultiply(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int **A1 = malloc(k * sizeof(int *));
    int **A2 = malloc(k * sizeof(int *));
    int **B1 = malloc(k * sizeof(int *));
    int **B2 = malloc(k * sizeof(int *));

    int **X = malloc(k * sizeof(int *));
    int **Y = malloc(k * sizeof(int *));
    int **P = malloc(k * sizeof(int *));
    int **Q = malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++) {
        A1[i] = malloc(k * sizeof(int));
        A2[i] = malloc(k * sizeof(int));
        B1[i] = malloc(k * sizeof(int));
        B2[i] = malloc(k * sizeof(int));

        X[i] = malloc(k * sizeof(int));
        Y[i] = malloc(k * sizeof(int));
        P[i] = malloc(k * sizeof(int));
        Q[i] = malloc(k * sizeof(int));
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    addMatrix(k, A1, A2, X);
    addMatrix(k, B1, B2, Y);

    specialMultiply(k, X, Y, P);

    subtractMatrix(k, A1, A2, X);
    subtractMatrix(k, B1, B2, Y);

    specialMultiply(k, X, Y, Q);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            int C1 = (P[i][j] + Q[i][j]) / 2;
            int C2 = (P[i][j] - Q[i][j]) / 2;

            C[i][j] = C1;
            C[i][j + k] = C2;
            C[i + k][j] = C2;
            C[i + k][j + k] = C1;
        }
    }

    for (int i = 0; i < k; i++) {
        free(A1[i]);
        free(A2[i]);
        free(B1[i]);
        free(B2[i]);

        free(X[i]);
        free(Y[i]);
        free(P[i]);
        free(Q[i]);
    }

    free(A1);
    free(A2);
    free(B1);
    free(B2);

    free(X);
    free(Y);
    free(P);
    free(Q);
}

int **createSpecialMatrix(int n) {
    int **A = malloc(n * sizeof(int *));

    int half = n / 2;

    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            int x = i % half;
            int y = j % half;

            A[i][j] = (x + y) % 10 + 1;
        }
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
    printf("\n----------------------------------------------------------------\n");
    printf("| Multiply special-pattern square matrices using D&C approach: |");
    printf("\n----------------------------------------------------------------\n");

    printf("\nSize\tTime\n");

    for (int n = 64; n <= 2048; n *= 2) {

        int **A = createSpecialMatrix(n);
        int **B = createSpecialMatrix(n);
        int **C = createSpecialMatrix(n);

        clock_t start = clock();

        specialMultiply(n, A, B, C);

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
