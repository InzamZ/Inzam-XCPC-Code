#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

struct edge {
    int u, v, next;
} e[maxn];

int vis[maxn];

queue<int>q;

int newbeg, cnt = 0;

int fir[maxn], cur = 0, ans = 0;
void addedge(int u, int v)
{
    e[++cur].u = u;
    e[cur].v = v;
    e[cur].next = fir[u];
    fir[u] = cur;
}

void bfs(int rt)
{
    q.push(rt);
    while (!q.empty()) {
        int res = q.front();
        q.pop();
        cnt++;
        for (int i = fir[res]; i; i = e[i].next) {
            if (!vis[e[i].v]) {
                q.push(e[i].v);
                vis[e[i].v] = vis[res] + 1;
                if (vis[e[i].v] > ans)
                    ans = vis[e[i].v];
            }
        }
    }
}

int main()
{
    int T = 1, n, m, a, b;
    bool flag = true;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        for (int t = 1; t <= n; ++t) {
            scanf("%d %d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        cnt = 0;
        for (int t = 1; t <= m; ++t)
            vis[t] = 0;
        bfs(m);
        if (cnt < m) {
            printf("-1\n"); return 0;
        }
        else {
            queue<int>p;
            for (int t = 1; t <= m; ++t)
                if (vis[t] = ans)
                    p.push(t);
            while (!p.empty()) {
                for (int t = 1; t <= m; ++t)
                    vis[t] = 0;
                bfs(p.front());
                p.pop();
            }
            printf("%d\n", ans - 1);
        }
    }
    return 0;
}