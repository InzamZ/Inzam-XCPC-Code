//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

ll ans = 0;
vector<int>e[maxn];
bool vis[maxn], vis2[maxn];

void dfs(int rt)
{
    vis[rt] = 1;
    if (rt != 1) {
        if (e[rt].size() == 2)
            ans++;
    }
    else {
        if (e[rt].size() == 1)
            ans++;
    }
    for (int i = 0; i < e[rt].size(); ++i) {
        if (!vis[e[rt][i]])
            dfs(e[rt][i]);
    }
}

int main()
{
    int T = 1, n, k, u, v;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            e[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        dfs(1);
        printf("%s\n", ans % 2 == 0 ? "Alice" : "Bob");
    }
    return 0;
}