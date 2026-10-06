#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i) {
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && a[l] > a[large])
        large = l;

    if(r < n && a[r] > a[large])
        large = r;

    if(large != i) {
        swap(&a[i], &a[large]);
        heapify(a, n, large);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if(a[i] % 2 != 0)
            a[i] *= 2;
    }

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    int min = a[0];

    for(i = 1; i < n; i++)
        if(a[i] < min)
            min = a[i];

    int answer = a[0] - min;

    while(a[0] % 2 == 0) {

        a[0] /= 2;

        if(a[0] < min)
            min = a[0];

        heapify(a, n, 0);

        int deviation = a[0] - min;

        if(deviation < answer)
            answer = deviation;
    }

    printf("Minimum deviation = %d\n", answer);

    return 0;
}

//Complexity: O(n log n) in the worst case.