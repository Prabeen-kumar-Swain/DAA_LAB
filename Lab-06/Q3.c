//Longest common subsequence using dynamic programming
#include <stdio.h>
#include <string.h>

int longestCommonSubsequence(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    char X[100], Y[100];
    printf("Enter the first string: ");
    scanf("%s", X);
    printf("Enter the second string: ");
    scanf("%s", Y);
    printf("The length of the longest common subsequence is: %d\n", longestCommonSubsequence(X, Y));
    return 0;
}

/*
Algorithm:
1. Create a 2D array dp of size (m+1) x (n+1) to store the length of the longest common subsequence for substrings X[0..i-1] and Y[0..j-1].
2. Initialize dp[i][0] = 0 for all i, since the longest common subsequence with an empty string is 0.
3. Initialize dp[0][j] = 0 for all j, since the longest common subsequence with an empty string is 0.
4. For each character in X and Y:
   - If the characters are equal, then:
     dp[i][j] = dp[i-1][j-1] + 1
   - Otherwise:
     dp[i][j] = max(dp[i-1][j], dp[i][j-1])
5. Return dp[m][n], which contains the length of the longest common subsequence.
*/

//Time Complexity: O(m * n) - We have two nested loops, each going up to m and n respectively.
