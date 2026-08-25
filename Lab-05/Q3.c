//Quick sort of N elements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int a[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = a[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    int p = i + 1;

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    FILE *fp;

    srand(time(NULL));

    fp = fopen("input.txt", "w");

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);

    fp = fopen("input.txt", "r");

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    quickSort(a, 0, n - 1);

    fp = fopen("output.txt", "w");

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", a[i]);

    fclose(fp);

    printf("Elements sorted successfully.\n");
    printf("Input stored in input.txt\n");
    printf("Sorted output stored in output.txt\n");

    return 0;
}
