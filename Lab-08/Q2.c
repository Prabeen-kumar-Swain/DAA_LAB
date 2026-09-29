#include <stdio.h>

int countCombinations(int *C, int n, int V) {
    int dp[V + 1];
    for (int i = 0; i <= V; i++) {
        dp[i] = 0;
    }

    dp[0] = 1;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (C[j] <= i) {
                dp[i] += dp[i - C[j]];
            }
        }
    }

    return dp[V];
}
int main() {
    int C[] = {1, 2, 5};
    int n = sizeof(C) / sizeof(C[0]);
    int V;
    printf("Enter the value you want to give: ");
    scanf("%d",  &V);

    printf("Total number of distinct combinations: %d\n", countCombinations(C, n, V));
    return 0;
}
