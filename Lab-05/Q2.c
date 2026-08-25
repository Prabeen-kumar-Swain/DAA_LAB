//Finding the k th smallest element in the array without sorting
#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, temp;

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

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    int p = partition(a, low, high);

    if (p == k)
        return a[p];

    if (k < p)
        return quickSelect(a, low, p - 1, k);

    return quickSelect(a, p + 1, high, k);
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid K\n");
        return 0;
    }

    printf("%dth smallest element = %d\n",
           k, quickSelect(a, 0, n - 1, k - 1));

    return 0;
}
