//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;


vector<int>e[maxn];
bool vis[maxn];
long double p[maxn];
long double ans = 0;

void dfs(int rt, long double depth)
{
    vis[rt] = 1;
    p[rt] = 1;
    ans += 1 / depth;
    for (int i = 0; i < e[rt].size(); ++i)
        if (vis[e[rt][i]] == 0)
            dfs(e[rt][i], depth + 1);
}

int main()
{
    int T = 1, n;
    // T=_read();
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 1);
        printf("%.20Lf\n", ans);
    }
    return 0;
}