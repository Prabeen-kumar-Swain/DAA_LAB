//Element uniqueness
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int n;

    printf("Enter no. of elements : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(int),cmp);

    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            printf("Duplicate Found\n");
            return 0;
        }
    }

    printf("All Elements are Unique\n");

    return 0;
}
