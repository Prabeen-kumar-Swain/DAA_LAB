//Find the partition point
#include <stdio.h>

int findPartition(int arr[], int n)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==0)
            low=mid+1;
        else
            high=mid-1;
    }

    return low;
}

int main(){
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter a run of 0s followed by a run of 1s: ");
    
    for(int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int index=findPartition(arr,n);

    printf("Transition point = %d\n",index);

    return 0;
}
