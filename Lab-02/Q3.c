#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_K 64
#define ARRAY_SIZE 1000

/*
    Merge two sorted arrays
*/
void merge(int *a, int sizeA,
           int *b, int sizeB,
           int *result)
{
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < sizeA)
        result[k++] = a[i++];

    while (j < sizeB)
        result[k++] = b[j++];
}

/*
    Generate k sorted arrays
*/
void generateSortedArrays(int **arr, int k, int n)
{
    for (int i = 0; i < k; i++)
    {
        int value = rand() % 20;

        for (int j = 0; j < n; j++)
        {
            value += rand() % 10 + 1;
            arr[i][j] = value;
        }
    }
}

/*
    Method 1 : Sequential Merge
    Complexity : O(nk²)
*/
void sequentialMerge(int **arr,
                     int k,
                     int n,
                     int *result)
{
    int currentSize = n;

    int *current =
        (int *)malloc(currentSize * sizeof(int));

    for (int i = 0; i < currentSize; i++)
        current[i] = arr[0][i];

    for (int i = 1; i < k; i++)
    {
        int newSize = currentSize + n;

        int *merged =
            (int *)malloc(newSize * sizeof(int));

        merge(current,
              currentSize,
              arr[i],
              n,
              merged);

        free(current);

        current = merged;
        currentSize = newSize;
    }

    for (int i = 0; i < currentSize; i++)
        result[i] = current[i];

    free(current);
}

/*
    Method 2 : Pairwise Merge
*/
void pairwiseMerge(int **arr,
                   int k,
                   int n,
                   int *result)
{
    int **lists =
        (int **)malloc(MAX_K * sizeof(int *));

    int *sizes =
        (int *)malloc(MAX_K * sizeof(int));

    int currentLists = k;

    /* Copy original arrays */

    for (int i = 0; i < k; i++)
    {
        lists[i] =
            (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
            lists[i][j] = arr[i][j];

        sizes[i] = n;
    }

    while (currentLists > 1)
    {
        int **newLists =
            (int **)malloc(MAX_K * sizeof(int *));

        int *newSizes =
            (int *)malloc(MAX_K * sizeof(int));

        int index = 0;

        for (int i = 0; i < currentLists; i += 2)
        {
            if (i + 1 < currentLists)
            {
                int size =
                    sizes[i] + sizes[i + 1];

                int *merged =
                    (int *)malloc(size * sizeof(int));

                merge(lists[i],
                      sizes[i],
                      lists[i + 1],
                      sizes[i + 1],
                      merged);

                free(lists[i]);
                free(lists[i + 1]);

                newLists[index] = merged;
                newSizes[index] = size;

                index++;
            }
            else
            {
                /* Carry forward the last array */
                newLists[index] = lists[i];
                newSizes[index] = sizes[i];
                index++;
            }
        }

        free(lists);
        free(sizes);

        lists = newLists;
        sizes = newSizes;
        currentLists = index;
    }

    for (int i = 0; i < sizes[0]; i++)
        result[i] = lists[0][i];

    free(lists[0]);
    free(lists);
    free(sizes);
}



int main()
{
    srand(time(NULL));

    FILE *fp = fopen("output.csv", "w");

    if (fp == NULL)
    {
        printf("Error creating output file.\n");
        return 1;
    }

    fprintf(fp,
            "K,Sequential Merge,Pairwise Merge\n");

    for (int k = 2; k <= 32; k++)
    {
        int **arrays =
            (int **)malloc(k * sizeof(int *));

        for (int i = 0; i < k; i++)
        {
            arrays[i] =
                (int *)malloc(ARRAY_SIZE * sizeof(int));
        }

        generateSortedArrays(arrays, k, ARRAY_SIZE);

        int *result =
            (int *)malloc(k * ARRAY_SIZE * sizeof(int));

        clock_t start, end;

        /*
            Method 1 : Sequential Merge
        */

        start = clock();

        sequentialMerge(arrays,
                        k,
                        ARRAY_SIZE,
                        result);

        end = clock();

        double timeSequential =
            (double)(end - start) / CLOCKS_PER_SEC;

        /*
            Method 2 : Pairwise Merge
        */

        start = clock();

        pairwiseMerge(arrays,
                      k,
                      ARRAY_SIZE,
                      result);

        end = clock();

        double timePairwise =
            (double)(end - start) / CLOCKS_PER_SEC;

        fprintf(fp,
                "%d,%lf,%lf\n",
                k,
                timeSequential,
                timePairwise);

        printf("k = %2d completed\n", k);

        free(result);

        for (int i = 0; i < k; i++)
            free(arrays[i]);

        free(arrays);
    }

    fclose(fp);

    printf("\nResults saved in output.csv\n");


    FILE *gp = fopen("plot.gp", "w");

    if (gp == NULL)
    {
        printf("Unable to create plot.gp\n");
        return 1;
    }

    fprintf(gp, "set datafile separator ','\n");
    fprintf(gp, "set title 'Comparison of Merging k Sorted Arrays'\n");
    fprintf(gp, "set xlabel 'Number of Arrays (k)'\n");
    fprintf(gp, "set ylabel 'Execution Time (seconds)'\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key left top\n");
    fprintf(gp, "set style data linespoints\n");

#ifdef _WIN32
    fprintf(gp, "set terminal windows\n");
#else
    fprintf(gp, "set terminal qt\n");
#endif

    // fprintf(gp, "set terminal png size 1000,800\n");
    // fprintf(gp, "set output 'merge_k.png'\n");
    fprintf(gp,
            "plot 'output.csv' using 1:2 "
            "title 'Method 1 : Sequential Merge' "
            "lw 2 pt 7 lc rgb 'blue',\\\n");

    fprintf(gp,
            "     'output.csv' using 1:3 "
            "title 'Method 2 : Pairwise Merge' "
            "lw 2 pt 5 lc rgb 'red'\n");

    fprintf(gp, "pause -1\n");

    fclose(gp);

    printf("Launching Gnuplot...\n");
    system("gnuplot plot.gp");
    printf("\nGraph displayed successfully.\n");
    return 0;
}
