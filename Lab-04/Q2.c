/*Algorithm: Pair Sum

Input: Two sets S1, S2 of size n, and integer X.
Output: Whether a pair exists whose sum is X.

Steps:

1. Start.
2. Read n.
3. Read the elements of S1.
4. Read the elements of S2.
5. Sort S2 using Merge Sort.
6. For every element a in S1:
7. Calculate required = X - a.
8. Perform Binary Search for required in S2.
        If required is found:
            A valid pair exists.
            Display the pair.
            Stop.
9. If all elements of S1 are checked and no pair is found, display "No pair exists."
10. Stop.

Complexity
Sorting S2:
O(n log n)

Binary search for every element of S1:
n × O(log n) = O(n log n)

Therefore:
Time Complexity = O(n log n)
*/

#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return 1;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int main() {
    int n, x;

    printf("Enter n: ");
    scanf("%d", &n);

    int S1[n], S2[n];

    printf("Enter S1:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S1[i]);

    printf("Enter S2:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S2[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    sort(S2, n);

    for (int i = 0; i < n; i++) {
        if (binarySearch(S2, n, x - S1[i])) {
            printf("Pair exists: %d + %d = %d\n",
                   S1[i], x - S1[i], x);
            return 0;
        }
    }

    printf("No such pair exists.\n");

    return 0;
}
