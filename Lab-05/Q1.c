//Finding Median without sorting the array
#include <stdio.h>

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1, temp;

    for (int j = low; j < high; j++){
        if (a[j] <= pivot){
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

int quickSelect(int a[], int low, int high, int k){
    if (low == high)
        return a[low];

    int p = partition(a, low, high);

    if (k == p)
        return a[p];
    else if (k < p)
        return quickSelect(a, low, p - 1, k);
    else
        return quickSelect(a, p + 1, high, k);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 == 1)
    {
        int median = quickSelect(a, 0, n - 1, n / 2);
        printf("Median = %d\n", median);
    }
    else
    {
        int x = quickSelect(a, 0, n - 1, n / 2 - 1);
        int y = quickSelect(a, 0, n - 1, n / 2);

        printf("Median = %.2f\n", (x + y) / 2.0);
    }

    return 0;
}
