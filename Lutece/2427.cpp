#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
using ll = long long;

int dp[maxn][maxn], a[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i][i];
    memset(dp, 0x3f, sizeof(dp));
    for (int len = 1; len <= n; ++len) {
        for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
            dp[i][i] = 1;
            for (int k = i; k < j; ++k) {
                if (dp[i][k] == 1 && dp[k + 1][j] == 1 && a[i][k] == a[k + 1][j]) {
                    a[i][j] = a[i][k] + 1;
                    dp[i][j] = 1;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}