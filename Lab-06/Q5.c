#include <stdio.h>
#include <math.h>

void maximum(int a[], int n) {
    int max = a[0], i;

    for (i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }

    printf("Maximum = %d\n", max);
}

void largestTwo(int a[], int n) {
    int largest, second, i;

    largest = second = -999999;

    for (i = 0; i < n; i++) {
        if (a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if (a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", second);
}

void mean(int a[], int n) {
    int sum = 0, i;
    float avg;

    for (i = 0; i < n; i++)
        sum += a[i];

    avg = (float)sum / n;

    printf("Mean = %.2f\n", avg);
}

void median(int a[], int n) {
    int b[100], i, j, temp;
    float med;

    /* Copy array */
    for (i = 0; i < n; i++)
        b[i] = a[i];

    /* Sort array */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    if (n % 2 == 1)
        med = b[n / 2];
    else
        med = (b[n / 2 - 1] + b[n / 2]) / 2.0;

    printf("Median = %.2f\n", med);
}

void standardDeviation(int a[], int n) {
    int i;
    float sum = 0, mean, variance = 0, sd;

    for (i = 0; i < n; i++)
        sum += a[i];

    mean = sum / n;

    for (i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance = variance / n;
    sd = sqrt(variance);

    printf("Standard Deviation = %.2f\n", sd);
}

void mode(int a[], int n) {
    int i, j, count, maxCount = 0;
    int modeValue = a[0];

    for (i = 0; i < n; i++) {
        count = 0;

        for (j = 0; j < n; j++) {
            if (a[i] == a[j])
                count++;
        }

        if (count > maxCount) {
            maxCount = count;
            modeValue = a[i];
        }
    }

    printf("Mode = %d\n", modeValue);
}

void removeDuplicates(int a[], int *n) {
    int i, j, k;

    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; j++) {

            if (a[i] == a[j]) {

                for (k = j; k < *n - 1; k++)
                    a[k] = a[k + 1];

                (*n)--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates:\n");

    for (i = 0; i < *n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void reverseArray(int a[], int n) {
    int i, temp;

    for (i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    printf("Reversed array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void partitionArray(int a[], int n, int pivot) {
    int i = 0, j = n - 1, temp;

    while (i < j) {

        while (i < n && a[i] >= pivot)
            i++;

        while (j >= 0 && a[j] < pivot)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    printf("Partitioned array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int a[100], n, i, choice, pivot;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Find Maximum\n");
        printf("2. Find First and Second Largest\n");
        printf("3. Find Mean\n");
        printf("4. Find Median\n");
        printf("5. Find Standard Deviation\n");
        printf("6. Find Mode\n");
        printf("7. Remove Duplicates\n");
        printf("8. Reverse Array\n");
        printf("9. Partition Around Pivot\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                maximum(a, n);
                break;

            case 2:
                largestTwo(a, n);
                break;

            case 3:
                mean(a, n);
                break;

            case 4:
                median(a, n);
                break;

            case 5:
                standardDeviation(a, n);
                break;

            case 6:
                mode(a, n);
                break;

            case 7:
                removeDuplicates(a, &n);
                break;

            case 8:
                reverseArray(a, n);
                break;

            case 9:
                printf("Enter pivot: ");
                scanf("%d", &pivot);
                partitionArray(a, n, pivot);
                break;

            case 0:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}


/*
COMPLEXITY ANALYSIS

1. Finding Maximum:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)

2. Finding First and Second Largest:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)

3. Finding Mean:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)

4. Finding Median:
   Worst-case Time Complexity: O(n^2)
   Space Complexity: O(n)
   (Using simple sorting)

5. Finding Standard Deviation:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)

6. Finding Mode:
   Worst-case Time Complexity: O(n^2)
   Space Complexity: O(1)

7. Removing All Duplicates:
   Worst-case Time Complexity: O(n^2)
   Space Complexity: O(1)

8. Reversing the Array:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)

9. Partitioning Around a Pivot:
   Worst-case Time Complexity: O(n)
   Space Complexity: O(1)
*/
