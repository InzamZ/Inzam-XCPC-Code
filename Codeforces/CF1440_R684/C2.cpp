//InzamZ

#include <bits/stdc++.h>
int ans[20005][6], top = 0;
bool s[110][110];

void prians(int a, int b, int c, int d, int e, int f)
{
    ans[top][0] = a;
    ans[top][1] = b;
    ans[top][2] = c;
    ans[top][3] = d;
    ans[top][4] = e;
    ans[top][5] = f;
    s[a][b] = !s[a][b];
    s[c][d] = !s[c][d];
    s[e][f] = !s[e][f];
    top++;
    return ;
}

int main()
{
    int n, m, t;
    scanf ("%d", &t);
    while (t--) {
        top = 0;
        scanf ("%d %d ", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                scanf("%1d", &s[i][j]);
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m; j++) {
                if (s[i][j])
                    prians(i, j, i + 1, j, i + 1, j + 1);
            }
            if (s[i][m])
                prians(i, m, i + 1, m - 1, i + 1, m);
        }
        for (int i = 1; i < m; i++) {
            if (s[n - 1][i] == 0 && s[n][i] == 1)
                prians(n, i, n, i + 1, n - 1, i + 1);
            else if (s[n - 1][i] == 1 && s[n][i] == 0)
                prians(n - 1, i, n, i + 1, n - 1, i + 1);
            else if (s[n - 1][i] == 1 && s[n][i] == 1)
                prians(n - 1, i, n, i, n - 1, i + 1);
        }
        if (s[n - 1][m] && s[n][m]) {
            prians(n - 1, m - 1, n, m - 1, n, m);
            prians(n - 1, m - 1, n, m - 1, n - 1, m);
        }
        else if (!s[n - 1][m] && !s[n][m]) ;
        else if (!s[n - 1][m]) {
            prians(n - 1, m, n, m - 1, n, m);
            prians(n - 1, m - 1, n - 1, m, n, m);
            prians(n - 1, m - 1, n, m - 1, n, m);
        }
        else if (!s[n][m]) {
            prians(n - 1, m - 1, n - 1, m, n, m);
            prians(n - 1, m - 1, n - 1, m, n, m - 1);
            prians(n - 1, m, n, m - 1, n, m);
        }
        printf("%d\n", top);
        for (int i = 0; i < top; i++) {
            for (int j = 0; j < 6; j++)
                printf("%d ", ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
