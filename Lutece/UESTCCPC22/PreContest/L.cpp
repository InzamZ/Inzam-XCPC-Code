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
vector<int>edg[maxn];
int ans[maxn],vis[maxn];
int T = 1, n;

int dfs(int rt,int f)
{
    vis[rt] = 1;
    for (auto i : edg[rt]) {
        if (i == f)
            continue;
        if (vis[i]) {
            continue;
        }
        dfs(i,rt);
    }
    ans[rt] = f;
    return 0;
}

int main()
{
    FIO;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(n,0);
    for (int i = 1; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}