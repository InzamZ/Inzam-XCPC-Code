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
const int maxn = 1e4 + 10;
const int maxb = 110;
int T = 1, n, s, c, ans = 0, a[maxn], b[maxn];
int dp[maxn], rst[maxn];

int solve() {
    ans = 0;
    memset(dp, 0, sizeof(dp));
    cin >> s >> c >> b[0];
    dp[0] = a[0] = 0;
    for (int i = 1; i <= s; ++i) {
        cin >> a[i] >> b[i];
        a[i] = a[i - 1] + a[i];
        dp[i] = LLONG_MAX;
        rst[i] = 0;
    }
    dp[0] = b[0] * c;
    for (int i = 1; i < s; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] - a[j] > c)
                break;
            if (dp[i] >= dp[j] + 500 + b[i] * (a[i] - a[j]))
                dp[i] =  dp[j] + 500 + b[i] * (a[i] - a[j]);
        }
    }
    for (int j = s - 1; j >= 0; --j) {
        if (a[s] - a[j] > c)
            break;
        dp[s] = min(dp[s], dp[j]);
    }
    cout << dp[s] << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}