#include <stdio.h>
#include <string.h>
#define N 1001

char A[N], B[N];
int D[N][N];

int min(int a, int b, int c) { int m = a < b ? a : b; return m < c ? m : c; }

void trace(int i, int j) {               /* recurse first => operations print in forward order */
    if (!i && !j) return;
    if (i && j && A[i-1] == B[j-1] && D[i][j] == D[i-1][j-1])
        { trace(i-1, j-1); printf("Match   %c\n", A[i-1]); }
    else if (i && j && D[i][j] == D[i-1][j-1] + 1)
        { trace(i-1, j-1); printf("Replace %c -> %c\n", A[i-1], B[j-1]); }
    else if (i && D[i][j] == D[i-1][j] + 1)
        { trace(i-1, j); printf("Delete  %c\n", A[i-1]); }
    else
        { trace(i, j-1); printf("Insert  %c\n", B[j-1]); }
}

int main() {
    printf("Enter A (no spaces): "); scanf("%1000s", A);
    printf("Enter B (no spaces): "); scanf("%1000s", B);
    int m = strlen(A), n = strlen(B);

    for (int i = 0; i <= m; i++) D[i][0] = i;
    for (int j = 0; j <= n; j++) D[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            D[i][j] = A[i-1] == B[j-1] ? D[i-1][j-1]
                    : 1 + min(D[i-1][j-1], D[i-1][j], D[i][j-1]);

    printf("Edit distance = %d\nTraceback:\n", D[m][n]);
    trace(m, n);
    return 0;
}