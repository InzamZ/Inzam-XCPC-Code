#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
const int maxb = 110;
const int mod = 998244353;
const ll Inf = 1e18;

int l[maxn][maxn], r[maxn];

int main()
{
    int T = 1, n, K;
    ll ans = 0;
    // scanf("%d",&T);
    while (T--) {
        ans = 1;
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= K; ++i)
            l[1][i] = 1;
        for (int i = 1; i <= K; ++i) {
            char c[10];
            int k;
            scanf("%s%d", c, &k);
            if (c[0] == 'L') {
                l[1][i] = 0;
                l[k][i] = 1;
                r[k] = i;
            }
            else {
                l[k][i] = -1;
                r[k] = i;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (!l[j][i])
                    l[j][i] = l[j - 1][i];
                // printf("%d ", l[j][i]);
            }
            // printf("\n");
        }
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            if (r[i] == 0) {
                for (int j = 1; j <= K; ++j) {
                    if (l[i][j] == 1)
                        cnt++;
                }
                ans *= cnt;
                ans %= mod;
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}