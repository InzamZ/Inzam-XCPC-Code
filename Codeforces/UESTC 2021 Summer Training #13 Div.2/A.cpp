#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

bool vis[maxn];
int T = 1;
int ans = 0, n, m, u, v;
vector<int>e[maxn];
vector<pii>f;

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

inline int dfs(int rt, int L, int R)
{
    vis[rt] = 1;
    int siz = e[rt].size();
    int cur = 0;
    if (rt != 1 && siz >= 2)
        R = max(R, e[rt][siz - 2] + 1);
    for (register int i = L; i < R; ++i) {
        for (; e[rt][cur] < i && e[rt][cur] != n + 1;)
            ++cur;
        if (vis[i])
            continue;
        else if (!vis[i] && e[rt][cur] == i) {
            i = dfs(i, i + 1, min(R, e[rt][cur + 1]));
            ++cur;
            R = max(i + 1, R);
        }
        else if (!vis[i] && e[rt][cur] > i) {
            ++ans;
            i = dfs(i, i + 1, min(R, e[rt][cur]));
            R = max(i + 1, R);
        }
    }
    return R - 1;
}

int main()
{
    T = _read();
    for (register int t = 1; t <= T; ++t) {
        ans = 0;
        n = _read(); m = _read();
        for (register int i = 1; i <= n; ++i) {
            vis[i] = 0;
            e[i].clear();
            f.clear();
        }
        for (register int i = 1; i <= m; ++i) {
            u = _read(); v = _read();
            if (u > v)
                swap(u, v);
            f.push_back(pii(u, v));
        }
        sort(f.begin(), f.end());
        int siz = unique(f.begin(), f.end()) - f.begin();
        for (register int i = 0; i < siz; ++i)
            e[f[i].first].push_back(f[i].second);
        for (register int i = 1; i <= n; ++i)
            e[i].push_back(n + 1);
        dfs(1, 2, n + 1);
        printf("%d\n", ans);
    }
    return 0;
}