#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node *node = malloc(sizeof(struct Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Node *heap[], int n, int i) {
    int small = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && heap[l]->freq < heap[small]->freq)
        small = l;

    if(r < n && heap[r]->freq < heap[small]->freq)
        small = r;

    if(small != i) {
        swap(&heap[i], &heap[small]);
        heapify(heap, n, small);
    }
}

void insert(struct Node *heap[], int *n, struct Node *node) {
    int i = (*n)++;
    heap[i] = node;

    while(i > 0) {
        int p = (i - 1) / 2;

        if(heap[p]->freq <= heap[i]->freq)
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

struct Node* extractMin(struct Node *heap[], int *n) {
    struct Node *min = heap[0];

    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);

    return min;
}

void printCodes(struct Node *root, char code[], int depth) {
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }

    code[depth] = '0';
    printCodes(root->left, code, depth + 1);

    code[depth] = '1';
    printCodes(root->right, code, depth + 1);
}

int main() {
    int n, i;
    printf("Enter number of symbols: ");
    scanf("%d", &n);

    struct Node *heap[100];

    for(i = 0; i < n; i++) {
        char ch;
        int freq;

        printf("Enter symbol and frequency: ");
        scanf(" %c %d", &ch, &freq);

        heap[i] = createNode(ch, freq);
    }

    int size = n;

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);

    while(size > 1) {
        struct Node *a = extractMin(heap, &size);
        struct Node *b = extractMin(heap, &size);

        struct Node *parent = createNode('$', a->freq + b->freq);
        parent->left = a;
        parent->right = b;

        insert(heap, &size, parent);
    }

    char code[100];

    printf("\nHuffman Codes:\n");
    printCodes(heap[0], code, 0);

    return 0;
}

//Complexity : O(nlogn)