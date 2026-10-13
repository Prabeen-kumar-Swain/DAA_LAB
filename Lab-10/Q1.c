
#include <stdio.h>
int parent[1005], parity[1005];

int find(int x) {
    if (parent[x] == x) return x;
    int p = parent[x];
    parent[x] = find(p);
    parity[x] ^= parity[p];
    return parent[x];
}

int addEdge(int u, int v) {
    int a = find(u), b = find(v);
    int pu = parity[u], pv = parity[v];

    if (a == b)
        return (pu ^ pv) == 1;

    parent[a] = b;
    parity[a] = pu ^ pv ^ 1;
    return 1;
}

int main() {
    int V, E, u, v;
    scanf("%d%d", &V, &E);

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int i = 1; i <= E; i++) {
        scanf("%d%d", &u, &v);

        if (addEdge(u, v))
            printf("Edge %d accepted\n", i);
        else
            printf("Edge %d rejected\n", i);
    }
    return 0;
}
