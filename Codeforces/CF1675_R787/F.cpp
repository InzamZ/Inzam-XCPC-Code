//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, k, x, y, xy;
int a[maxn];
bool vis[maxn], tar[maxn];
vector<int>e[maxn];

bool dfs(int u, int f, int dep)
{
    vis[u] = 1;
    if (u == y) {
        xy = dep;
        return 1;
    }
    bool ok = 0;
    if (tar[u])
        ok = 1;
    for (auto v : e[u]) {
        if (v == f)
            continue;
        if (!vis[v] && dfs(v, u, dep + 1)) {
            ok = 1;
            ans += 2;
        }
    }
    return ok;
}

bool dfs2(int u, int f)
{
    vis[u] = 1;
    bool ok = 0;
    if (tar[u])
        ok = 1;
    for (auto v : e[u]) {
        if (v == f)
            continue;
        if (!vis[v] && dfs2(v, u)) {
            ok = 1;
            ans += 2;
        }
    }
    return ok;
}
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> k >> x >> y;
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            vis[i] = 0;
            tar[i] = 0;
        }
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
            tar[a[i]] = true;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(x, x, 0);
        dfs2(y, y);
        // cout << ans << ' ' << xy  << '\n';
        cout << ans - xy  << '\n';
    }
    return 0;
}