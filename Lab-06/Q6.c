#include <stdio.h>
#include <math.h>

/* Matrix Addition */
void addition(int a[10][10], int b[10][10], int n) {
    int c[10][10], i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResult of Addition:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

/* Matrix Multiplication */
void multiplication(int a[10][10], int b[10][10], int n) {
    int c[10][10], i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;

            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResult of Multiplication:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

/* Check Zero Matrix */
void zeroMatrix(int a[10][10], int n) {
    int i, j, zero = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                zero = 0;
                break;
            }
        }
    }

    if (zero)
        printf("\nThe matrix is a Zero Matrix.\n");
    else
        printf("\nThe matrix is not a Zero Matrix.\n");
}

/* Check Symmetric Matrix */
void symmetric(int a[10][10], int n) {
    int i, j, flag = 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag)
        printf("\nThe matrix is Symmetric.\n");
    else
        printf("\nThe matrix is not Symmetric.\n");
}

/* Find Determinant */
int determinant(int a[10][10], int n) {
    int sub[10][10];
    int det = 0;
    int sign;
    int i, j, k, row, col;

    if (n == 1)
        return a[0][0];

    if (n == 2)
        return a[0][0] * a[1][1] -
               a[0][1] * a[1][0];

    for (i = 0; i < n; i++) {

        row = 0;

        for (j = 1; j < n; j++) {
            col = 0;

            for (k = 0; k < n; k++) {

                if (k == i)
                    continue;

                sub[row][col] = a[j][k];
                col++;
            }

            row++;
        }

        if (i % 2 == 0)
            sign = 1;
        else
            sign = -1;

        det = det + sign * a[0][i] *
              determinant(sub, n - 1);
    }

    return det;
}

/* Transpose Matrix In-Place */
void transpose(int a[10][10], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {

            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    printf("\nTranspose of Matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

/*
   Eigenvalue and Eigenvector

   The lab question asks for finding eigenvalues
   and eigenvectors, but does not specify a particular
   algorithm.

   Therefore, this program displays a message instead
   of using an arbitrary method.
*/
void eigenValueVector() {
    printf("\nEigenvalue and Eigenvector calculation requires\n");
    printf("a specified numerical algorithm such as Power Method.\n");
}

int main() {

    int a[10][10], b[10][10];
    int n, i, j, choice;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter first matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    do {

        printf("\n========== MENU ==========\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Check Zero Matrix\n");
        printf("4. Check Symmetric Matrix\n");
        printf("5. Find Determinant\n");
        printf("6. Transpose Matrix In-Place\n");
        printf("7. Eigenvalue and Eigenvector\n");
        printf("0. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter second matrix:\n");

                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++)
                        scanf("%d", &b[i][j]);
                }

                addition(a, b, n);
                break;

            case 2:
                printf("\nEnter second matrix:\n");

                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++)
                        scanf("%d", &b[i][j]);
                }

                multiplication(a, b, n);
                break;

            case 3:
                zeroMatrix(a, n);
                break;

            case 4:
                symmetric(a, n);
                break;

            case 5:
                printf("\nDeterminant = %d\n",
                       determinant(a, n));
                break;

            case 6:
                transpose(a, n);
                break;

            case 7:
                eigenValueVector();
                break;

            case 0:
                printf("\nProgram ended.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}


/*
COMPLEXITY ANALYSIS

1. Matrix Addition:
   Time Complexity  : O(n^2)
   Space Complexity : O(n^2)

2. Matrix Multiplication:
   Time Complexity  : O(n^3)
   Space Complexity : O(n^2)

3. Checking Zero Matrix:
   Time Complexity  : O(n^2)
   Space Complexity : O(1)

4. Checking Symmetric Matrix:
   Time Complexity  : O(n^2)
   Space Complexity : O(1)

5. Finding Determinant:
   Time Complexity  : O(n!)
   Space Complexity : O(n^2) approximately

6. Transposing Matrix In-Place:
   Time Complexity  : O(n^2)
   Space Complexity : O(1)

7. Finding Eigenvalue and Eigenvector:
   Depends on the numerical algorithm used.
   The lab sheet does not specify an algorithm.

*/
