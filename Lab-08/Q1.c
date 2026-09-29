#include <stdio.h>

int minCoins(int *C, int n, int V) {
    int dp[V + 1];
    for (int i = 0; i <= V; i++) {
        dp[i] = V + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (C[j] <= i) {
                dp[i] = (dp[i] > dp[i - C[j]] + 1) ? dp[i - C[j]] + 1 : dp[i];
            }
        }
    }

    return (dp[V] == V + 1) ? -1 : dp[V];
}

int main() {
    int C[] = {1, 2, 5};
    int n = sizeof(C) / sizeof(C[0]);  
    int V;
    printf("Enter the value you want to give: ");
    scanf("%d",  &V);
  

    printf("Minimum number of coins needed: %d\n", minCoins(C, n, V));
    return 0;
}
//Complexity = O(n^2)