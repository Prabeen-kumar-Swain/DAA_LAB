//Reve’s puzzle
#include <stdio.h>

int dp[50];
int split[50];

void hanoi3(int n, char from, char to, char aux)
{
    if (n == 0)
        return;

    hanoi3(n - 1, from, aux, to);

    printf("Move disk %d: %c -> %c\n", n, from, to);

    hanoi3(n - 1, aux, to, from);
}

void hanoi4(int n, char from, char to, char aux1, char aux2)
{
    int k;

    if (n == 0)
        return;

    if (n == 1)
    {
        printf("Move disk 1: %c -> %c\n", from, to);
        return;
    }

    k = split[n];

    hanoi4(k, from, aux1, to, aux2);

    hanoi3(n - k, from, to, aux2);

    hanoi4(k, aux1, to, from, aux2);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 999999;

        for (int k = 1; k < i; k++)
        {
            int moves = 2 * dp[k] + (1 << (i - k)) - 1;

            if (moves < dp[i])
            {
                dp[i] = moves;
                split[i] = k;
            }
        }
    }

    printf("\nMinimum moves = %d\n", dp[n]);

    if (n == 8)
        printf("For 8 disks, expected answer = 33 moves\n");

    printf("\nMoves:\n");

    hanoi4(n, 'A', 'D', 'B', 'C');

    return 0;
}


/*
ALGORITHM: REVE'S PUZZLE

1. There are 4 pegs.
2. Let dp[n] be the minimum moves required for n disks.
3. For n disks, choose k disks to move using all 4 pegs.
4. Move the remaining n-k disks using the normal 3-peg Hanoi:
       2^(n-k) - 1 moves.
5. Move the k disks to the destination using 4 pegs.
6. Therefore:
       dp[n] = min(2*dp[k] + 2^(n-k) - 1)
       for all 1 <= k < n.
7. Store the best k in split[n].
8. Recursively perform the moves.
9. For n = 8, the minimum is 33 moves.

Complexity of DP: O(n^2)
*/

/*
this problem is similar to tower of hanoi.
The only difference is that Tower of Hanoi has 3 pegs and Reve's Puzzle has 4 pegs.
*/
