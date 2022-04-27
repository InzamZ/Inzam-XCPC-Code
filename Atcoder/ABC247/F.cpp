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
#define mod 998244353
int T = 1, n;
ll ans = 0;
int p[maxn], q[maxn], f[maxn], g[maxn];
bool vis[maxn];
vector<int>e[maxn];

int dfs(int x)
{
    vis[x] = 1;
    for (auto v : e[x]) {
        if (vis[v] == 0) {
            return dfs(v) + 1;
        }
    }
    return 1;
}

int main()
{
    FIO;
    while (T--) {
        ans = 1;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        for (int i = 0; i < n; ++i)
            cin >> q[i];
        for (int i = 0; i < n; ++i) {
            e[p[i]].push_back(q[i]);
            e[q[i]].push_back(p[i]);
        }
        f[1] = 2; f[2] = 3;
        g[1] = 1; g[2] = 3; g[3] = 4;
        for (int i = 3; i <= n; ++i)
            f[i] = (f[i - 1] + f[i - 2]) % mod;
        for (int i = 4; i <= n; ++i)
            g[i] = (f[i - 1] + f[i - 3]) % mod;
        ll cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                continue;
            cnt = dfs(i);
            ans *= g[cnt];
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}