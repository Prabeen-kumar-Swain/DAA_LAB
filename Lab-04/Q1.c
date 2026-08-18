/*Algorithm: Sort by Colour

Input: n pairs (number, colour), already sorted by number.
Output: Items arranged as Red → Blue → Yellow, while preserving number order within each colour.

Steps:

1. Start.
2. Read n.
3. Read the n pairs (number, colour).
4. Create an empty result array.
5. Traverse the input array from left to right.
6. Add all items whose colour is red to the result.
7. Traverse the input array again.
8. Add all items whose colour is blue to the result.
9. Traverse the input array again.
10. Add all items whose colour is yellow to the result.
11. Display the result.
12. Stop.

Complexity:
Three linear traversals: O(n)
Time Complexity = O(n)
Space Complexity = O(n)
*/

#include <stdio.h>
#include <string.h>

struct Item {
    int number;
    char colour[10];
};

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    struct Item a[n], result[n];
    int r = 0, b = 0, y = 0;

    printf("Enter number and colour (red/blue/yellow):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &a[i].number, a[i].colour);
    }

    /* First put all red items */
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "red") == 0)
            result[r++].number = a[i].number;
    }

    /* Then blue items */
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "blue") == 0)
            result[r++].number = a[i].number;
    }

    /* Then yellow items */
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "yellow") == 0)
            result[r++].number = a[i].number;
    }

    printf("Sorted items:\n");

    r = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "red") == 0)
            printf("%d red\n", a[i].number);
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "blue") == 0)
            printf("%d blue\n", a[i].number);
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].colour, "yellow") == 0)
            printf("%d yellow\n", a[i].number);
    }

    return 0;
}
