//Heap sort of N randomly generated elements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int temp;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
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

    heapSort(a, n);

    fp = fopen("output.txt", "w");

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", a[i]);

    fclose(fp);

    printf("Elements sorted successfully.\n");
    printf("Input stored in input.txt\n");
    printf("Sorted output stored in output.txt\n");

    return 0;
}
