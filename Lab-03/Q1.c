// Binary vs Ternary Search:
#include <stdio.h>
#include <stdlib.h>

long long binaryComparisons(int a[], int n, int x) {
    int l = 0, r = n - 1;
    long long count = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;

        count++;

        if (a[m] == x)
            return count;

        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return count;
}

long long ternaryComparisons(int a[], int n, int x) {
    int l = 0, r = n - 1;
    long long count = 0;

    while (l <= r) {
        int third = (r - l) / 3;
        int m1 = l + third;
        int m2 = r - third;

        count++;

        if (a[m1] == x)
            return count;

        count++;

        if (a[m2] == x)
            return count;

        if (x < a[m1])
            r = m1 - 1;
        else if (x > a[m2])
            l = m2 + 1;
        else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }

    return count;
}

int main() {
    printf("\n-----------------------------------------------\n");
    printf("|       Counting number of comparisons:       |");
    printf("\n-----------------------------------------------\n");
    printf("\nSize\t\tBinary\tTernary\n");

    for (int n = 1000; n <= 1000000; n += 100000) {

        int *a = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            a[i] = i * 2;

        int x = a[n - 1];

        long long binary = binaryComparisons(a, n, x);
        long long ternary = ternaryComparisons(a, n, x);

        printf("%d\t\t%lld\t%lld\n", n, binary, ternary);

        free(a);
    }

    return 0;
}
