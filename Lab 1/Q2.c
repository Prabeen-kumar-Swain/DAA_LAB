#include <stdio.h>
#include <stdlib.h>

int linearSearch2D(int rows, int cols, int arr[rows][cols], int key, int *foundRow, int *foundCol) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == key) {
                *foundRow = i;
                *foundCol = j;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int rows, cols;
    int key, foundRow, foundCol;

    // Ask for number of rows
    printf("Enter number of rows : ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    // Ask for number of columns
    printf("Enter number of columns : ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    int arr[rows][cols];
  
    printf("Enter %d elements for the %dx%d array:\n", rows * cols, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Ask for the search key
    printf("Enter the element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (linearSearch2D(rows, cols, arr, key, &foundRow, &foundCol)) {
        printf("Element %d found at position: Row %d, Column %d (0-indexed)\n", key, foundRow, foundCol);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
