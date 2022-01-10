//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 50;
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
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

ll a[maxn], b[maxn];

int main()
{
    int T = 1, n, mxid = 0;
    ll ans = 0, mx;
    T = _read();
    while (T--) {
        ans = mx = mxid = 0;
        n = _read();
        for (int i = 1; i <= n; ++i)
            b[i] = _read();
        for (int mxid = 1; mxid <= n; ++mxid) {
            for (int i = 1; i <= n; ++i)
                a[i] = b[i];
            for (int i = 1; i <= n; ++i) {
                if (i == mxid)
                    continue;
                if (a[i] % 8 == 0) {
                    a[i] /= 8;
                    a[mxid] *= 8;
                }
                else if (a[i] % 4 == 0) {
                    a[i] /= 4;
                    a[mxid] *= 4;
                }
                else if (a[i] % 2 == 0) {
                    a[i] /= 2;
                    a[mxid] *= 2;
                }
            }
            ll res = 0;
            for (int i = 1; i <= n; ++i)
                res += a[i];
            ans = max(ans, res);
        }
        printf("%lld\n", ans);
    }
    return 0;
}