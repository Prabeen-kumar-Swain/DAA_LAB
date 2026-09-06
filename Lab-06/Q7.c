#include <stdio.h>

int main() {
    int A[100], B[100], C[200];
    int m, n, i, j;

    printf("Enter size of A: ");
    scanf("%d", &m);

    printf("Enter size of B: ");
    scanf("%d", &n);

    printf("Enter A:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("Enter B:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &B[i]);

    for (i = 0; i < m + n - 1; i++)
        C[i] = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i + j] += A[i] * B[j];
        }
    }

    printf("Convolution:\n");

    for (i = 0; i < m + n - 1; i++)
        printf("%d ", C[i]);

    return 0;
}
