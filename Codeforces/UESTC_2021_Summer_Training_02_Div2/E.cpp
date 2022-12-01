#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e6 + 5;
const int maxb = 55;
const int inf = 1e9;
const ll Inf = 1e18;

bool vis[maxb][maxn];


int main()
{
    int T = 1, n, m, l;
    bool flag = true;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        for (int t = 1; t <= m; ++t) {
            scanf("%d", &l);
            for (int i = 1; i <= l; ++i) {
                int num;
                scanf("%d", &num);
                vis[t][num] = 1;
            }
        }
        for (int i = 1; flag && i <= m; ++i) {
            for (int j = i + 1; flag && j <= m; ++j)
                for (int k = 1; flag && k <= n; ++k) {
                    if (vis[i][k] && vis[j][k])
                        break;
                    if (k == n)
                        flag = false;
                }
        }
        printf("%s\n", flag ? "possible" : "impossible");
    }
    return 0;
}