#include <stdio.h>

void lcs(char *X, char *Y, int m, int n, char *LCS) {
    // Create a table to store the length of the longest common subsequence
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill up the table in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // Reconstruct the longest common subsequence string
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            LCS[dp[i][j] - 1] = X[i - 1];
            i--;
            j--;
            dp[i][j]--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    // Print the longest common subsequence string
    printf("Longest common subsequence: %s\n", LCS);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    int m = strlen(X);
    int n = strlen(Y);
    char LCS[m + 1];
    lcs(X, Y, m, n, LCS);
    return 0;
}
