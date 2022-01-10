#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

vector<int>edge[maxn];
int vis[maxn];
queue<int>q;

int main()
{
    int T = 1, n, m, k;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        if (k == 1)
            printf("%d\n", n);
        else if (k != 2)
            printf("%d\n", 1);
        else {
            for (int i = 1; i <= n; ++i)
                vis[i] = -1;
            q.push(1);
            vis[1] == 0;
            while (!q.empty()) {
                int res = q.front(); q.pop();
                for (int i = 0; i < edge[res].size(); ++i) {
                    if (vis[edge[res][i]] == -1) {
                        vis[edge[res][i]] = (vis[res] + 1) % 2;
                        q.push(edge[res][i]);
                    }
                    else if (vis[edge[res][i]] != (vis[res] + 1) % 2) {
                        printf("1\n");
                        return 0;
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; ++i)
                if (vis[i] == 0)
                    ++ans;
            printf("%d\n", max(ans, n - ans));
        }
    }
    return 0;
}