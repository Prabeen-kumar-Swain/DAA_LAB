#include <stdio.h>
#include <string.h>

struct Node {
    char ch;
    int freq;
};

void swap(struct Node *a, struct Node *b) {
    struct Node t = *a;
    *a = *b;
    *b = t;
}

void push(struct Node heap[], int *n, struct Node x) {
    int i = (*n)++;
    heap[i] = x;

    while(i > 0) {
        int p = (i - 1) / 2;

        if(heap[p].freq >= heap[i].freq)
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

struct Node pop(struct Node heap[], int *n) {
    struct Node x = heap[0];

    heap[0] = heap[--(*n)];

    int i = 0;

    while(1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int large = i;

        if(l < *n && heap[l].freq > heap[large].freq)
            large = l;

        if(r < *n && heap[r].freq > heap[large].freq)
            large = r;

        if(large == i)
            break;

        swap(&heap[i], &heap[large]);
        i = large;
    }

    return x;
}

int main() {
    char s[1000], result[1000];
    int K, freq[256] = {0};
    int i, n, size = 0, pos = 0;

    printf("Enter string: ");
    scanf("%s", s);

    printf("Enter K: ");
    scanf("%d", &K);

    n = strlen(s);

    for(i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    struct Node heap[256];

    for(i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            struct Node x;
            x.ch = i;
            x.freq = freq[i];
            push(heap, &size, x);
        }
    }

    struct Node waiting[256];
    int front = 0, rear = 0;

    for(i = 0; i < n; i++) {

        if(rear - front >= K) {
            struct Node x = waiting[front++];

            if(x.freq > 0)
                push(heap, &size, x);
        }

        if(size == 0) {
            printf("Impossible\n");
            return 0;
        }

        struct Node x = pop(heap, &size);

        result[pos++] = x.ch;
        x.freq--;

        waiting[rear++] = x;
    }

    result[pos] = '\0';

    printf("Reorganised string = %s\n", result);

    return 0;
}

//Complexity: With a fixed character set such as ASCII, approximately O(n log 256), effectively O(n).