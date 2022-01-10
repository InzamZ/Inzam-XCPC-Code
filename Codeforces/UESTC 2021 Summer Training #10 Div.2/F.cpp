#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5e3 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

ll dp[maxn][maxn], cnt[maxn], a[maxn], ans = 0;

int main()
{
    int T = 1, n, k, q;
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d %d %d", &n, &k, &q);
        F(i, 1, n) {
            scanf("%lld", &a[i]);
        }
        F(i, 0, n) dp[i][0] = 1;
        F(i, 1, k) F(j, 1, n) {
            if (j == 1)
                dp[j][i] = dp[j + 1][i - 1];
            else if (j == n)
                dp[j][i] = dp[j - 1][i - 1];
            else
                dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
            dp[j][i] %= mod;
        }
        F(i, 1, n) F(j, 0, k) {
            cnt[i] += dp[i][k - j] * dp[i][j];
            cnt[i] %= mod;
        }
        F(j, 1, n) {
            ans += (a[j] * cnt[j]) % mod;
        }
        F(i, 1, q) {
            int idx;
            ll x;
            scanf("%d", &idx);
            scanf("%lld", &x);
            ans += (x - a[idx]) * cnt[idx];
            ans %= mod;
            a[idx] = x;
            printf("%lld\n", (ans + mod) % mod);
        }
    }
    return 0;
}