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
const int maxn = 1000 + 10;
const int maxb = 110;
int T = 1, n, ans, dp[maxn], a[maxn], b[maxn], indeg[maxn], vis[maxn];
vector<int>e[maxn], v;
string s;

void dfs(int rt) {
    vis[rt] = 1;
    for (auto x : e[rt]) {
        dp[x] = max(dp[x], dp[rt] + 1);
        --indeg[x];
    }
    ans = max(ans, dp[rt]);
    for (auto x : e[rt]) {
        if (!vis[x] && !indeg[x])
            dfs(x);
    }
}


int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i] > a[j] && b[i] > b[j]) {
                e[i].push_back(j);
                ++indeg[j];
            }
        }
    for (int i = 1; i <= n ; ++i) {
        dp[i] = max(1ll,dp[i]);
        if (!vis[i] && indeg[i] == 0)
            dfs(i);
    }
    for (int i = 1; i <= n ; ++i)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
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