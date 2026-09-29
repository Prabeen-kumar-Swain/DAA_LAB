#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, best = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int)), *dp = malloc(n * sizeof(int));
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
        if (dp[i] > best) best = dp[i];
    }
    printf("LIS length = %d\n", best);
    return 0;
}