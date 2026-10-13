
#include <stdio.h>
int parent[1005], size[1005];
long long sum[1005], weight[1005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return;

    if (size[u] < size[v]) {
        int t = u;
        u = v;
        v = t;
    }

    parent[v] = u;
    size[u] += size[v];
    sum[u] += sum[v];
}

int main() {
    int n, m, K, u, v;
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &weight[i]);
        parent[i] = i;
        size[i] = 1;
        sum[i] = weight[i];
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        unite(u, v);

        long long ans = 0;

        for (int j = 1; j <= n; j++) {
            if (find(j) == j && size[j] <= K &&
                sum[j] > ans)
                ans = sum[j];
        }

        printf("%lld\n", ans);
    }

    return 0;
}
