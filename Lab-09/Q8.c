#include <stdio.h>

struct Meeting {
    int start;
    int end;
};

void swap(struct Meeting *a, struct Meeting *b) {
    struct Meeting t = *a;
    *a = *b;
    *b = t;
}

void sort(struct Meeting a[], int n) {
    int i, j;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i].start > a[j].start)
                swap(&a[i], &a[j]);
        }
    }
}

void push(int heap[], int *n, int x) {
    int i = (*n)++;
    heap[i] = x;

    while(i > 0) {
        int p = (i - 1) / 2;

        if(heap[p] <= heap[i])
            break;

        int t = heap[p];
        heap[p] = heap[i];
        heap[i] = t;

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
        int small = i;

        if(l < *n && heap[l] < heap[small])
            small = l;

        if(r < *n && heap[r] < heap[small])
            small = r;

        if(small == i)
            break;

        int t = heap[i];
        heap[i] = heap[small];
        heap[small] = t;

        i = small;
    }

    return x;
}

int main() {
    int n, i;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    struct Meeting a[n];

    for(i = 0; i < n; i++) {
        printf("Enter start and end: ");
        scanf("%d %d", &a[i].start, &a[i].end);
    }

    sort(a, n);

    int heap[n];
    int size = 0;
    int rooms = 0;

    for(i = 0; i < n; i++) {

        while(size > 0 && heap[0] <= a[i].start)
            pop(heap, &size);

        push(heap, &size, a[i].end);

        if(size > rooms)
            rooms = size;
    }

    printf("Minimum number of rooms = %d\n", rooms);

    return 0;
}

//Complexity: The sorting above is O(n²), while heap operations take O(n log n). Therefore the complete program is O(n²).