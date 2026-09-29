#include <stdio.h>
#define N 101

double p[N], q[N], e[N + 1][N], w[N + 1][N];
int root[N][N];

void show(int i, int j, int d) {         /* tree printed sideways: right subtree on top */
    if (i > j) { printf("%*sd%d\n", d * 4, "", j); return; }
    int r = root[i][j];
    show(r + 1, j, d + 1);
    printf("%*sk%d\n", d * 4, "", r);
    show(i, r - 1, d + 1);
}

int main() {
    int n;
    printf("Enter number of keys n (<=100): ");
    scanf("%d", &n);
    printf("Enter p1..p%d: ", n);
    for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
    printf("Enter q0..q%d: ", n);
    for (int i = 0; i <= n; i++) scanf("%lf", &q[i]);

    for (int i = 1; i <= n + 1; i++) e[i][i-1] = w[i][i-1] = q[i-1];
    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            e[i][j] = 1e18;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if (t < e[i][j]) { e[i][j] = t; root[i][j] = r; }
            }
        }
    printf("Minimum expected search cost = %.4f\nTree (rotated 90 degrees, root at left):\n", e[1][n]);
    show(1, n, 0);
    return 0;
}