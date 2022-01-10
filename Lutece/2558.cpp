#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e4 + 10;

int ans, order[maxn], indeg[maxn], cnt = 0, val[maxn];
bitset<maxn>vis[maxn];
queue<int>q;

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
struct data {
    int to, next;
} edge[maxn];
int head[maxn];
void add(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int main()
{
    int n, m, a, b;
    cnt = 0;
    n = _read(); m = _read();
    for (int i = 1; i <= m; ++i) {
        a = _read(); b = _read();
        add(b, a);
        ++indeg[a];
    }
    for (int i = 1; i <= n; ++i) {
        vis[i][i] = 1;
        if (!indeg[i])
            q.push(i);
    }
    cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order[++cnt] = u;
        for (int i = head[u]; i; i = edge[i].next) {
            --indeg[edge[i].to];
            if (!indeg[edge[i].to])
                q.push(edge[i].to);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int u = order[i];
        for (int j = head[u]; j; j = edge[j].next)
            vis[edge[j].to] |= vis[u];
    }
    for (int i = 1; i <= n; ++i) {
        ans = 0;
        for (int j = 1; j <= n; ++j) {
            if (vis[i][j])
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}