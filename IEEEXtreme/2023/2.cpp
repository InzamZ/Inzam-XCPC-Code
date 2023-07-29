//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 1010;
int T = 1, n, m, x, ans = 0;
int dp[maxb][maxb];
string e[maxb], v;

int solve() {
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
        e[i] = ' ' + e[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            if (e[i][j] == 'w')
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = 0;
            if (dp[i][j] > 0) {
                int w = dp[i][j], h = 1;
                ans = max(ans, w * h);
                int tmp = i;
                while (--tmp >= 0) {
                    w = min(dp[tmp][j], w);
                    if (ans >= w * i) break;
                    h++;
                    ans = max(ans, w * h);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}