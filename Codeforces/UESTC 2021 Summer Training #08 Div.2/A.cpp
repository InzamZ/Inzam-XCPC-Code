#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5010;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

vector<int>e[maxn];
vector<int>e2[maxn];

int indeg[maxn], col[maxn][maxn];
int a[maxn], b[maxn], ans[maxn];

queue<int>q;
bool toposort(int n)
{
    int num = 0;
    for (int i = 1; i <= n; ++i)
        if (!indeg[i])
            ++num, q.push(i);
    while (!q.empty()) {
        int res = q.front(); q.pop();
        for (int i = 0; i < e[res].size(); ++i)
            if (!(--indeg[e[res][i]]))
                ++num, q.push(e[res][i]);
    }
    return num == n;
}

void dfs(int rt, int colors)
{
    for (int i = 0; i < e2[rt].size(); ++i) {
        if (!col[e2[rt][i]][rt])
            col[e2[rt][i]][rt] = colors == 2 ? 1 : 2;
    }
    for (int i = 0; i < e[rt].size(); ++i) {
        if (indeg[e[rt][i]]) {
            if (!col[rt][e[rt][i]])
                col[rt][e[rt][i]] = colors;
        }
    }
    for (int i = 0; i < e[rt].size(); ++i) {
        if (indeg[e[rt][i]]) {
            --indeg[e[rt][i]];
            dfs(e[rt][i], colors == 2 ? 1 : 2);
        }
    }
}

int main()
{
    int T = 1, n, m;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &a[i], &b[i]);
            e[a[i]].push_back(b[i]);
            ++indeg[b[i]];
            e2[b[i]].push_back(a[i]);
        }
        ans[0] = toposort(n) ? 1 : 2;
        for (int i = 1; i <= m; ++i) {
            if (!indeg[a[i]] || !indeg[b[i]])
                ans[i] = 1;
            // else
            //     ans[i] = col[a[i]][b[i]];
        }
        for (int i = 1; i <= n; ++i) {
            if (indeg[i])
                dfs(i, 1);
        }
        for (int i = 1; i <= m; ++i) {
            if (!ans[i])
                ans[i] = col[a[i]][b[i]];
        }
        printf("%d\n", ans[0]);
        for (int i = 1; i <= m; ++i)
            printf("%d%c", ans[i], i == m ? '\n' : ' ');
    }
    return 0;
}