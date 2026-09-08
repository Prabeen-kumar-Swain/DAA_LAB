//[Invert the coin-triangle]
#include <stdio.h>

int main()
{
    int n, k;
    long long moves;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    k = n / 3;

    if (n % 3 == 0)
        moves = k * (3 * k + 1) / 2;
    else if (n % 3 == 1)
        moves = 3 * k * (k + 1) / 2;
    else
        moves = (k + 1) * (3 * k + 2) / 2;

    printf("Minimum moves = %lld\n", moves);

    return 0;
}

/*
ALGORITHM: INVERT COIN TRIANGLE

1. Read the number of rows n.
2. Find k = n / 3.
3. Depending on n % 3, use the corresponding formula:
      If n % 3 == 0:
          moves = k * (3*k + 1) / 2

      If n % 3 == 1:
          moves = 3 * k * (k + 1) / 2

      If n % 3 == 2:
          moves = (k + 1) * (3*k + 2) / 2

4. Print the minimum number of moves.
5. Complexity: O(1).
*/
