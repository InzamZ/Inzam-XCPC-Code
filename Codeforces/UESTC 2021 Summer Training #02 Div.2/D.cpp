#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int randk = 100;

struct edge {
    int  v, next;
} e[maxn];

int vis[maxn];

queue<int>q;

int newbeg, cnt = 0;

int fir[maxn], cur = 0, ans = 0;
int T = 1, n, m, a, b;

void addedge(int u, int v)
{
    e[++cur].v = v;
    e[cur].next = fir[u];
    fir[u] = cur;
}

void bfs(int rt)
{
    for (int i = 1; i <= n; ++i)
        vis[i] = -1;
    q.push(rt);
    vis[rt] = 0;
    while (!q.empty()) {
        int res = q.front();
        q.pop();
        cnt++;
        for (int i = fir[res]; i; i = e[i].next) {
            if (vis[e[i].v] == -1) {
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
    // scanf("%d", &T);
    srand(time(NULL));
    rand();
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int t = 1; t <= m; ++t) {
            scanf("%d %d", &a, &b);
            addedge(a, b);
            addedge(b, a);
        }
        cnt = 0;
        for (int t = 1; t <= randk; ++t) {
            int res = (1ll * rand() * rand()) % n + 1;
            bfs(res);
            if (cnt < n) {
                printf("-1\n");
                return 0;
            }
            cnt = 0;
        }
        int k = 0;
        while (ans > (1 << k))
            ++k;
        printf("%d\n", k + 1);
    }
    return 0;
}