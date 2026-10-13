
#include <stdio.h>
int parent[10005], rank[10005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (rank[a] < rank[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
    return 1;
}

int main() {
    int R, C, k, r, c;
    int grid[105][105] = {0};
    int count = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    scanf("%d%d%d", &R, &C, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &r, &c);

        if (grid[r][c]) {
            printf("%d\n", count);
            continue;
        }

        grid[r][c] = 1;
        int id = r * C + c;
        parent[id] = id;
        rank[id] = 0;
        count++;

        for (int j = 0; j < 4; j++) {
            int nr = r + dr[j];
            int nc = c + dc[j];

            if (nr >= 0 && nr < R &&
                nc >= 0 && nc < C && grid[nr][nc]) {
                if (unite(id, nr * C + nc))
                    count--;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
