//[Super egg testing experiment]
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int E, F;
    int dp[20][101];

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    for (int e = 1; e <= E; e++)
    {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int f = 1; f <= F; f++)
        dp[1][f] = f;

    for (int e = 2; e <= E; e++)
    {
        for (int f = 2; f <= F; f++)
        {
            dp[e][f] = 999999;

            for (int x = 1; x <= f; x++)
            {
                int trials = 1 + max(dp[e - 1][x - 1],
                                     dp[e][f - x]);

                if (trials < dp[e][f])
                    dp[e][f] = trials;
            }
        }
    }

    printf("Minimum number of droppings = %d\n", dp[E][F]);

    return 0;
}


/*
ALGORITHM: SUPER EGG DROPPING

1. Read E = number of eggs and F = number of floors.
2. Create dp[E+1][F+1].
3. dp[e][0] = 0 because zero floors need zero trials.
4. dp[e][1] = 1 because one floor needs one trial.
5. dp[1][f] = f because with one egg we must check floors one by one.
6. For every number of eggs e and floors f:
      Try dropping the egg from every floor x.
7. If egg breaks:
      We have e-1 eggs and x-1 floors.
8. If egg does not break:
      We have e eggs and f-x floors.
9. Take the worst case and add one trial:
      dp[e][f] = 1 + min(max(dp[e-1][x-1],
                            dp[e][f-x]))
10. Print dp[E][F].

Complexity: O(E * F^2)
Space: O(E * F)
*/
