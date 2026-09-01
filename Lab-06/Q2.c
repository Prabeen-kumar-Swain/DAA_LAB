//0-1 Knapsack problem using dynamic programming
#include <stdio.h>
#include <stdlib.h>

int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ? values[i - 1] + dp[i - 1][w - weights[i - 1]] : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("The maximum value that can be obtained is: %d\n", knapsack(W, weights, values, n));
    return 0;
}

/*
Algorithm:
1. Create a 2D array dp of size (n+1) x (W+1) to store the maximum value that can be obtained with a weight limit of w and considering the first i items.
2. Initialize dp[0][w] = 0 for all w, since no items can be selected with 0 items.
3. For each item i from 1 to n, and for each weight w from 0 to W:
   - If the weight of the current item is less than or equal to w, then:
     dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w - weights[i-1]])
   - Otherwise:
     dp[i][w] = dp[i-1][w]
4. Return dp[n][W], which contains the maximum value that can be obtained with the given weight limit and items.
*/

//Time Complexity: O(n * W) - We have two nested loops, each going up to n and W respectively.
