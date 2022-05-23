//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
int imx[105][105], dp[105][105];

int solve() {
    ans = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        imx[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j) {
            imx[i][j] = max(imx[i][j - 1], a[j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j)
            dp[i][j] = 1e9;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i && j <= m; ++j) {
            for (int k = 0; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + imx[k + 1][i]);
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}

signed main() {
    FIO;
    while (cin >> n >> m && (n || m)) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}