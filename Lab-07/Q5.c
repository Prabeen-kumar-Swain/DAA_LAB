#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    printf("Shooting sequence:\n");

    /* Left to right */
    for (int i = 1; i <= n; i++)
        printf("%d ", i);

    /* Right to left */
    for (int i = n; i >= 1; i--)
        printf("%d ", i);

    printf("\n");

    printf("Target is guaranteed to be hit.\n");
    printf("Maximum number of shots = %d\n", 2 * n);

    return 0;
}


/*
ALGORITHM: HITTING A MOVING TARGET

1. There are n hiding spots numbered 1 to n.
2. The target moves to an adjacent spot after every shot.
3. Shoot the spots from left to right:
       1, 2, 3, ..., n
4. Then shoot from right to left:
       n, n-1, ..., 1
5. The first sweep catches one parity of possible target positions.
6. The reverse sweep catches the other parity.
7. Therefore, the target is guaranteed to be hit.
8. Number of shots = 2*n.

Complexity: O(n)
Space: O(1)
*/
