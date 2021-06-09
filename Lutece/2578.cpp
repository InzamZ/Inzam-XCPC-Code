#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f
#define mod 1000000007
using ll = long long;

ll inv[105], p[maxn];

ll qpow(ll base, ll n)
{
    ll ans = 1, res = base;
    while (n) {
        if (n & 1ll) {
            ans *= res; ans %= mod;
        }
        res *= res; res %= mod;
        n >>= 1;
    }
    return ans % mod;
}
int main()
{
    int n;
    ll res = 1, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= 100; i++)
        inv[i] = qpow(i, mod - 2);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &p[i]);
    for (int i = 1; i <= n; ++i) {
        res = res * 100 % mod;
        res = res * inv[p[n + 1 - i]] % mod;
        ans = (ans + res) % mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}