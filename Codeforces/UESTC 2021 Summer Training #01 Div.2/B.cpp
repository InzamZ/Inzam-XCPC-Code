#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 2e6 + 5;
const int inf = 1e9;
const ll MOD = 1e9 + 7;

ll p[maxn], cntt = 1;
ll cnt[maxn], ans = 1;

ll qpow(ll x, ll y)
{
    ll res = x, ans = 1;
    while (y) {
        res %= MOD;
        if (y & 1ll) {
            ans *= res;
            ans %= MOD;
        }
        y >>= 1;
        res *= res;
    }
    return ans;
}

int main()
{
    int T = 1, n;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d", &n);
        F(i, 1, n) {
            scanf("%lld", &p[i]);
            ++cnt[p[i]];
        }
        F(i, 2, maxn) {
            if (cnt[i]) {
                cntt *= (cnt[i] + 1);
                cntt %= (2 * MOD - 2);
            }
        }
        F(i, 2, maxn) {
            if (cnt[i])
                ans = (ans * qpow(i, (cnt[i] * cntt / 2) % (MOD - 1))) % MOD;
        }
        printf("%lld\n", ans % MOD);
    }
    return 0;
}