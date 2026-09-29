#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    long long best = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    long long *ms = malloc(n * sizeof(long long));
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        ms[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && ms[j] + a[i] > ms[i]) ms[i] = ms[j] + a[i];
        if (ms[i] > best) best = ms[i];
    }
    printf("Maximum sum = %lld\n", best);
    return 0;
}