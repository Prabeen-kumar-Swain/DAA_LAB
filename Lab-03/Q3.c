// Max and Min using D&C Approach:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int min;
    int max;
} Result;

Result minMax(int a[], int l, int r) {
    Result x, y, z;

    if (l == r) {
        x.min = x.max = a[l];
        return x;
    }

    if (r == l + 1) {
        if (a[l] < a[r]) {
            x.min = a[l];
            x.max = a[r];
        } else {
            x.min = a[r];
            x.max = a[l];
        }
        return x;
    }

    int mid = (l + r) / 2;

    x = minMax(a, l, mid);
    y = minMax(a, mid + 1, r);

    z.min = x.min < y.min ? x.min : y.min;
    z.max = x.max > y.max ? x.max : y.max;

    return z;
}

int main() {
    srand(time(NULL));
    printf("\n-----------------------------------------------\n");
    printf("|       Max and Min using D&C Approach:       |");
    printf("\n-----------------------------------------------\n");

    printf("\nSize\t\tTime\n");

    for (int n = 100000; n < 10000000; n += 100000) {

        int *a = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            a[i] = rand();

        clock_t start = clock();

        Result r = minMax(a, 0, n - 1);

        clock_t end = clock();

        printf("%d\t\t%.6f\n", n,
               (double)(end - start) / CLOCKS_PER_SEC);

        free(a);
    }

    return 0;
}
