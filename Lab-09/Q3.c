#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(int heap[], int *n, int x) {
    int i = (*n)++;
    heap[i] = x;

    while(i > 0) {
        int p = (i - 1) / 2;

        if(heap[p] >= heap[i])
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

int pop(int heap[], int *n) {
    int x = heap[0];
    heap[0] = heap[--(*n)];

    int i = 0;

    while(1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int large = i;

        if(l < *n && heap[l] > heap[large])
            large = l;

        if(r < *n && heap[r] > heap[large])
            large = r;

        if(large == i)
            break;

        swap(&heap[i], &heap[large]);
        i = large;
    }

    return x;
}

int main() {
    int n, D, F;
    int i, fuel, stops = 0;

    printf("Enter target distance: ");
    scanf("%d", &D);

    printf("Enter initial fuel: ");
    scanf("%d", &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    int d[n], f[n];

    for(i = 0; i < n; i++) {
        printf("Enter distance and fuel: ");
        scanf("%d %d", &d[i], &f[i]);
    }

    int heap[n];
    int size = 0;
    int position = 0;
    fuel = F;

    while(fuel < D) {
        while(position < n && d[position] <= fuel) {
            push(heap, &size, f[position]);
            position++;
        }

        if(size == 0) {
            printf("Cannot reach target\n");
            return 0;
        }

        fuel += pop(heap, &size);
        stops++;
    }

    printf("Minimum refuelling stops = %d\n", stops);

    return 0;
}

//Complexity: O(n log n) assuming stations are already sorted by distance.