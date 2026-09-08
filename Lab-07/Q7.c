//[Matrix Chain Multiplication]
#include <stdio.h>
#include <limits.h>

int dp[20][20];
int split[20][20];

void printOrder(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");

    printOrder(i, split[i][j]);
    printOrder(split[i][j] + 1, j);

    printf(")");
}

int main()
{
    int n;
    int p[20];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    /* Cost of one matrix is zero */
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    /* Chain length */
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum scalar multiplications = %d\n",
           dp[1][n]);

    printf("Optimal ordering = ");
    printOrder(1, n);
    printf("\n");

    return 0;
}

/*
ALGORITHM: MATRIX CHAIN MULTIPLICATION

1. Suppose there are n matrices:
       A1, A2, ..., An

2. Store their dimensions in array p.
   Matrix Ai has dimension:
       p[i-1] x p[i]

3. Create dp[i][j].
   dp[i][j] stores the minimum number of scalar
   multiplications needed for Ai...Aj.

4. A single matrix needs zero multiplication:
       dp[i][i] = 0

5. Consider chain lengths from 2 to n.

6. For every i and j:
       Try every possible splitting point k.

7. Cost of splitting at k:
       dp[i][k] + dp[k+1][j]
       + p[i-1] * p[k] * p[j]

8. Store the minimum cost in dp[i][j].
9. Store k in split[i][j].
10. Recursively print the optimal parenthesization.

Complexity:
Time = O(n^3)
Space = O(n^2)
*/
