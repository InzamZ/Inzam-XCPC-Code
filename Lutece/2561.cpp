#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 1e6 + 10;
const ll inf = 1e17;
const ll mod = 1e9 + 7;
#define reg register
#define FOR(a,b,c) for(reg int a=b;a<=c;++a)

ll dp[maxn], num[maxn];
ll ans = inf, n, mx = 0;

int lowbit(int x)
{
    return x & (-x);
}

ll getsum(int i)
{
    ll res = 0;
    while (i > 0) {
        res += dp[i];
        res %= mod;
        i -= lowbit(i);
    }
    return res % mod;
}

void update(int i, ll val)
{
    while (i <= mx) {
        dp[i] += val;
        i += lowbit(i);
    }
}

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
    n = _read();
    FOR(i, 1, n) {
        num[i] = _read();
        mx = max(mx, num[i]);
    }
    FOR(i, 1, n) {
        ll temp = getsum(num[i]) - getsum(num[i] - 1);
        temp = (getsum(num[i]) + 1) * num[i] - temp ;
        temp %= mod;
        update(num[i], temp);
    }
    printf("%lld\n", getsum(mx));
    return 0;
}