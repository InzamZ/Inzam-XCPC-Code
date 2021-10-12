#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 +  10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

int T = 1, n;
ll ans = 0;
int c[maxn], indeg[maxn], a[maxn];
bool vis[maxn];

void toposort()
{
    int num = 0;
    queue<int>q;
    for (int i = 1; i <= n; ++i)
        if (!indeg[i])
            q.push(i);
    while (!q.empty()) {
        int res = q.front(); q.pop();
        indeg[a[res]]--;
        if (indeg[a[res]] == 0)
            q.push(a[res]);
    }
}

ll dfs(int rt)
{
    ll res = c[rt];
    vis[rt] = 1;
    if (vis[a[rt]] == 0)
        res = min(res, dfs(a[rt]));
    return res;
}

int main()
{
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            ++indeg[a[i]];
        }
        toposort();
        for (int i = 1; i <= n; ++i) {
            if (indeg[i] && !vis[i])
                ans += dfs(i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}