#include <stdio.h>

int main() {
    int n, i, total = 0;

    printf("Enter number of children: ");
    scanf("%d", &n);

    int rating[n], candy[n];

    printf("Enter ratings:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &rating[i]);
        candy[i] = 1;
    }

    for(i = 1; i < n; i++) {
        if(rating[i] > rating[i - 1])
            candy[i] = candy[i - 1] + 1;
    }

    for(i = n - 2; i >= 0; i--) {
        if(rating[i] > rating[i + 1] &&
           candy[i] <= candy[i + 1])
            candy[i] = candy[i + 1] + 1;
    }

    for(i = 0; i < n; i++)
        total += candy[i];

    printf("Minimum candies = %d\n", total);

    return 0;
}

//Complexity: O(n)