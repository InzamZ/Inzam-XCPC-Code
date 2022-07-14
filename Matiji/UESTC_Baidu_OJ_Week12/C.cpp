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
const int maxn = 1 << 16;
const int maxb = 20;
int T = 1, n;
double dp[maxn][maxb], a[maxn], b[maxn], ans;

int solve() {
    ans = 1e9;
    double x, y;
    cin >> n;
    f(i, 1, n) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < (1 << n ); i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for (int i = 1; i < (1 << n ); i++) {
        for (int j = 1; j <= n; ++j) {
            int from;
            if ((1 << (j - 1)) > i)
                break;
            if (i & (1 << (j - 1))) {
                from = i ^ (1 << (j - 1));
                for (int k = 1; k <= n; ++k) {
                    if (from & (1 << (k - 1)))
                        dp[i][j] = min(dp[i][j], dp[from][k] + sqrt((a[j] - a[k]) * (a[j] - a[k]) + (b[j] - b[k]) * (b[j] - b[k])));
                }
                if (from == 0)
                    dp[i][j] = min(dp[i][j], sqrt(a[j] * a[j] + b[j] * b[j]));
            }
        }
    }
    // for (int i = 0; i < (1 << n); ++i) {
    //     cout << i << ": ";
    //     for (int j = 0; j < n; ++j)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; ++i)
        ans = min(ans, dp[(1 << n) - 1][i]);
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << '\n';
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