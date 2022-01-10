#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

#define pii pair<int,int>

using ll = long long;

const int maxn = 1e5 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

vector< pii >edge(maxn * 3);
int to[maxn][2],ord[maxn];
bool vis[maxn], pic[maxn * 3];

int main()
{
    int T = 1, n;
    scanf("%d", &T);
    while (T--) {
        int a[3];
        scanf("%d", &n);
        for (int i = 0; i < n - 2; ++i) {
            scanf("%d%d%d", &a[0], &a[1], &a[2]);
            sort(a, a + 3);
            edge[i] = (pii(a[0], a[1]));
            edge[i + n - 2] = (pii(a[0], a[2]));
            edge[i + 2 * n - 4] = (pii(a[1], a[2]));
        }
        sort(edge.begin(), edge.begin() + (3 * n - 6));
        for (int i = 0; i <  (3 * n - 6); ++i) {
            // printf("%d %d", edge[i].first, edge[i].second);
            pic[i] = false;
        }
        for (int i = 0; i < (3 * n - 6); ++i) {
            if (i >= 1 && edge[i] == edge[i - 1])
                pic[i] = true;
            if (i < edge.size() - 1 && edge[i] == edge[i + 1])
                pic[i] = true;
            if (!pic[i]) {
                to[edge[i].first][to[edge[i].first][0] != 0] = edge[i].second;
                to[edge[i].second][to[edge[i].second][0] != 0] = edge[i].first;
            }
        }
        // for (int i = 0; i <  (3 * n - 6); ++i)
        //     printf("%d %d %d", edge[i].first, edge[i].second, pic[i]);
        int res; res = 1;
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", res, i == n ? '\n' : ' ');
            vis[res] = 1;
            ord[++(*ord)]=res;
            if (vis[to[res][0]])
                res = to[res][1];
            else
                res = to[res][0];
        }
        fill(edge.begin(), edge.begin() + (3 * n - 6), pii{0, 0});
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        for (int i = 1; i <= n; ++i)
            to[i][0] = to[i][1] = 0;
    }
    return 0;
}