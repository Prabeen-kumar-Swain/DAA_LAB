#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, x, found = 0;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer for size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("Enter the element to search: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element %d found at position %d (index %d)\n", x, i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", x);
    }

    return 0;
}
