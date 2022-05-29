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
const int maxn = 1e3 + 10;
const int maxb = 5e3 + 10;
#define MOD 998244353
int T = 1, n, m, k, ans = 0;
int dp[maxn][maxb];

int solve() {
    ans = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1)
                dp[i][j] = j;
            else if (k == 0) {
                dp[i][j] = dp[i][j - 1];
                dp[i][j] = (dp[i][j] + dp[i - 1][m]) % MOD;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                if (j > k)
                    dp[i][j] += dp[i - 1][j - k];
                dp[i][j] %= MOD;
                if (j + k <= m)
                    dp[i][j] += (dp[i - 1][m] - dp[i - 1][j + k - 1] + MOD);
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    dp[n][m] = dp[n][m] + MOD;
    cout << dp[n][m] % MOD << '\n';
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}