// Use of loop invariants in sorting:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min])
                min = j;
        }

        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main() {
    srand(time(NULL));
    printf("\n-----------------------------------------------\n");
    printf("|      Use of loop invariants in sorting:     |");
    printf("\n-----------------------------------------------\n");

    printf("\n\nSize\t\tTime\n\n");

    for (int n = 5000; n <= 50000; n += 5000) {

        int *A = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            A[i] = rand();

        clock_t start = clock();

        selectionSort(A, n);

        clock_t end = clock();

        printf("%d\t\t%.6f\n", n,
               (double)(end - start) / CLOCKS_PER_SEC);

        free(A);
    }

    return 0;
}
