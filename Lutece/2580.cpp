#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 5e3 + 10;
const ll inf = 1e17;
const ll mod = 1e9 + 7;
#define reg register
#define FOR(a,b,c) for(reg int a=b;a<=c;++a)
#define RFOR(a,b,c) for(reg int a=b;a>=c;--a)

ll dp[maxn], num[maxn];
ll ans = 0, n, m;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

int main()
{
    n = _read(); m = _read();
    FOR(i, 1, n) {
        num[i] = _read();
    }
    dp[0] = 1;
    FOR(i, 1, n) {
        RFOR(j, m, num[i]) {
            dp[j] += dp[j - num[i]];
            dp[j] %= mod;
        }
    }
    FOR(i, 1, n) {
        FOR(j, num[i], m) {
            dp[j] -= dp[j - num[i]];
            dp[j] = (dp[j] + mod) % mod;
        }
        FOR(j, 1, m) ans ^= dp[j];
        RFOR(j, m, num[i]) {
            dp[j] += dp[j - num[i]];
            dp[j] %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}