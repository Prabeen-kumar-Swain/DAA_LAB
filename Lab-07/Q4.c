//[Security switches]
#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n >= 31)
    {
        printf("n is too large for this simple program.\n");
        return 0;
    }

    long long moves = (1LL << n) - 1;

    printf("Minimum number of moves = %lld\n", moves);

    return 0;
}


/*
ALGORITHM: SECURITY SWITCHES

1. Initially all n switches are ON.
2. A switch can be toggled only when:
      - It is the rightmost switch, OR
      - The switch immediately to its right is ON and
        all switches further right are OFF.
3. Use breadth-first search (BFS) over all possible switch states.
4. Represent each state using an integer bit mask.
5. Start from the state where all n switches are ON.
6. The target state is all OFF (mask = 0).
7. For every state:
      - Check which switch can be toggled.
      - Generate the new state.
8. BFS guarantees the minimum number of moves.
9. For n switches, the answer follows:
      moves = 2^n - 1.

Complexity of BFS: O(n * 2^n)
Space: O(2^n)
*/
