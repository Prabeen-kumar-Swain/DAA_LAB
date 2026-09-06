#include <stdio.h>

void reverse(int a[], int i, int j) {
    int temp;

    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
        j--;
    }
}

int main() {
    int a[100], n, i, j, maxIndex;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter permutation:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /*
       Put n, n-1, n-2, ... in their correct positions.
    */

    for (i = n - 1; i >= 0; i--) {

        maxIndex = 0;

        for (j = 1; j <= i; j++) {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }

        if (maxIndex != i) {

            /* Bring maximum to front */
            if (maxIndex != 0)
                reverse(a, 0, maxIndex);

            /* Bring maximum to its correct position */
            reverse(a, 0, i);
        }
    }

    printf("Sorted permutation:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
