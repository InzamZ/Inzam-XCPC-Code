#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const int maxn = 1005;
const int inf = 1e9;
const ll Inf = 1e18;
// struct point {
//     double x, y;
// } p[maxn];
int imap[maxn][maxn];
int vis[maxn][maxn];
int T = 1, n, m, s, t;

queue<int>q;

void bfs(int rt)
{
    q.push(rt);
    vis[rt][rt] = 0;
    while (!q.empty()) {
        int res = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (imap[res][i] && vis[rt][i] > vis[rt][res] + 1) {
                q.push(i);
                vis[rt][i] = vis[rt][res] + 1;
                vis[i][rt] = vis[rt][i];
            }
        }
    }
}

int main()
{
    // scanf("%d", &T);
    while (T--) {
        memset(vis, 0x3f, sizeof(vis));
        ll ans = 0;
        scanf("%d %d %d %d", &n, &m, &s, &t);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            imap[u][v] = imap[v][u] = 1;
        }
        bfs(s);
        bfs(t);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                if (vis[s][t] <= vis[s][i] + 1 + vis[j][t] && vis[s][t] <= vis[s][j] + 1 + vis[i][t] && imap[i][j] == 0)
                    ans++;
            }
        printf("%lld\n", ans);
        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= n; ++j)
        //         printf("%d%c", vis[i][j], j == n ? '\n' : ' ');
    }
    return 0;
}