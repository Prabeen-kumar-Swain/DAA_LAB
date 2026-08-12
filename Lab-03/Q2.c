// Search the Defective Coin:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findDefective(int a[], int l, int r) {
    if (l == r)
        return a[l] < 100 ? l : -1;

    int mid = (l + r) / 2;

    int left = 0;
    int right = 0;

    for (int i = l; i <= mid; i++)
        left += a[i];

    for (int i = mid + 1; i <= r; i++)
        right += a[i];

    if (left < right)
        return findDefective(a, l, mid);

    if (right < left)
        return findDefective(a, mid + 1, r);

    return -1;
}

int main() {
    srand(time(NULL));
    printf("\n-----------------------------------------------\n");
    printf("|          Search the Defective Coin:          |");
    printf("\n-----------------------------------------------\n");

    printf("\nSize\t\tTime\n");

    for (int n = 1024; n <= 1048576; n *= 2) {
        int *a = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            a[i] = 100;

        a[rand() % n] = 99;

        clock_t start = clock();

        for (int k = 0; k < 100; k++)
            findDefective(a, 0, n - 1);

        clock_t end = clock();

        printf("%d\t\t%.6f\n", n,
               (double)(end - start) / CLOCKS_PER_SEC);

        free(a);
    }

    return 0;
}
