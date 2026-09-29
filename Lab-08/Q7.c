#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter rod length n: ");
    scanf("%d", &n);
    int *p = malloc((n + 1) * sizeof(int)), *r = calloc(n + 1, sizeof(int)), *cut = calloc(n + 1, sizeof(int));
    printf("Enter prices p1..p%d: ", n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

    for (int j = 1; j <= n; j++) {
        r[j] = -1;
        for (int i = 1; i <= j; i++)
            if (p[i] + r[j - i] > r[j]) { r[j] = p[i] + r[j - i]; cut[j] = i; }
    }
    printf("Maximum revenue = %d\nPieces:", r[n]);
    for (int k = n; k > 0; k -= cut[k]) printf(" %d", cut[k]);
    printf("\n");
    return 0;
}