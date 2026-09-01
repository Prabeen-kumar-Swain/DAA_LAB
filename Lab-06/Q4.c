//Matrix chain multiplication using dynamic programming
#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int p[], int n) {
    int dp[n][n];
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions of the matrices: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("The minimum number of scalar multiplications is: %d\n", matrixChainMultiplication(p, n + 1));
    return 0;
}
/*
Algorithm:
1. Create a 2D array dp of size n x n to store the minimum number of multiplications 
   needed to multiply the matrices from i to j.
2. Initialize dp[i][i] = 0 for all i, since multiplying one matrix requires no multiplications.
3. For each length of the chain from 2 to n, calculate the minimum number of 
   multiplications needed to multiply the matrices from i to j by trying all possible positions
   to split the product.
4. Return dp[1][n-1], which contains the minimum number of multiplications needed to 
   multiply the entire chain of matrices.
*/

//Time Complexity: O(n^3) - We have three nested loops, each going up to n.
