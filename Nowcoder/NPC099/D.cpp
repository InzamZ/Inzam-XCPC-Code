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
const int maxn = 1e6 + 10;
const int maxb = 110;
int T = 1, n, m, ansx, ans = 0, siz[maxn], dp[maxn];
vector<int>e[maxn], v;
string s;

int dfs1(int u, int fa) {
    int soncnt = 1, tmp;
    for (auto x : e[u]) {
        if (x == fa)
            continue;
        tmp = dfs1(x, u);
        dp[u] += u * soncnt * tmp;
        dp[u] += dp[x];
        soncnt += tmp;
    }
    siz[u] = soncnt;
    return soncnt;
}

int dfs2(int u, int fa) {
    if (u != 1)
        dp[u] =  (u - fa) * (n - siz[u]) * siz[u] + dp[fa];
    for (auto x : e[u]) {
        if (x == fa)
            continue;
        dfs2(x, u);
    }
    return 0;
}

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > ans) {
            ans = dp[i];
            ansx = i;
        }
    }
    cout << ansx << ' ' <<  ans * 2 + (n + 1) * n / 2 << '\n';
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