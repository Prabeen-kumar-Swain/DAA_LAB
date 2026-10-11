
#include <stdio.h>
#define MAX 100
#define INF 1000000000

int w[MAX], dp[MAX][MAX], split[MAX][MAX];
int prefix[MAX];

int sum(int i, int j) {
    return prefix[j + 1] - prefix[i];
}

void printTree(int i, int j) {
    if (i == j) {
        printf("L%d", i + 1);
        return;
    }

    printf("(");
    printTree(i, split[i][j]);
    printf(" + ");
    printTree(split[i][j] + 1, j);
    printf(")");
}

int main() {
    int n;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of weights.\n");
        return 1;
    }

    printf("Enter weights in their fixed order:\n");
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);

        if (w[i] <= 0) {
            printf("Weights must be positive.\n");
            return 1;
        }

        prefix[i + 1] = prefix[i] + w[i];
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + sum(i, j);

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nOptimal alphabetic merge pattern: ");
    printTree(0, n - 1);

    printf("\nMinimum weighted path cost: %d\n",
           dp[0][n - 1]);

    return 0;
}
