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
int ans = 0, n, m, u, v, pos;
int lar[maxn];
priority_queue<int, vector<int>, greater<int> >e[maxn];

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
    R = max(R, lar[rt] + 1);
    int nxt = e[rt].top();
    for (register int i = L; i < R; ++i) {
        if (vis[i])
            continue;
        while (e[rt].top() < i)
            e[rt].pop();
        nxt = e[rt].top();
        if (!vis[i] && nxt == i) {
            e[rt].pop();
            nxt = e[rt].top();
            i = dfs(i, i + 1, min(R, nxt));
            R = max(R, i + 1);
        }
        else if (!vis[i] && nxt > i) {
            ++ans;
            i = dfs(i, i + 1, min(R, nxt));
            R = max(R, i + 1);
        }
    }
    return R - 1;
}

int main()
{
    T = _read();
    while (T--) {
        ans = 0;
        n = _read(); m = _read();
        for (register int i = 1; i <= n; ++i) {
            vis[i] = lar[i] = 0;
            while (!e[i].empty())
                e[i].pop();
            e[i].push(n + 1);
        }
        for (register int i = 1; i <= m; ++i) {
            u = _read(); v = _read();
            if (u > v)
                swap(u, v);
            if (u != v)
                e[u].push(v);
            lar[u] = max(lar[u], v);
        }
        dfs(1, 2, n + 1);
        printf("%d\n", ans);
    }
    return 0;
}