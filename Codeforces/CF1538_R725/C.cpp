#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int val[maxn];

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

void solve()
{
    int n, l, r;
    ll ans = 0;
    n = _read(); l = _read(); r = _read();
    for (int i = 0; i < n; ++i)
        val[i] = _read();
    sort(val, val + n);
    val[n] = 2e9;
    for (int i = 0; i < n; ++i) {
        if (val[i] > r)
            break;
        auto x = lower_bound(val + i + 1, val + 1 + n, l - val[i]) - val ;
        auto y = upper_bound(val + i + 1, val + 1 + n, r - val[i]) - val ;
        ans += (y - x);
    }
    printf("%lld\n", ans);
    return ;
}

int main()
{
    int T = 1;
    T = _read();
    while (T--)
        solve();
    return 0;
}