//Performance analysis of bubble sort
//(ii) Bubble sort that always completes the (n − 1)th pass.
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int comparisons=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            comparisons++;

            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Comparisons = %d\n",comparisons);
}

int main()
{
    int arr[]={5,1,4,2,8};
    int n=5;

    bubbleSort(arr,n);

    printf("Sorted Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
