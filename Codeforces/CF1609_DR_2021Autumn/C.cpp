//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 2e5 + 10;
const int maxb = 1e6;
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

bool vis[maxb];
int a[maxn], dplr[maxn], dprl[maxn];

int main()
{
    int T = 1, n, pos, e = 0;
    ll ans = 0;
    T = _read();
    for (int i = 2; i <= maxb; ++i) {
        if (vis[i])
            continue;
        for (int j = 2 * i; j <= maxb; j += i)
            vis[j] = 1;
    }
    while (T--) {
        n = _read();
        e = _read();
        ans = 0;
        for (int i = 1; i <= n; ++i)
            a[i] = _read();
        for (int i = 1; i <= n; ++i)
            dplr[i] = dprl[i] = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 1)
                dplr[i] = 1;
            if (a[i] == 1 && i - e > 0 && a[i - e] == 1)
                dplr[i] = dplr[i - e] + 1 ;
        }
        for (int i = n; i >= 1; --i) {
            if (a[i] == 1)
                dprl[i] = 1;
            if (a[i] == 1 && i + e <= n && a[i + e] == 1)
                dprl[i] = dprl[i + e] + 1 ;
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] || a[i] == 1)
                continue;
            if ((i - e > 0 && a[i - e] == 1) || (i + e <= n && a[i + e] == 1)) {
                int lcnt = 0, rcnt = 0;
                if (i - e > 0 )
                    lcnt = dplr[i - e];
                if (i + e <= n)
                    rcnt = dprl[i + e];
                ans += ((1ll + lcnt) * (1ll + rcnt) - 1);
            }
            // printf("%d\n", i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}