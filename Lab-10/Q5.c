
#include <stdio.h>
#include <stdlib.h>

int parent[1005], A[1005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
}

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main() {
    int n, m, u, v;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        unite(u, v);
    }

    for (int r = 0; r < n; r++) {
        if (find(r) != r) continue;

        int idx[1005], val[1005], k = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == r) {
                idx[k] = i;
                val[k] = A[i];
                k++;
            }
        }

        qsort(val, k, sizeof(int), compare);

        for (int i = 0; i < k; i++)
            A[idx[i]] = val[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");
    return 0;
}
