#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge2(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort2(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort2(arr, l, m);
        mergeSort2(arr, m + 1, r);
        merge2(arr, l, m, r);
    }
}

void merge3(int arr[], int l, int m1, int m2, int r)
{
    int n1 = m1 - l + 1;
    int n2 = m2 - m1;
    int n3 = r - m2;

    int *A = (int *)malloc(n1 * sizeof(int));
    int *B = (int *)malloc(n2 * sizeof(int));
    int *C = (int *)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++)
        A[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        B[i] = arr[m1 + 1 + i];

    for (int i = 0; i < n3; i++)
        C[i] = arr[m2 + 1 + i];

    int i = 0, j = 0, k = 0, p = l;

    while (i < n1 || j < n2 || k < n3)
    {
        int min = 2147483647;

        if (i < n1 && A[i] < min)
            min = A[i];
        if (j < n2 && B[j] < min)
            min = B[j];
        if (k < n3 && C[k] < min)
            min = C[k];

        arr[p++] = min;

        if (i < n1 && A[i] == min)
            i++;
        else if (j < n2 && B[j] == min)
            j++;
        else if (k < n3 && C[k] == min)
            k++;
    }

    free(A);
    free(B);
    free(C);
}

void mergeSort3(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int third = (r - l) / 3;

    int m1 = l + third;
    int m2 = l + 2 * third;

    mergeSort3(arr, l, m1);
    mergeSort3(arr, m1 + 1, m2);
    mergeSort3(arr, m2 + 1, r);

    merge3(arr, l, m1, m2, r);
}

int main()
{
    FILE *fp = fopen("output.csv", "w");

    fprintf(fp, "Size,MergeSort,ModifiedMergeSort\n");

    srand(time(NULL));

    for (int n = 1000; n <= 50000; n += 1000)
    {
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            a[i] = rand();
            b[i] = a[i];
        }

        clock_t start, end;

        start = clock();
        mergeSort2(a, 0, n - 1);
        end = clock();
        double t1 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort3(b, 0, n - 1);
        end = clock();
        double t2 = (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(fp, "%d,%lf,%lf\n", n, t1, t2);

        printf("%d Done\n", n);

        free(a);
        free(b);
    }

    fclose(fp);

    printf("Data saved in output.csv\n");

    /* Generate Gnuplot Script */
    FILE *gp = fopen("plot.gp", "w");

    
    fprintf(gp, "set datafile separator ','\n");
    fprintf(gp, "set title 'Merge Sort vs Modified Merge Sort'\n");
    fprintf(gp, "set xlabel 'Input Size (N)'\n");
    fprintf(gp, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key top left\n");
    fprintf(gp, "set terminal qt\n");
    //fprintf(gp, "set terminal png size 1000,800\n");
    //fprintf(gp, "set output 'merge_comp.png'\n");
    fprintf(gp, "plot 'output.csv' using 1:2 with linespoints lw 2 pt 7 title 'Merge Sort',\\\n");
    fprintf(gp, "     'output.csv' using 1:3 with linespoints lw 2 pt 5 title 'Modified Merge Sort'\n");
    fprintf(gp, "pause -1\n");

    fclose(gp);

    /* Automatically launch gnuplot */
    system("gnuplot plot.gp");

    return 0;
}
