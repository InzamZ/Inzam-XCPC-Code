#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 10;
using ll = long long;
int b[maxn], a[maxn];
int dp[maxn][maxn];
int main()
{
    int n, m, len, cnt;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= m; ++i)
        scanf("%d", b + i);
    for (int i = 1; i <= n; ++i)
        for (int j = 1 ; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}