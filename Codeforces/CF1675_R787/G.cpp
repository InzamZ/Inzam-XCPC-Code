#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9;
const int maxn = 1e3 + 10;
int m, n, a[maxn], sum[maxn];
int dp[maxn][maxn];

signed main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m ; ++j)
            dp[i][j] = inf;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    dp[0][0] = 0;
    for (int k = m; k >= 0; --k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= m - k; ++j)
                dp[i + 1][j + k] = min(dp[i + 1][j + k],dp[i][j] + abs(j - sum[i]));
    cout << dp[n][m] << endl;
    return 0;
}