//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
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
        sum = 1ll * sum * 10 + 1ll * (ch - 48), ch = nc();
    return sum;
}
#endif

ll T = 1, n, a, b, p, q, r, s;
ll check1l, check1r, check2l, check2r;

bool check1(ll k)
{
    return check1l <= k && k <= check1r;
}

bool check2(ll k)
{
    return check2l <= k && k <= check2r;
}

int main()
{
    // T=_read();
    while (T--) {
        n = _read(); a = _read(); b = _read();
        p = _read(); q = _read(); r = _read(); s = _read();
        check1l = max(1 - a, 1 - b), check1r = min(n - a, n - b);
        check2l = max(1 - a, b - n), check2r = min(n - a, b - 1);
        for (ll i = p; i <= q; ++i) {
            for (ll j = r; j <= s; ++j) {
                bool flag = 0;
                if (i - a == j - b && check1(j - b))
                    flag = 1;
                else if (i - a == b - j && check2(b - j))
                    flag = 1;
                printf("%c", flag ? '#' : '.');
                if (j == s)
                    putchar('\n');
            }
        }
    }
    return 0;
}