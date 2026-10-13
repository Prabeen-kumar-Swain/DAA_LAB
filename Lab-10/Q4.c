
#include <stdio.h>
int parent[1005], active[1005];
long long weight[1005], sum[1005], ans[1005];
int graph[1005][1005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

long long unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return sum[u];

    parent[v] = u;
    sum[u] += sum[v];
    return sum[u];
}

int main() {
    int n, m, u, v, p[1005];
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%lld", &weight[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    long long mx = 0;

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = mx;

        int x = p[i];
        active[x] = 1;
        parent[x] = x;
        sum[x] = weight[x];

        if (sum[x] > mx) mx = sum[x];

        for (int j = 1; j <= n; j++) {
            if (active[j] && graph[x][j]) {
                long long s = unite(x, j);
                if (s > mx) mx = s;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
