/*Algorithm: K-Sum

Input: Set S containing n integers, integers k and T.
Output: Whether k elements have sum T.

Steps:

1. Start.
2. Read n.
3. Read the n elements of S.
4. Sort S using Merge Sort.
5. Define a recursive function KSum(S, n, k, index, target).
6. If k == 1:
        Perform Binary Search for target.
        If found, return TRUE.
        Otherwise, return FALSE.
    Otherwise:
        For every element from index to n-1:
        Select the current element.
7. Calculate:
        newTarget = target - S[i]
        Recursively call:
        KSum(S, n, k-1, i+1, newTarget)
8. If any recursive call returns TRUE, return TRUE.
9. If no combination is found, return FALSE.
10. Display whether k elements with sum T exist.
11. Stop.

Complexity:
The required complexity is approximately:
O(n^(k-1) log n)

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
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int findKSum(int a[], int n, int k, int index, int sum) {
    if (k == 1) {
        return binarySearch(a, n, sum);
    }

    for (int i = index; i < n; i++) {
        if (findKSum(a, n, k - 1, i + 1, sum - a[i]))
            return 1;
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    sort(a, n);

    if (findKSum(a, n, k, 0, T))
        printf("Yes, %d elements can make sum %d.\n", k, T);
    else
        printf("No such combination exists.\n");

    return 0;
}
